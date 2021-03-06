function [vvec,yvec,bound]=MPCtrajectory(A,B,C,task,ph,xsp,x0,ds,init)

%% Parameters
safetymargin=task.Ego.longsafetymargin;
laneWidth = task.road.lanewidth;
n = size(A,2);                          % Number of states
m = size(B,2);                          % Number of inputs

%% State/input penalty

% State/input penalty
qx_ref = [1 0;0 10];qax=10;qvy=1000;qjx=100;qay=300;
r = 1;

H1 = blkdiag(kron(eye(ph),C'*qx_ref*C),kron(eye(ph),eye(m)*r));  % Extend costfunction with, same things as nikolce.

% Costfunction for x acceleration
H2 = [kron(eye(ph),[1 0;0 0]) + [zeros(2,ph*n);kron(eye(ph-1),[-1 0;0 0]) zeros((ph-1)*n,2)] + ...
    [zeros((ph-1)*n,2) kron(eye(ph-1),[-1 0;0 0]);zeros(2,ph*n)] + [zeros(2,ph*n);zeros((ph-2)*n,2)...
    kron(eye(ph-2),[1 0;0 0]) zeros((ph-2)*n,2);zeros(2,ph*n)]];
H2 =qax*[H2 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))]/ds^2;

% Costfunction for y velocity 
H3 = [kron(eye(ph),[0 0;0 1]) + [zeros(2,ph*n);kron(eye(ph-1),[0 0;0 -1]) zeros((ph-1)*n,2)] + ...
    [zeros((ph-1)*n,2) kron(eye(ph-1),[0 0;0 -1]);zeros(2,ph*n)] + [zeros(2,ph*n);zeros((ph-2)*n,2)...
    kron(eye(ph-2),[0 0;0 1]) zeros((ph-2)*n,2);zeros(2,ph*n)]];
H3 =qvy*[H3 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))]/ds^2;

% Costfunction for y acceleration
H4 = zeros(ph*n,ph*n);
repBlock=zeros(6,6);
repBlock(2,:)=[0 1 0 -2 0 1];
repBlock(4,:)=[0 -2 0 4 0 -2];
repBlock(6,:)=[0 1 0 -2 0 1];

for i=1:2:n*ph-5
    temp=zeros(ph*n,ph*n);
    temp(i:i+5,i:i+5)=repBlock;
    H4=H4+temp;
end

H4 =qay*[H4 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))]/ds^2;

% Costfunction for x jerk
H5 = zeros(ph*n,ph*n);
repBlock=zeros(6,6);
repBlockH5(1,:)=[1 0 -2 0 1 0];
repBlockH5(3,:)=[-2 0 4 0 -2 0];
repBlockH5(5,:)=[1 0 -2 0 1 0];

for i=1:2:n*ph-5
    temp=zeros(ph*n,ph*n);
    temp(i:i+5,i:i+5)=repBlock;
    H5=H5+temp;
end
H5 =qjx*[H5 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))]/ds^2;

H=2*(H1+H2+H3+H4+H5);
f1 = 2*(C*xsp)'*qx_ref;f=[];

for i=1:size(f1,1)
    f = [f;f1(i,1);f1(i,2)];
end
f = -[f;zeros(m*ph,1)];
%% Equality constraints
Aeq =[[zeros(2,n*ph);-eye((ph-1)*n) zeros((ph-1)*n,2)]+eye(ph*n) kron(eye(ph),-B)];
beq = zeros(size(Aeq,1),1);
beq(1:2)=x0;


%% Inequality constraints
ymin=ones(1,ph)*eps;ymin(100:120)=4;
ymax=ones(1,ph)*laneWidth*2;

nCon=4;
Ain=zeros(nCon*ph,(m+n)*ph);
bin=zeros(nCon*ph,1);

% Set constraint for obstacle
for i=1:ph

    if xsp(2,i)==7.5;
    bin(i)=-5;%xsp(2,i);%+task.Ego.width;
    Ain(i,i*n)=-1;
    end
end

% Set max turning (ph+1:3ph)
for i=2:ph
    bin(ph+i)=0.2;
    Ain(ph+i,ph*n+i*2-2)=1;
    Ain(ph+i,ph*n+i*2)=-1;
end
for i=2:ph
    bin(2*ph+i)=0.2;
    Ain(2*ph+i,ph*n+i*2-2)=-1;
    Ain(2*ph+i,ph*n+i*2)=1;
end

% Set top bound (3ph+1:4ph)
for i=1:ph
    bin(3*ph+i)=2*laneWidth-task.Ego.width;
    Ain(3*ph+i,i*n)=1;

end

options = optimset('Algorithm','interior-point-convex','Display','off');
z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[],options);
if isempty(z)
    disp('Problem Infeasible');
end

for i = 1:ph
    vvec(i)=z(i*2-1);
    yvec(i)=z(i*2);
end
bound=-bin(1:ph);

end