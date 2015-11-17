%% Moving reference frame
clear;clc;clf;close;
ds=1;                                   % delta s = 1 meter
A = [0 0;0 0];
B = [1 0;0 1];

n = size(A,2);                          % Number of states
m = size(B,2);                          % Number of inputs

C = [0 0;0 1];
D = [0 0;0 0];

% H = [0 1];                              % Selection matrix
% Cz= H*C;

ph = 50;                                 % Prediction horizon

laneWidth = 2.5;                        % Lanewidth
ysp=[ones(1,ph)*(5);ones(1,ph)*2.5];    % Setpoint for xdot and y pos.
x0=[2;4];                     % Initial state value

% State/input penalty
q = 4;
r = 1;

H = 2*blkdiag(kron(eye(ph),C'*q*C),kron(eye(ph),eye(m)*r));  % Extend costfunction with, same things as nikolce.

f1 = 2*(C*ysp)'*q;f=[];
for i=1:size(f1,1)
    f = [f;f1(i,1);f1(i,2)];
end
f = -[f;zeros(m*ph,1)];

% Equality constraints
Aeq =[[zeros(2,n*ph);-eye((ph-1)*n) zeros((ph-1)*n,2)]+eye(ph*n) kron(eye(ph),-B)]; 
beq = zeros(size(Aeq,1),1);beq(1:2)=x0;

% Inequality constraints
ymin=ones(1,ph)*eps;
ymin(floor(ph/4*2):floor(ph/4*3))=4;
ymax=ones(1,ph)*laneWidth*2;

Ain=[-kron(eye(ph),[0 1]) zeros(ph,ph*m)];
bin=-ymin';

z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],x0);

