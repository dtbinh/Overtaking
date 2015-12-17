clear
close
clc
%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;
laneWidth=task.road.lanewidth;
safetyMargin=task.Ego.longsafetymargin;
task.Ego.horizon=1000;
ph = task.Ego.horizon;
% Simulation
simTime = 200; %Simulation time
askInput=0;
simulate = 1;
noOfLanes = 3; %2 or 3
% Set profile, 'help setProfile' for more details
profile='C';

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
vvecTemp=ones(1,ph)*(task.Ego.velocity-task.obstacle.velocity);
[H,Aeq,beq]=mpcInit(A,B,C,ph,task,ds);
yvecTemp=ones(1,ph)*laneWidth/2;



%% Set Obstacle
p1=0.01;
p2=0.01;
task.obstacle=generateObstacle(0,simTime,task,noOfLanes);

%% Main loop



        xPosEst(1)=xPos(1);
        for k=1:ph
            xPosEst(k+1)=xPosEst(k)+vvecTemp(k);
        end
        xsp=generateXsp(xPosEst,task,ph);
        H=sparse(H);
        Aeq=sparse(Aeq);
        beq=sparse(beq);
        for i=1:100
        tic
        %% Calculate MPC trajectory
        [vvecTemp,yvecTemp,bound]=MPCtrajectory(A,B,C,task,ph,xsp,x0,H,Aeq,beq,noOfLanes,ds);

        time(i)=toc;
        end
        mean(time)*1000
        
