clear
clc
tic
%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  

% Leading car
vL=70/3.6;
pL=1000;
%% Moving reference frame
ds=1;                                   % delta s = 1 meter
A = [0 0;0 0];
B = [1 0;0 1];

n = size(A,2);                          % Number of states
m = size(B,2);                          % Number of inputs

C = [1 0;0 1];
D = [0 0;0 0];

% H = [0 1];                              % Selection matrix
% Cz= H*C;

ph = 150;                                 % Prediction horizon

laneWidth = task.road.lanewidth;                        % Lanewidth
xsp=[ones(1,ph)*2;ones(1,ph)*laneWidth/2];    % Setpoint for xdot and y pos.
x0=[2;laneWidth/2];                     % Initial state value


%% State/input penalty
q = 1;
r = 50;

H = 2*blkdiag(kron(eye(ph),C'*q*C),kron(eye(ph),eye(m)*r));

f1 = 2*q*(C*xsp)';
f=[];
for i=1:size(f1,1)
    f = [f;f1(i,1);f1(i,2)];
end
f = -[f;zeros(m*ph,1)];

%% Equality constraints
Aeq =[[zeros(2,n*ph);-eye((ph-1)*n) zeros((ph-1)*n,2)]+eye(ph*n) kron(eye(ph),-B)]; 
beq = zeros(size(Aeq,1),1);beq(1:2)=x0;

%% Inequality constraints
ymin=ones(1,ph)*eps;ymin(100:120)=4;
ymax=ones(1,ph)*laneWidth*2;

nCon=1;
Ain=zeros(nCon*ph,(m+n)*ph);
bin=zeros(nCon*ph,1);
point=0;
% Set obstacle (1:ph)
for i=round(10*ph/20):round(11*ph/20)
    bin(i)=-3*laneWidth/2;
    Ain(i,i*2)=-1;
end

% Set max turning (ph+1:2ph)
for i=2:ph
    bin(ph+i)=0.01;
    Ain(ph+i,ph*n+i*2-2)=1;
    Ain(ph+i,ph*n+i*2)=-1;
end
for i=2:ph
    bin(2*ph+i)=0.01;
    Ain(2*ph+i,ph*n+i*2-2)=-1;
    Ain(2*ph+i,ph*n+i*2)=1;
end

z=quadprog(H,f,Ain,bin,Aeq,beq);
toc


d(1)=0;
for i=2:ph
    d(i)=d(i-1)+z(i*2-1)+vL;
end

clf
plotroad(task,max(d))
hold on
plot(d,z(2:2:ph*2))

% figure(2)
% plot(z(1:n:ph*n))
