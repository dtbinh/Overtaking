function [vvec yvec bound xsp]=MPCtrajectory(A,B,C,D,task, ph, obstacle,xsp,x0,q,r,vE)
tic
%% Parameters
safetymargin=task.Ego.longsafetymargin;
laneWidth = task.road.lanewidth;
n = size(A,2);                          % Number of states
m = size(B,2);                          % Number of inputs

%% State/input penalty

forbidden=[round((obstacle-3*safetymargin)/vE) round((obstacle+3*safetymargin)/vE)];
for i=1:ph
    if i>=forbidden(1) && i<=forbidden(2)
    xsp(2,i)=7.5;
    end
end

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

nCon=3;
Ain=zeros(nCon*ph,(m+n)*ph);
bin=zeros(nCon*ph,1);

% Set obstacle (1:ph)

for i=1:ph
    if i>=forbidden(1) && i<=forbidden(2)
    bin(i)=-laneWidth;
    Ain(i,i*2)=-1;
    end
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

for i = 1:ph
    vvec(i)=z(i*2-1);
    yvec(i)=z(i*2);
end
bound=-bin(1:ph);
end