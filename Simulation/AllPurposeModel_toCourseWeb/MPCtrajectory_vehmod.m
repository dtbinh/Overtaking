function y = MPCtrajectory_vehmod(xin)

LenaPh = 150;



xsp(1, 1:150) = xin(1:2:299);    % referens: xhast, ypos 
xsp(2, 1:150) = xin(2:2:300);

x0 = xin(301:302); % nuvarande xhast, ypos

% Parameters
% safetymargin = 5;
laneWidth = 5;
n = 2;                          % Number of states
m = 2;                          % Number of inputs

C = eye(2);
B = C;
A = C;
% State/input penalty

% State/input penalty
qx_ref = [0 0;0 10];qax=10;qvy=100;qjx=100;qay=3000;
r = 1;

H1 = blkdiag(kron(eye(LenaPh),C'*qx_ref*C),kron(eye(LenaPh),eye(m)*r));  % Extend costfunction with, same things as nikolce.

% Costfunction for x acceleration
H2 = [kron(eye(LenaPh),[1 0;0 0]) + [zeros(2,LenaPh*n);kron(eye(LenaPh-1),[-1 0;0 0]) zeros((LenaPh-1)*n,2)] + ...
    [zeros((LenaPh-1)*n,2) kron(eye(LenaPh-1),[-1 0;0 0]);zeros(2,LenaPh*n)] + [zeros(2,LenaPh*n);zeros((LenaPh-2)*n,2)...
    kron(eye(LenaPh-2),[1 0;0 0]) zeros((LenaPh-2)*n,2);zeros(2,LenaPh*n)]];
H2 =qax*[H2 zeros(LenaPh*n,LenaPh*m);zeros(LenaPh*m,LenaPh*(n+m))];

% Costfunction for y velocity 
H3 = [kron(eye(LenaPh),[0 0;0 1]) + [zeros(2,LenaPh*n);kron(eye(LenaPh-1),[0 0;0 -1]) zeros((LenaPh-1)*n,2)] + ...
    [zeros((LenaPh-1)*n,2) kron(eye(LenaPh-1),[0 0;0 -1]);zeros(2,LenaPh*n)] + [zeros(2,LenaPh*n);zeros((LenaPh-2)*n,2)...
    kron(eye(LenaPh-2),[0 0;0 1]) zeros((LenaPh-2)*n,2);zeros(2,LenaPh*n)]];
H3 =qvy*[H3 zeros(LenaPh*n,LenaPh*m);zeros(LenaPh*m,LenaPh*(n+m))];

% Costfunction for y acceleration
H4 = zeros(LenaPh*n,LenaPh*n);
repBlock=zeros(6,6);
repBlock(2,:)=[0 1 0 -2 0 1];
repBlock(4,:)=[0 -2 0 4 0 -2];
repBlock(6,:)=[0 1 0 -2 0 1];

for i=1:2:n*LenaPh-5
    temp=zeros(LenaPh*n,LenaPh*n);
    temp(i:i+5,i:i+5)=repBlock;
    H4=H4+temp;
end

H4 =qay*[H4 zeros(LenaPh*n,LenaPh*m);zeros(LenaPh*m,LenaPh*(n+m))];

% Costfunction for x jerk
H5 = zeros(LenaPh*n,LenaPh*n);
repBlock=zeros(6,6);
repBlockH5(1,:)=[1 0 -2 0 1 0];
repBlockH5(3,:)=[-2 0 4 0 -2 0];
repBlockH5(5,:)=[1 0 -2 0 1 0];

for i=1:2:n*LenaPh-5
    temp=zeros(LenaPh*n,LenaPh*n);
    temp(i:i+5,i:i+5)=repBlock;
    H5=H5+temp;
end
H5 =qjx*[H5 zeros(LenaPh*n,LenaPh*m);zeros(LenaPh*m,LenaPh*(n+m))];

H=2*(H1+H2+H3+H4+H5);
f1 = 2*(C*xsp)'*qx_ref;f=[];

for i=1:size(f1,1)
    f = [f;f1(i,1);f1(i,2)];
end
f = -[f;zeros(m*LenaPh,1)];
% Equality constraints
Aeq =[[zeros(2,n*LenaPh);-eye((LenaPh-1)*n) zeros((LenaPh-1)*n,2)]+eye(LenaPh*n) kron(eye(LenaPh),-B)];
beq = zeros(size(Aeq,1),1);
beq(1:2)=x0;


% Inequality constraints
ymin=ones(1,LenaPh)*eps;ymin(100:120)=4;
% ymax=ones(1,ph)*laneWidth*2;
ymax=ones(1,LenaPh)*20;

nCon=4;
Ain=zeros(nCon*LenaPh,(m+n)*LenaPh);
bin=zeros(nCon*LenaPh,1);

% Set constraint for obstacle
for i=1:LenaPh
    if xsp(2,i)~2.5;
    bin(i)=-xsp(2,i);%+task.Ego.width;
    Ain(i,i*n)=-1;
    end
end

% Set max turning (ph+1:3ph)
for i=2:LenaPh
    bin(LenaPh+i)=0.02;
    Ain(LenaPh+i,LenaPh*n+i*2-2)=1;
    Ain(LenaPh+i,LenaPh*n+i*2)=-1;
end
for i=2:LenaPh
    bin(2*LenaPh+i)=0.02;
    Ain(2*LenaPh+i,LenaPh*n+i*2-2)=-1;
    Ain(2*LenaPh+i,LenaPh*n+i*2)=1;
end

% Set top bound (3ph+1:4ph)
for i=1:LenaPh
    bin(3*LenaPh+i)=2*laneWidth;
    Ain(3*LenaPh+i,i*n)=1;

end

options = optimset('Algorithm','interior-point-convex','Display','off');
% options = optimset('Algorithm','interior-point-convex');
z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[],options);
if isempty(z)
    disp('Problem Infeasible');
end

% for i = 1:ph
%     v=z(1);
%     y=z(2);
% end
y = z(2:2:300);
% y = z(2);


end