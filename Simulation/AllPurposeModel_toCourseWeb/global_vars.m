clc, clear

global task x0 A B C D H Aeq beq qx_ref ph;

load init_params

task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
laneWidth=task.road.lanewidth;
safetyMargin=task.Ego.longsafetymargin;
% ph = task.Ego.horizon;
ph = 150;


task.Ego.velocity=70/3.6;

% Leading car
task.obstacle.velocity=60/3.6;
vD=task.Ego.velocity-task.obstacle.velocity;
task.Ego.overtakingLength=500/(task.Ego.velocity-task.obstacle.velocity);

x0=[task.Ego.velocity-task.obstacle.velocity laneWidth/2];

% Initiate system
ds=1;                                   % delta s = 1 meter
A = [0 0;0 0];
B = [1 0;0 1];

C = [1 0;0 1];
D = [0 0;0 0];

sys=ss(A,B,C,D);
sysd=c2d(ss(A,B,C,D),ds);
A=sysd.a;B=sysd.b;C=sysd.c;D=sysd.d;

qx_ref = [1 0; 0 10];

tp = 0.3;
[H,Aeq,beq]=mpcInit(A,B,C,ph,task,ds);