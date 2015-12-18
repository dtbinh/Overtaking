% function [vvec,yvec,bound] = MPC2(A,B,C,task,ph,xsp,x0,H,Aeq,beq)
function yvec = MPC2(xin)
%% Parameters

global task qx_ref ph H Aeq beq C;

% safetymargin=task.Ego.longsafetymargin;


xsp(1, 1:150) = xin(1:2:299);    % referens: xhast, ypos 
xsp(2, 1:150) = xin(2:2:300);

x0 = xin(301:302); % nuvarande xhast, ypos

laneWidth = 5;
n = 2;                          % Number of states
m = 2;                          % Number of inputs


% State/input penalty


f1 = 2*(C*xsp)'*qx_ref;

f=[];

for i=1:size(f1,1)
    f = [f;f1(i,1);f1(i,2)];
end

f = -[f; zeros(m*ph,1)];
% Equality constraints
beq(1:2)=x0;


% Inequality constraints
ymin=ones(1,ph)*eps;
% ymin(100:120)=4;
% ymax=ones(1,ph)*laneWidth*2;

nCon=4;
Ain=zeros(nCon*ph,(m+n)*ph);
bin=zeros(nCon*ph,1);

% Set constraint for obstacle
for i=1:ph

    if xsp(2,i)==7.5;
    bin(i)=-5-task.Ego.width/2;%xsp(2,i);%+task.Ego.width;
    Ain(i,i*n)=-1;
    else
    bin(i)=-task.Ego.width/2; 
    Ain(i,i*n)=-1;
    end
end

% Set constraint for oncoming vehicle

for i=1:ph

    bin(ph+i)=2*laneWidth-task.Ego.width/2;
    Ain(ph+i,i*n)=1;
end

%Set max turning (ph+1:3ph)
for i=2:ph
    bin(2*ph+i)=0.2;
    Ain(2*ph+i,ph*n+i*2-2)=1;
    Ain(2*ph+i,ph*n+i*2)=-1;
end
for i=2:ph
    bin(3*ph+i)=0.2;
    Ain(3*ph+i,ph*n+i*2-2)=-1;
    Ain(3*ph+i,ph*n+i*2)=1;
end

% % Set top bound (3ph+1:4ph)
% for i=1:ph
%     bin(4*ph+i)=2*laneWidth-task.Ego.width/2;
%     Ain(4*ph+i,i*n)=1;
% 
% end

options = optimset('Algorithm','interior-point-convex','Display','off');

z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[],options);

if isempty(z)
    disp('Problem Infeasible');
end

% for i = 1:ph
%     vvec(i)=z(i*2-1);
%     yvec(i)=z(i*2);
% end

yvec = z(2*(1:ph));

% bound=[-bin(1:ph),bin(ph+1:2*ph)];

end