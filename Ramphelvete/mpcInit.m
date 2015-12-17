function [H,Aeq,beq]=mpcInit(A,B,C,ph,task,ds)

%%
%   mpcInit(A,B,C,ph,task,ds)
%   A,B,C is system
%   ph = prediction horizon
%
%%
%% Parameters
safetymargin=task.Ego.longsafetymargin;
laneWidth = task.road.lanewidth;
n = size(A,2);                          % Number of states
m = size(B,2);                          % Number of inputs
vD=task.Ego.velocity-task.obstacle{1}.velocity;

% State/input penalty
qx_ref = task.Ego.profile.qx_ref;
qax=task.Ego.profile.qax;
qvy=task.Ego.profile.qvy;
qjx=task.Ego.profile.qjx;
qay=task.Ego.profile.qay;
qt=0;
r = 1;
H1 = blkdiag(kron(eye(ph),C'*qx_ref*C),kron(eye(ph),eye(m)*r));  % Extend costfunction with, same things as nikolce.

% Costfunction for x acceleration
H2 = [kron(eye(ph),[1 0;0 0]) + [zeros(2,ph*n);kron(eye(ph-1),[-1 0;0 0]) zeros((ph-1)*n,2)] + ...
    [zeros((ph-1)*n,2) kron(eye(ph-1),[-1 0;0 0]);zeros(2,ph*n)] + [zeros(2,ph*n);zeros((ph-2)*n,2)...
    kron(eye(ph-2),[1 0;0 0]) zeros((ph-2)*n,2);zeros(2,ph*n)]];
H2 =qax*[H2 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))]/(ds^2);

% Costfunction for y velocity 
H3 = [kron(eye(ph),[0 0;0 1]) + [zeros(2,ph*n);kron(eye(ph-1),[0 0;0 -1]) zeros((ph-1)*n,2)] + ...
    [zeros((ph-1)*n,2) kron(eye(ph-1),[0 0;0 -1]);zeros(2,ph*n)] + [zeros(2,ph*n);zeros((ph-2)*n,2)...
    kron(eye(ph-2),[0 0;0 1]) zeros((ph-2)*n,2);zeros(2,ph*n)]];
H3 =qvy*[H3 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))]/(ds^2);

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

H4 =qay*[H4 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))]/(ds^2);

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
H5 = qjx*[H5 zeros(ph*n,ph*m);zeros(ph*m,ph*(n+m))]/(ds^2);

H=2*(H1+H2+H3+H4+H5);
H = blkdiag(H,eye(ph)*0);
%% Aeq/beq
Aeq1 =[[zeros(2,n*ph);-eye((ph-1)*n) zeros((ph-1)*n,2)]+eye(ph*n) kron(eye(ph),-B) zeros(n*ph,ph)];
Aeq2 = [kron(eye(ph),[-1/(vD^2) 0]) zeros(ph,m*ph) ...
    [zeros(1,ph);eye(ph-1) zeros(ph-1,1)]+ -1*eye(ph)];
Aeq =[Aeq1;Aeq2];

beq = [zeros(ph*n,1); ones(ph,1)*(-2/vD)];
end