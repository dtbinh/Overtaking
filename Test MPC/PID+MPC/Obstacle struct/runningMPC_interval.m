clear
close
clc
%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
laneWidth=task.road.lanewidth;
safetyMargin=task.Ego.longsafetymargin;
ph = task.Ego.horizon; 
simTime = 20000; %Simulation time
simulate = 1; 

task.Ego.velocity=70/3.6;

%% Leading car
task.obstacle.velocity=60/3.6;
vD=task.Ego.velocity-task.obstacle.velocity;
task.Ego.overtakingLength=500/(task.Ego.velocity-task.obstacle.velocity);

%% Initiate system
ds=1;                                   % delta s = 1 meter
A = [0 0;0 0];
B = [1 0;0 1];

C = [1 0;0 1];
D = [0 0;0 0];

sys=ss(A,B,C,D);
sysd=c2d(ss(A,B,C,D),ds);
A=sysd.a;B=sysd.b;C=sysd.c;D=sysd.d;

x0=[task.Ego.velocity-task.obstacle.velocity laneWidth/2];

%% Set PID parameters
xref=[];
xk(:,1)=x0;
xPos=zeros(simTime,1);
errorSum=0;

%% Set MPC parameters
mpcInterval=30;
vvecTemp=ones(1,ph)*(task.Ego.velocity-task.obstacle.velocity);
[H,Aeq,beq]=mpcInit(A,B,C,ph,task,ds);

yvecTemp=ones(1,ph)*laneWidth/2;

%% Set Obstacle
p1=0.01;
p2=0.01;
task.obstacle=generateObstacle(p1,simTime,task);

%% Main loop
for i=1:simTime
    tic    
    if (mod(i,mpcInterval)==0 || i==1 ) 
        counter=0;
        xPosEst(1)=xPos(i);
        for k=1:ph
            xPosEst(k+1)=xPosEst(k)+vvecTemp(k);
        end
        xsp=generateXsp(xPosEst,task,ph);

    %% Calculate MPC trajectory
    [vvecTemp,yvecTemp,bound]=MPCtrajectory(A,B,C,task,ph,xsp,x0,H,Aeq,beq);

    end   
    counter=counter+1;
    xref=[vvecTemp(counter+1);yvecTemp(counter+1)];    
    [xk(:,i+1),errorSum] = PID(A,B,xref,xk(:,i),errorSum);
    xPos(i+1)=xPos(i)+xk(1,i+1);
    x0=[xk(1,i+1) xk(2,i+1)];
    
    if simulate==1 && mod(i,2)==0
        figure(1)
        clf
        %Plot road and obstacles
        plotroad(task,i*vD-2*ph,i*vD+4*ph)
   
        for u=1:length(task.obstacle)
            if abs(task.obstacle{u}.position-xPos(i))<4*ph
            plot(task.obstacle{u}.position,laneWidth/2,task.obstacle{u}.colour)
            end
        end
        hold on
        %plot car and trajectory
        plotcar(xPos(i+1),xk(2,i+1),'b*')
        plot(xPosEst(1:ph),xsp(2,:),'r--')
        plot(xPosEst(1:ph),yvecTemp,'b')
        plot(xPosEst(1:ph),bound(:,1),'k')
        plot(xPosEst(1:ph),bound(:,2),'k')
        % plot normal overtaking distance
        plot(xPos(i+1)+task.Ego.overtakingLength,2.5,'y+')
        pause(0.0000001)
    end
%     if mod(i,ceil(simTime/1000))==0 && simulate==0
%     waitbar(i/simTime)
%     end
    time(i)=toc;
end
figure(2)
plot(time)
sum(time)