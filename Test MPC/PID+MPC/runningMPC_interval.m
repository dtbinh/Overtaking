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
M=2000; %Simulation time
simulate = 1; %simulate in real time
% Ego vehicle
vE=70/3.6;
pE=0;
my=0.25;
g=9.81;
minDist=10;
overtakingLimit=1;

task.Ego.longsafetymargin=task.Ego.length*1.5+vE^2/(2*my*g);

% Leading car
vL=60/3.6;
vD=vE-vL;
%% Initiate system
ds=1;                                   % delta s = 1 meter
A = [0 0;0 0];
B = [1 0;0 1];

C = [1 0;0 1];
D = [0 0;0 0];

sys=ss(A,B,C,D);
sysd=c2d(ss(A,B,C,D),ds);
A=sysd.a;B=sysd.b;C=sysd.c;D=sysd.d;

x0=[vE-vL laneWidth/2];

%% Set PID parameters
xref=[];
xk(:,1)=x0;
xPos(1)=0;
errorSum=0;


%% Set MPC parameters
mpcInterval=30;
q=1;
r=100;
vvecTemp=ones(1,ph)*(vE-vL);

yvecTemp=ones(1,ph)*laneWidth/2;

%% Set Obstacle
p=0.01;
obstacle=generateObstacle(p,M,(vE-vL),task);
for i=1:M


if (mod(i,mpcInterval)==0 || i==1 )
        if (vE-vL)<overtakingLimit && obstacle(1)-xPos(i)<300
            break;
        end
    counter=0;
xPosEst(1)=xPos(i);
for k=1:ph
xPosEst(k+1)=xPosEst(k)+vvecTemp(k);
end
xsp=generateXsp(obstacle,xPosEst,task,ph,vD);

%% Calculate MPC trajectory

[vvecTemp,yvecTemp,bound]=MPCtrajectory(A,B,C,task,ph,xsp,x0);


end   
counter=counter+1;
    xref=[vvecTemp(counter+1);yvecTemp(counter+1)];  
    
%     errorD=error-(xref-xk(:,i));
%     error=(xref-xk(:,i));
%     errorSum=errorSum+error;
%     Cpid=pid(Kp,Ki,Kd);
%     uk=error*Cpid.Kp+errorSum*Cpid.Ki+errorD*Cpid.Kd;      
%     xk(:,i+1)=A*xk(:,i)+B*uk;
    
    [xk(:,i+1) errorSum] = PID(A,B,xref,xk(:,i),errorSum);
    xPos(i+1)=xPos(i)+xk(1,i+1);
    x0=[xk(1,i+1) xk(2,i+1)];
    
    if simulate==1
        figure(1)
        clf
    %Plot road and obstacles
    plotroad(task,i*vD-2*ph,i*vD+2*ph)
    plot(obstacle,laneWidth/2,'r*')
    hold on
    %plot car and trajectory
    plotcar(xPos(i+1),xk(2,i+1),'b*')
    %plot(xPos,yvec(1:i+1),'b')
    plot(xPosEst(2:end),xsp(2,:),'r--')
    plot(xPosEst(1:ph),yvecTemp,'b')
    plot(xPosEst(1:ph),bound,'k')
    % plot normal overtaking distance
    plot(xPos(i+1)+750/(vE-vL),2.5,'y+')
    pause(0.0000001)
    end
    if mod(i,ceil(M/1000))==0 && simulate==0
    waitbar(i/M)
    end

end