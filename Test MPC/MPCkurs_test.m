% MPC with constraints
%
%---Basic system model
%
clc
close all;
clear all;
h=0.1;
A=[1 h;0.5*h 1];
B=[h^2/2; h];
C=[1 0];
n=size(A,1);
m=size(B,2);
%
%---Parameters
%
q=10;
r=1;
N=10;
x0=[0.5 1]';
%Own params
pf=eye(size(A))*q 
Q=q*C'*C;
R=1*r;

%
%---Define matrices for the QPcodecode
%
%For you to do!
sizeA=size(A);
Aeq=[[zeros(sizeA(1),N*sizeA(2)); kron(eye(N-1,N),-A)]+ eye(sizeA*N),kron(eye(N),-B)]
AA=[A;zeros(sizeA(2)*(N-1),sizeA(1))];
RR=blkdiag(eye(N)*R); 
QQ=blkdiag(kron(eye((N-1)),Q),pf);
QR=blkdiag(QQ,RR);

%---For the case with actuator constraints
%

Ain=[[zeros(2*N)],[eye(N);-eye(N)]]; % Use empty matrices for the first case without actuator...
bin=[ones(2*N,1)]; % ...constraints and change for the case with constraints!
%
%---Cost function
%
%For you to do!
H=2*QR; %1/2
f=zeros(size(H,1),1)
%
%---MPC algorithm
%
M=100; % simulation time
xk=x0; % initialize state vector
yvec=[];
uvec=[];

options = optimset('Algorithm','interior-point-convex','Display','off');
for k=1:M,
beq=AA*xk; 

% The matrix AA defines how the last measured Akzk = bk for zk =ured state xk
% determines the right hand side of the inequality condition.
z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[],options);
uk=z(n*N+1);
xk=A*xk+B*uk;
yvec=[yvec; C*xk];
uvec=[uvec; uk];
end


tvec=h*(1:1:M);

figure(1)
title('N=10 , q=10')
hold on
plot(tvec,yvec,'-',tvec,uvec,'--');
grid
legend('y vector','u vector')
xlabel('time')
ylabel('angle')



