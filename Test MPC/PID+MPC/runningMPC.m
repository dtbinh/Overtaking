clear
close
clc

%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
laneWidth=task.road.lanewidth;
safetyMargin=task.Ego.longsafetymargin;
ph = 150; 
M=1000; %Simulation time

% Ego vehicle
vE=70/3.6;
pE=0;

% Leading car
vL=60/3.6;
obstacle=200;

%% Initiate system
ds=1;                                   % delta s = 1 meter
A = [0 0;0 0];
B = [1 0;0 1];

C = [1 0;0 1];
D = [0 0;0 0];

sys=ss(A,B,C,D);
sysd=c2d(ss(A,B,C,D),ds);
A=sysd.a;B=sysd.b;C=sysd.c;D=sysd.d;

x0=[vE laneWidth/2];

%% Set PID parameters
xref=[];
xk(:,1)=x0;
xPos=0;

%% Set MPC parameters
MPCinterval=1;
q=1;
r=1;
vvec=ones(1,ph)*vE;
yvec=ones(1,ph)*laneWidth/2;

for i=1:M
%% Set Obstacle
obstacle=1000;

xPosEst(1)=xPos;
for k=1:ph
xPosEst(k+1)=xPosEst(k)+vvec(k);
end

xsp=generateXsp(obstacle,xPosEst,task,ph,vE);

%% Calculate MPC trajectory
[vvecTemp,yvecTemp]=MPCtrajectory(A,B,C,D,task,ph,xsp,x0,q,r);
    if i>1
        vvec=[vvec(1:i) vvecTemp(1:end)];
        yvec=[yvec(1:i) yvecTemp(1:end)];
    end
    xref=[vvec(i);yvec(i)];  
    
    xk(:,i+1) = PID(A,B,xref,xk(:,i));
    xPos=xPos+xk(1,i+1);
    x0=[xk(1,i+1) xk(2,i+1)];
    
    plotroad(task,vE*ph)
    hold on
    plotcar(xPos,xk(2,i),'b*')
    plot(xPosEst(1:ph),xsp(2,:),'r')
    pause(0.01)
end