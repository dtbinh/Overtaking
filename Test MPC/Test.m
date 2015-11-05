clear
clc
clf

%% Simulation conditions

M=50; %simulation time

%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
task.N=2;                                                                     %Number of samples (som Nikolce)                                                         %Som Nikolce
task.s=linspace(0,task.Ego.horizon,task.N)';                                    %[m] relative distance vector
task.ds=task.s(2)-task.s(1);   


A=[1 0; 0 1];
B=[1 0;0 1];
C=[1 1];

x=0;
xv0=[x task.road.lanewidth/2];
xv=xv0;
xk=xv0';
vx=0;
vy=0;
ax=1;
ay=0;
T=task.Ego.horizon/task.N;

                                                 %[m] sampling interval

%% MPC parameters
sizeA=size(A);
q=10;
r=1;
pf=eye(size(A))*q ;
Q=q*C'*C;
R=1*r;

%% Build Quadprog matrices
Aeq=[[[zeros(sizeA(1),task.N*sizeA(2)); kron(eye(task.N-1,task.N),-A)] + eye(sizeA*task.N)],kron(eye(task.N),-B)];
AA=[A;zeros(sizeA(2)*(task.N-1),sizeA(1))];
RR=blkdiag(eye(task.N)*R); 
QQ=blkdiag(kron(eye((task.N-1)),Q),pf);
QR=blkdiag(QQ,RR);

%% Cost function
H=2*QR; %1/2
f=zeros(size(H,1),1)


%plot(task.s,task.ymin,'b',task.s,task.ymax,'b');
%plot(task.s,task.E.yref,'k-.');
%plot(task.E.x0,task.E.y0,'r*');
%plot(task.L.x0,task.L.y0,'g*');


ux=[ 1 zeros(1,M-1)];
uy=[ zeros(1,M)];

%For loop
for i=1:M

    %% Controller
    yd=task.road.lanewidth/2;
   % xd=task.s(i)';
    
   beq=AA*xk; 

    % The matrix AA defines how the last measured Akzk = bk for zk =ured state xk
    % determines the right hand side of the inequality condition.
    z=quadprog(H,f,Aeq,beq);
    uk=z(sizeA*task.N+1);
    xk=A*xk+B*uk;
    
    clf
    plotroad(task,M)
    plotcar(xk(i,1),xk(i,2))
    pause(0.050)
        
    
    %% Update model
%     ax(i+1) = ux(i);
%     ay(i+1) = uy(i);
%     vx(i+1) = vx(i)+ax(i+1)*T;
%     vy(i+1) = vy(i)+ay(i+1)*T;
%     xv(i+1,:)=[xv(i,1)+T*vx(i+1) xv(i,2)+T*vy(i+1)];

    %% Plot vehicle
    clf
    plotroad(task,M)
    plotcar(xv(i,1),xv(i,2))
    pause(0.050)
    
    
end
