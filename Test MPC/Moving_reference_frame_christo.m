clear
clc
tic
%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
safetymargin=task.Ego.longsafetymargin;
% Ego vehicle
vE=70/3.6;
pE=0;

% Leading car
vL=60/3.6;
pL=1000;

%% Moving reference frame
ds=1;                                   % delta s = 1 meter
A = [0 0;0 0];
B = [1 0;0 1];

n = size(A,2);                          % Number of states
m = size(B,2);                          % Number of inputs

C = [1 0;0 1];
D = [0 0;0 0];

sys=ss(A,B,C,D);
sysd=c2d(ss(A,B,C,D),ds);
A=sysd.a;B=sysd.b;C=sysd.c;

%% Set conditions

ph = 300;                                 % Prediction horizon

laneWidth = task.road.lanewidth;                        % Lanewidth
xsp=[ones(1,ph)*(vE-vL);ones(1,ph)*laneWidth/2];    % Setpoint for xdot and y pos.

x0=[vE-vL;laneWidth/2];                     % Initial state value


%% State/input penalty

forbidden=[70 round(70+safetymargin)];
for i=1:ph
    if i>=forbidden(1) && i<=forbidden(2)
    xsp(2,i)=7.5;
    end
end

q = 1;
r = 30;

H = 2*blkdiag(kron(eye(ph),C'*q*C),kron(eye(ph),eye(m)*r));

f1 = 2*q*(C*xsp)';
f=[];
for i=1:size(f1,1)
    f = [f;f1(i,1);f1(i,2)];
end
f = -[f;zeros(m*ph,1)];

%% Equality constraints
Aeq =[[zeros(2,n*ph);-eye((ph-1)*n) zeros((ph-1)*n,2)]+eye(ph*n) kron(eye(ph),-B)];
beq = zeros(size(Aeq,1),1);
beq(1:2)=x0;

%% Inequality constraints
ymin=ones(1,ph)*eps;ymin(100:120)=4;
ymax=ones(1,ph)*laneWidth*2;

nCon=1;
Ain=zeros(nCon*ph,(m+n)*ph);
bin=zeros(nCon*ph,1);
point=0;
% Set obstacle (1:ph)

forbidden=[70 round(70+safetymargin)];
for i=1:ph
    if i>=forbidden(1) && i<=forbidden(2)
    bin(i)=-laneWidth;
    Ain(i,i*2)=-1;
    end
end

% Set max turning (ph+1:2ph)
for i=2:ph
    bin(ph+i)=0.001;
    Ain(ph+i,ph*n+i*2-2)=1;
    Ain(ph+i,ph*n+i*2)=-1;
end
for i=2:ph
    bin(2*ph+i)=0.001;
    Ain(2*ph+i,ph*n+i*2-2)=-1;
    Ain(2*ph+i,ph*n+i*2)=1;
end

z=quadprog(H,f,Ain,bin,Aeq,beq);
toc

for i = 1:ph
    vvec(i)=z(i*2-1);
    yvec(i)=z(i*2);
end

d_final(1)=0;
for i=2:ph
    d_final(i)=d_final(i-1)+vvec(i)+vL;
end

clf
plotroad(task,max(d_final))
hold on
plot(d_final,yvec)
plot(d_final,-bin(1:ph),'b')
plot(d_final,xsp(2,:),'--')

%% PID
xref=[];
xk(:,1)=x0;
uk=[0;0];
Kp=1;
Ki=0;
Kd=0.75;
errorSum=0;
error=0;
for i = 1:ph
xref=[vvec(i);yvec(i)];

errorD=error-(xref-xk(:,i));
error=(xref-xk(:,i));
errorSum=errorSum+error;

TF=tf(sysd);
C=pid(Kp,Ki,Kd);
uk=error*C.Kp+errorSum*C.Ki+errorD*C.Kp;  
    
xk(:,i+1)=A*xk(:,i)+B*uk;

plotcar(d_final(i),xk(2,i),'r*')
pause(0.01);
end
