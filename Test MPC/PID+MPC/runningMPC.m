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
M=500; %Simulation time

% Ego vehicle
vE=70/3.6;
pE=0;
my=0.25;
g=9.81;
minDist=10;

task.Ego.longsafetymargin=task.Ego.length*1.5+vE^2/(2*my*g);

% Leading car
vL=60/3.6;
obstacle=2000;

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
errorSum=0;


%% Set MPC parameters
MPCinterval=1;
q=1;
r=100;
vvec=ones(1,ph)*vE;
yvec=ones(1,ph)*laneWidth/2;
%% Set Obstacle
p=0.001;
obstacle=generateObstacle(p,M,(vE-vL),task);
for i=1:M



xPosEst(1)=xPos;
for k=1:ph
xPosEst(k+1)=xPosEst(k)+vvec(k);
end

xsp=generateXsp(obstacle,xPosEst,task,ph,vE);

%% Calculate MPC trajectory

[vvecTemp,yvecTemp]=MPCtrajectory(A,B,C,task,ph,xsp,x0);
    if i>1
        vvec=[vvec(1:i) vvecTemp(1:end)];
        yvec=[yvec(1:i) yvecTemp(1:end)];
    end
    
    xref=[vvec(i);yvec(i)];  
    
%     errorD=error-(xref-xk(:,i));
%     error=(xref-xk(:,i));
%     errorSum=errorSum+error;
%     Cpid=pid(Kp,Ki,Kd);
%     uk=error*Cpid.Kp+errorSum*Cpid.Ki+errorD*Cpid.Kd;      
%     xk(:,i+1)=A*xk(:,i)+B*uk;
    
    [xk(:,i+1) errorSum] = PID(A,B,xref,xk(:,i),errorSum);
    xPos=xPos+xk(1,i+1);
    x0=[xk(1,i+1) xk(2,i+1)];
    
    
    %Plot road and obstacles
    plotroad(task,0,(vE-vL)*M)
    plot(obstacle,laneWidth/2,'r*')
    hold on
    %plot car and trajectory
    plotcar(xPos,xk(2,i),'b*')
    plot(xPosEst(1:ph),xsp(2,:),'r')
    plot(xPosEst(1:ph),yvec(i:i+ph-1),'b')
    %plot recommended overtaking distance
    plot(xPos+750,2.5,'y+')
    pause(0.0000001)
end