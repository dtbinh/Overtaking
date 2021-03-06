clear
clc
clf

%% Simulation conditions

M=30; %simulation time

%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
task.N=2;                                                                     %Number of samples (som Nikolce)                                                         %Som Nikolce
task.s=linspace(0,task.Ego.horizon,task.N)';                                    %[m] relative distance vector
task.ds=task.s(2)-task.s(1);  

A=[1 0; 0 1];
B=[1 0; 0 0.4];
C=[1;1];

yd=task.road.lanewidth/2+5;
xd=100/3.6;

posX=0;
x=0;
xv0=[x task.road.lanewidth/2];
xv=xv0;
xk=xv0';
vx=0;
vy=0;
ax=0;
ay=0;
T=task.Ego.horizon/task.N;
N=task.Ego.horizon;
vvec=[0 0]';
                                                 %[m] sampling interval

%% MPC parameters
sizeA=size(A,2);
q=1;
r=1;
pf=eye(size(A))*q ;
Q=1*q*C'*C;
R=1*r;

%% Build Quadprog matrices
Aeq=[[[zeros(sizeA,N*sizeA); kron(eye(N-1,N),-A)] + eye(sizeA*N)],kron(eye(N),-B)];
AA=[A;zeros(sizeA*(N-1),sizeA)];
RR=eye(N*size(B,2))*R; 
QQ=blkdiag(kron(eye((N)),Q),pf);
QR=blkdiag(QQ,RR);

% Max acceleration constraint
Ain=zeros(size(A,1)*N,(size(A,1)+size(B,1))*N);
Ain(1,5)=1;
bin=[3 0 0 0]';

%% Cost function
H=2*QR; %1/2
f=zeros(size(H,1),1);

options = optimset('Algorithm','interior-point-convex','Display','off');


%plot(task.s,task.ymin,'b',task.s,task.ymax,'b');
%plot(task.s,task.E.yref,'k-.');
%plot(task.E.x0,task.E.y0,'r*');
%plot(task.L.x0,task.L.y0,'g*');



%For loop
for i=1:M

    %% Controller

    vvec=[vvec xk];
   beq=AA*(xk-[xd;yd]); 

    % The matrix AA defines how the last measured Akzk = bk for zk =ured state xk
    % determines the right hand side of the inequality condition.
    z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[],options);
    uk=z(sizeA*N+1:sizeA*N+2);
    xk=A*xk+B*uk;
    
    uvec(:,i)=uk;
    
    
    %% Plot vehicle
    posX=posX+xk(1)*T;
    posY=xk(2);
    clf
    plotroad(task,M*20)
    plotcar(posX,posY, 'r')
    pause(0.050)
    
end
figure(2)
plot(vvec(1,:));hold on
plot(vvec(2,:))
grid