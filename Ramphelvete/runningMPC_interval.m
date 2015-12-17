clear
close
clc
%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;
laneWidth=task.road.lanewidth;
safetyMargin=task.Ego.longsafetymargin;
task.Ego.horizon=300;
ph = task.Ego.horizon;
% Simulation
simTime = 2000; %Simulation time
askInput=0;
simulate = 1;
noOfLanes = 2; %2 or 3
% Set profile, 'help setProfile' for more details
profile='N';

%% Print information
if askInput
simTime=input('What simulation time is desired(s)? \n');
simTime=round(simTime/0.022);
clc
noOfLanes=input('How many lanes are desired?(2-3) \n');
clc
simulate=input('Do you wish to see real time simulations(1/0)? \n');
clc
profile=input('Which driving behaviour is derired? (A/B/C/N) \n','s');
clc
else
fprintf('Simulation time is set to %i s and simulations is set to %d. \nThe number of lanes are %d. \n\nThe black lines are hard constraints and the dotted red line is a desired setpoint.\n\n',simTime*0.022,simulate,noOfLanes)
end
%% Leading car
task.obstacle.velocity=60/3.6;

task.Ego.overtakingLength=500/(task.Ego.velocity-task.obstacle.velocity);
%% Ego vehicle
task.Ego.profile=setProfile(profile);
task.Ego.velocity=70/3.6;
vD=task.Ego.velocity-task.obstacle.velocity;
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
p1=0.008;
p2=0.01;
task.obstacle=generateObstacle(p1,simTime,task,noOfLanes,1);

%% Main loop
H=sparse(H);
Aeq=sparse(Aeq);
beq=sparse(beq);

for i=1:simTime
    tic
    task=updateAdjacent(task);
    if (mod(i,mpcInterval)==0 || i==1 )
        counter=0;
        xPosEst(1)=xPos(i);
        for k=1:ph
            xPosEst(k+1)=xPosEst(k)+vvecTemp(k);
        end
        xsp=generateXsp(xPosEst,task,ph);
        
        %% Calculate MPC trajectory
        [vvecTemp,yvecTemp,bound]=MPCtrajectory(A,B,C,task,ph,xsp,x0,H,Aeq,beq,noOfLanes,ds);
        
    end
    counter=counter+1;
    xref=[vvecTemp(counter+1);yvecTemp(counter+1)];
    [xk(:,i+1),errorSum] = PID(A,B,xref,xk(:,i),errorSum);
    xPos(i+1)=xPos(i)+xk(1,i+1)*ds;
    x0=[xk(1,i+1) xk(2,i+1)];
    
    if simulate==1 && mod(i,2)==0
        figure(1)
        clf
        %Plot road,car and obstacles
        plotroad(task,xPos(i+1)-0.1*ph*vD,xPos(i+1)+1.1*ph*vD,noOfLanes)
        plotcar(xPos(i+1),xk(2,i+1))
        for u=1:length(task.obstacle)
            if abs(task.obstacle{u}.position-xPos(i))<2*ph*vD
                pl1=plot(task.obstacle{u}.position,task.obstacle{u}.yPosition,task.obstacle{u}.colour);
            end
        end
        hold on
        %plot trajectory
        pl2=plot(xPosEst(1:ph),xsp(2,:),'r--');
        pl3=plot(xPosEst(1:ph),yvecTemp,'b');
        pl4=plot(xPosEst(1:ph),bound(:,1),'k');
        pl5=plot(xPosEst(1:ph),bound(:,2),'k');
        % plot normal overtaking distance
        plot(xPos(i+1)+task.Ego.overtakingLength,2.5,'y+');
        pause(0.0001/ph)
    end
    %     if mod(i,ceil(simTime/1000))==0 && simulate==0
    %     waitbar(i/simTime)
    %     end
    time(i)=toc;
end
legend([pl1,pl2,pl3,pl4],{'Leading vehicles','Setpoint trajectory','MPC trajectory','Boundary',})
xlabel('Relative distance [m]')
ylabel('Y position [m]')
figure(2)
plot(time)

sum(time)