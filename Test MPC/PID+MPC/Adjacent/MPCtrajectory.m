function [vvec,yvec,bound,infeasible]=MPCtrajectory(A,B,C,task,ph,xsp,x0,H,Aeq,beq,adj)

%% Parameters
safetymargin=task.Ego.longsafetymargin;
laneWidth = task.road.lanewidth;
n = size(A,2);                          % Number of states
m = size(B,2);                          % Number of inputs

infeasible=0;
vvec=0;
yvec=0;

%% State/input penalty

% State/input penalty
qx_ref = [1 0;0 10];qax=20;qvy=400;qjx=100;qay=200;

f1 = 2*(C*xsp)'*qx_ref;f=[];
for i=1:size(f1,1)
    f = [f;f1(i,1);f1(i,2)];
end
f = -[f;zeros(m*ph,1)];

%% Equality constraints
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
    bin(i)=-5-task.Ego.width/2;%xsp(2,i);%+task.Ego.width;
    Ain(i,i*n)=-1;
    else
    bin(i)=-task.Ego.width/2; 
    Ain(i,i*n)=-1;
    end
end

% Set constraint for adjacent vehicle

for i=1:ph

    bin(ph+i)=adj(i);
    Ain(ph+i,i*n)=1;
end
%Set max turning (ph+1:3ph)
for i=2:ph
    bin(2*ph+i)=0.2;
    Ain(2*ph+i,ph*n+i*2-2)=1;
    Ain(2*ph+i,ph*n+i*2)=-1;
end
for i=2:ph
    bin(3*ph+i)=0.2;
    Ain(3*ph+i,ph*n+i*2-2)=-1;
    Ain(3*ph+i,ph*n+i*2)=1;
end

% 'interior-point-convex'

options = optimset('Algorithm','interior-point-convex','Display','off');
z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[],options);
if isempty(z)
    infeasible=1;
else

for i = 1:ph
    vvec(i)=z(i*2-1);
    yvec(i)=z(i*2);
end
end
bound=[-bin(1:ph),bin(ph+1:2*ph)];

end