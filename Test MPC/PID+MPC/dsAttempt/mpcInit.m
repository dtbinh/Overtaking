function [H,Aeq,beq]=mpcInit(A,B,C,N,task,ds)

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

% State/input penalty
qx_ref = task.Ego.profile.qx_ref;
qax=task.Ego.profile.qax;
qvy=task.Ego.profile.qvy;
qjx=task.Ego.profile.qjx;
qay=task.Ego.profile.qay;
r = 1;

H1 = blkdiag(kron(eye(N),C'*qx_ref*C),kron(eye(N),eye(m)*r));  % Extend costfunction with, same things as nikolce.

% Costfunction for x acceleration
H2 = [kron(eye(N),[1 0;0 0]) + [zeros(2,N*n);kron(eye(N-1),[-1 0;0 0]) zeros((N-1)*n,2)] + ...
    [zeros((N-1)*n,2) kron(eye(N-1),[-1 0;0 0]);zeros(2,N*n)] + [zeros(2,N*n);zeros((N-2)*n,2)...
    kron(eye(N-2),[1 0;0 0]) zeros((N-2)*n,2);zeros(2,N*n)]];
H2 =qax*[H2 zeros(N*n,N*m);zeros(N*m,N*(n+m))]/ds^2;

% Costfunction for y velocity 
H3 = [kron(eye(N),[0 0;0 1]) + [zeros(2,N*n);kron(eye(N-1),[0 0;0 -1]) zeros((N-1)*n,2)] + ...
    [zeros((N-1)*n,2) kron(eye(N-1),[0 0;0 -1]);zeros(2,N*n)] + [zeros(2,N*n);zeros((N-2)*n,2)...
    kron(eye(N-2),[0 0;0 1]) zeros((N-2)*n,2);zeros(2,N*n)]];
H3 =qvy*[H3 zeros(N*n,N*m);zeros(N*m,N*(n+m))]/ds^2;

% Costfunction for y acceleration
H4 = zeros(N*n,N*n);
repBlock=zeros(6,6);
repBlock(2,:)=[0 1 0 -2 0 1];
repBlock(4,:)=[0 -2 0 4 0 -2];
repBlock(6,:)=[0 1 0 -2 0 1];

for i=1:2:n*N-5
    temp=zeros(N*n,N*n);
    temp(i:i+5,i:i+5)=repBlock;
    H4=H4+temp;
end

H4 =qay*[H4 zeros(N*n,N*m);zeros(N*m,N*(n+m))]/ds^2;

% Costfunction for x jerk
H5 = zeros(N*n,N*n);
repBlock=zeros(6,6);
repBlockH5(1,:)=[1 0 -2 0 1 0];
repBlockH5(3,:)=[-2 0 4 0 -2 0];
repBlockH5(5,:)=[1 0 -2 0 1 0];

for i=1:2:n*N-5
    temp=zeros(N*n,N*n);
    temp(i:i+5,i:i+5)=repBlock;
    H5=H5+temp;
end
H5 =qjx*[H5 zeros(N*n,N*m);zeros(N*m,N*(n+m))]/ds^2;

H=2*(H1+H2+H3+H4+H5);
%% Aeq/beq
Aeq =[[zeros(2,n*N);-eye((N-1)*n) zeros((N-1)*n,2)]+eye(N*n) kron(eye(N),-B)];
beq = zeros(size(Aeq,1),1);
end