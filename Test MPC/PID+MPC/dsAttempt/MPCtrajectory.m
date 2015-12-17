function [vvec,yvec,bound]=MPCtrajectory(A,B,C,task,N,xsp,x0,H,Aeq,beq,lanes,ds)

%%
%   MPCtrajectory(A,B,C,task,N,xsp,x0,H,Aeq,beq,lanes,ds)
%   A,B,C is system
%   N = prediction horizon
%   xsp = Setpoint matrix, constraints are set from this 
%   x0 = Current position [x,y]
%   H = Hessian matrix
%   Aeq,beq equality constraints
%   lanes = Nr of lanes
%
%%

%% Parameters
safetymargin=task.Ego.longsafetymargin;
laneWidth = task.road.lanewidth;
n = size(A,2);                          % Number of states
m = size(B,2);                          % Number of inputs

%% State/input penalty

% State/input penalty

qx_ref = task.Ego.profile.qx_ref;
qax=task.Ego.profile.qax;
qvy=task.Ego.profile.qvy;
qjx=task.Ego.profile.qjx;
qay=task.Ego.profile.qay;

%% Cost function
f1 = 2*(C*xsp)'*qx_ref;f=[];

for i=1:size(f1,1)
    f = [f;f1(i,1);f1(i,2)];
end
f = -[f;zeros(m*N,1)];
%% Equality constraints
beq(1:2)=x0;


%% Inequality constraints
ymin=ones(1,N)*eps;ymin(100:120)=4;
ymax=ones(1,N)*laneWidth*2;

nCon=4; % Number of constraints
Ain=zeros(nCon*N,(m+n)*N);
bin=zeros(nCon*N,1);

% Set constraint for obstacle
for i=1:N
    bin(i)=-xsp(2,i)+laneWidth/2-task.Ego.width/2;%xsp(2,i);%+task.Ego.width;
    Ain(i,i*n)=-1;
    
end

% Set top bound

for i=1:N
    
    bin(N+i)=lanes*laneWidth-task.Ego.width/2;
    Ain(N+i,i*n)=1;
end
%Set max turning (N+1:3N)
for i=2:N
    bin(2*N+i)=0.1*task.Ego.velocity/ds;
    Ain(2*N+i,N*n+i*2-2)=1;
    Ain(2*N+i,N*n+i*2)=-1;
end
for i=2:N
    bin(3*N+i)=0.1*task.Ego.velocity/ds;
    Ain(3*N+i,N*n+i*2-2)=-1;
    Ain(3*N+i,N*n+i*2)=1;
end

options = optimset('Algorithm','interior-point-convex','Display','off');
z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[],options);
if isempty(z)
    disp('Problem Infeasible');
end

for i = 1:N
    vvec(i)=z(i*2-1);
    yvec(i)=z(i*2);
end
bound=[-bin(1:N),bin(N+1:2*N)];

end