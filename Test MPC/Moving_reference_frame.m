%% Moving reference frame
clear;clc;clf;close;
ds=1;                                   % delta s = 1 meter
A = [0 0;0 0];
B = [1 0;0 1];

n = size(A,2);                          % Number of states
m = size(B,2);                          % Number of inputs
t = 1;                                  % Number of time variables

C = [1 0;0 1];
D = [0 0;0 0];

% H = [0 1];                              % Selection matrix
% Cz= H*C;

ph =100;                                 % Prediction horizon

laneWidth = 2.5;                          % Lanewidth
ysp=[ones(1,ph)*(2);ones(1,ph)*2.5];      % Setpoint for xdot and y pos.
ysp(2,floor(ph/4*2):floor(ph/4*3))=7.5;   % Obstacle refererence
x0=[2;2.5];                               % Initial state value

%
vtilde_r = 2;                             % relative refenrence velocity

% State/input penalty
qx_ref = [0 0;0 20];qax=10;qvy=200;qjx=100;qay=800;qt=1;
r = 1;

H1 = blkdiag(kron(eye(ph),C'*qx_ref*C),kron(eye(ph),eye(m)*r));  % Extend costfunction with, same things as nikolce.

% Costfunction for x acceleration
H2 = [kron(eye(ph),[1 0;0 0]) + [zeros(2,ph*n);kron(eye(ph-1),[-1 0;0 0]) zeros((ph-1)*n,2)] + ...
    [zeros((ph-1)*n,2) kron(eye(ph-1),[-1 0;0 0]);zeros(2,ph*n)] + [zeros(2,ph*n);zeros((ph-2)*n,2)...
    kron(eye(ph-2),[1 0;0 0]) zeros((ph-2)*n,2);zeros(2,ph*n)]];
H2 =qax*[H2 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))];

% Costfunction for y velocity 
H3 = [kron(eye(ph),[0 0;0 1]) + [zeros(2,ph*n);kron(eye(ph-1),[0 0;0 -1]) zeros((ph-1)*n,2)] + ...
    [zeros((ph-1)*n,2) kron(eye(ph-1),[0 0;0 -1]);zeros(2,ph*n)] + [zeros(2,ph*n);zeros((ph-2)*n,2)...
    kron(eye(ph-2),[0 0;0 1]) zeros((ph-2)*n,2);zeros(2,ph*n)]];
H3 =qvy*[H3 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))];

% Costfunction for y acceleration
H4 = zeros(ph*n,ph*n);
repBlock=zeros(6,6);
repBlock(2,:)=[0 1 0 -2 0 1];
repBlock(4,:)=[0 -2 0 4 0 -2];
repBlock(6,:)=[0 1 0 -2 0 1];

for i=1:2:n*ph-5
    temp=zeros(ph*n,ph*n);
    temp(i:i+5,i:i+5)=repBlock;
    H4=H4+temp;
end

H4 =qay*[H4 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))];

% Costfunction for x jerk
H5 = zeros(ph*n,ph*n);
repBlock=zeros(6,6);
repBlockH5(1,:)=[1 0 -2 0 1 0];
repBlockH5(3,:)=[-2 0 4 0 -2 0];
repBlockH5(5,:)=[1 0 -2 0 1 0];

for i=1:2:n*ph-5
    temp=zeros(ph*n,ph*n);
    temp(i:i+5,i:i+5)=repBlock;
    H5=H5+temp;
end
H5 = qjx*[H5 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))];

H=2*(H1+H2+H3+H4+H5);
H = blkdiag(H,eye(t*ph)*0);
H(end:end)=qt;
f1 = 2*(C*ysp)'*qx_ref;f=[];

for i=1:size(f1,1)
    f = [f;f1(i,1);f1(i,2)];
end
f = -[f;zeros(m*ph,1);zeros(t*ph,1)];

% Equality constraints
Aeq1 =[[zeros(2,n*ph);-eye((ph-1)*n) zeros((ph-1)*n,2)]+eye(ph*n) kron(eye(ph),-B) zeros(n*ph,t*ph)];
Aeq2 = [kron(eye(ph),[-1/(vtilde_r^2) 0]) zeros(t*ph,m*ph) ...
    [zeros(1,ph*t);eye(t*ph-1) zeros(t*ph-1,1)]+ -1*eye(t*ph)];
% Aeq2 =[1 zeros(1,(m+n+t)*ph-1); 0 0 1 zeros(1,(m+n+t)*ph-3); zeros(1,(m+n)*ph) 1 zeros(1,ph-1)];
Aeq =[Aeq1;Aeq2];

beq = [zeros(ph*n,1); ones(t*ph,1)*(-2/vtilde_r)];beq(1:2)=x0;%beq(end-2:end)=[x0(1) x0(1) 0];

% Inequality constraints
ymin=ones(1,ph)*eps;
ymin(floor(ph/4*2):floor(ph/4*3))=5;
ymax=ones(1,ph)*10;

Ain1=[-kron(eye(ph),[0 1]) zeros(ph,ph*(m+t))];

Ain=[Ain1;-1 0 1 0 zeros(1,(m+n+t)*ph-4)];

bin=[-ymin';0.003];


z=quadprog(H,f,Ain,bin,Aeq,beq,[],[]);

figure(1)

plot(z(4:2:ph*n)-z(2:2:(ph-1)*n))
title('Y-velocity')

figure(2)
subplot(2,1,1)
plot(z(3:2:ph*n)-z(1:2:(ph-1)*n))
title('X-acceleration')
subplot(2,1,2)
plot(z(1:2:ph*n));
title('x-velocity')

figure(3)
plot(z(n:n:ph*n))
hold on
plot(ymin,'k','Linewidth',3);plot(ymax,'k','Linewidth',3);plot(ysp(2,:),'--r');
axis([0 ph -1 11])