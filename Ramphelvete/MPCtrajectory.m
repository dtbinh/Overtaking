function [vvec,yvec,bound]=MPCtrajectory(A,B,C,task,ph,xsp,x0,H,Aeq,beq,lanes,ds)

%%
%   MPCtrajectory(A,B,C,task,ph,xsp,x0,H,Aeq,beq,lanes,ds)
%   A,B,C is system
%   ph = prediction horizon
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
f1 = 2*(C*xsp)'*qx_ref;
f=[];

for i=1:size(f1,1)
    f = [f;f1(i,1);f1(i,2)];
end
f = -[f;zeros(m*ph,1);zeros(ph,1)];
%% Equality constraints
beq(1:2)=x0;


%% Inequality constraints
% ymin=ones(1,ph)*eps;ymin(100:120)=4;
% ymax=ones(1,ph)*laneWidth*2;

nCon=7; % Number of constraints
Ain=zeros(nCon*ph,(m+n)*ph);
bin=zeros(nCon*ph,1);


% Ramp barrier
% v_a is the adjecent vehicles relative speed (v_adjecent - v_leading)
v_a = task.obstacle{2}.velocity-task.obstacle{1}.velocity;
% l_ar is safty margin to ajecent
l_ar = task.obstacle{2}.longsafetymarginF;
% Lanewidth
w_l = task.road.lanewidth;
% Lateral position of adjecent vehicle
y_a = task.obstacle{2}.yPosition;
%
x_a0= task.obstacle{2}.position;

Ain_t = (v_a)/l_ar;
Ain_y = 1/w_l;

bin_part = -[task.obstacle{2}.position:task.obstacle{2}.velocity:task.obstacle{2}.position+(ph-1)*task.obstacle{2}.velocity]'./l_ar-(y_a*ones(ph,1))./w_l+[ds:ds:ds*ph]';

Ain = [kron(eye(ph),[0 Ain_y]) zeros(ph,ph*m) kron(eye(ph),Ain_t)];

bin(1:ph) = bin_part-ones(ph,1);

% Set constraint for obstacle
for i=1:ph
    bin(ph+i)=-xsp(2,i)+laneWidth/2-task.Ego.width/2;%xsp(2,i);%+task.Ego.width;
    Ain(ph+i,i*n)=-1;
end

% Set top bound

for i=1:ph
    bin(2*ph+i)=lanes*laneWidth-task.Ego.width/2;
    Ain(2*ph+i,i*n)=1;
end
%Set max turning (ph+1:3ph)
for i=2:ph
    bin(3*ph+i)=0.01*task.Ego.velocity/ds;
    Ain(3*ph+i,ph*n+i*2-2)=1;
    Ain(3*ph+i,ph*n+i*2)=-1;
end
for i=2:ph
    bin(4*ph+i)=0.01*task.Ego.velocity/ds;
    Ain(4*ph+i,ph*n+i*2-2)=-1;
    Ain(4*ph+i,ph*n+i*2)=1;
end
%Set max velocity
for i=1:ph
    bin(5*ph+i)=3;
    Ain(5*ph+i,n*i-1)=1;
end
for i=1:ph
    bin(6*ph+i)=-2;
    Ain(6*ph+i,n*i-1)=-1;
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
bound=[bin(1:ph),-bin(ph+1:2*ph)];

end