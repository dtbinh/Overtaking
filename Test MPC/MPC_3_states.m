%% Simulation conditions
clc;clear;close all;

M=30; %simulation time

%% Parameters
ph = 150;            % Prediction horizon 

T = 1;                % Sample time
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
task.N=2;                                                                     %Number of samples (som Nikolce)                                                         %Som Nikolce
task.s=linspace(0,task.Ego.horizon,task.N)';                                    %[m] relative distance vector
task.ds=task.s(2)-task.s(1);

% Model using 3 states pos of x, vel of x and pos y. thus x vector x=[x,xdot,y]
% the control input is acceleration control in x and velocity control in y
% u=[]

A = [0 T 0;0 0 0;0 0 0];
B = [0 0;1 0;0 1];
C = [0 1 0; 0 0 1];
D = [0 0;0 0];


sys=c2d(ss(A,B,C,D),T);
A=sys.a;B=sys.b;C=sys.c;

x0=[0;70/3.6;2.5];                     % Initial state vector

% MPC data
n = size(A,1);        % Number of states
m = size(B,2);        % Number of inputs
c = size(C,1);        % Number of outputs

I = eye(n);


q=[0 0 0;0 10 0;0 0 100];       % State penalty matrix
R=[1 0;0 10];                   % Input penalty matrix

Q=q*C'*C;                       % State penalty to output states

% Equality matrix, Aeq
Aeq=[[[zeros(n,ph*n); kron(eye(ph-1,ph),-A)] + eye(n*ph)],kron(eye(ph),-B)];
% Equality matrix, AA (AA*x0)= Beq
AA=[A;zeros(n*(ph-1),n)];

QQ=kron(eye(ph),Q);
RR=kron(eye(ph),R);

QR=blkdiag(QQ,RR);
%%

H = QR;  % Heassian matrix
f = zeros(ph*(n+m),1);

% Limits the input values for entire horizon

beq=AA*(x0);

ymax=ones(1,ph)*8;
ymin=zeros(1,ph);
ymin(floor(ph/3):floor(ph/2))=3*ones(1,length(ymin(floor(ph/3):floor(ph/2))));

Ain=[kron(eye(ph),[0 0 -1]) zeros(length(ph),ph*m);...
     kron(eye(ph),[0 -1 0]) zeros(length(ph),ph*m);...
     kron(eye(ph-1),[0 1 0 0 -1 0])];
bin=[-ymin'; -ones(ph,1)*(70/3.6)];

z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[]);



