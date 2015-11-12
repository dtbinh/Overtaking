clear
clc
close
T=1;
%% Simulation conditions
simulate=1; % Show simulation in RT
M=400/T; %simulation time

%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
task.N=4000; 
N=task.N; %Number of samples (som Nikolce)                                                         %Som Nikolce
task.s=linspace(0,task.Ego.horizon,task.N)';                                    %[m] relative distance vector
task.ds=task.s(2)-task.s(1);  
A = [0 T 0;0 0 0;0 0 0];
B = [0 0;1 0;0 1];
C = [0 1 0; 0 0 1];
D = [0 0;0 0];


sys=c2d(ss(A,B,C,D),T);
A=sys.a;B=sys.b;C=sys.c;

xd=0;                          % Setpoint x
xdotd=1;                  % Setpoint xd
yd=task.road.lanewidth/2;     % Setpoint y

x0=0;
posX=x0;
xdot0=1;
y0=task.road.lanewidth/2;
xk=[x0 xdot0 y0]';
%T=task.Ego.horizon/task.N;
% N=task.Ego.horizon;

slipAngle=0.01; 
sMax=atan(slipAngle);
%% MPC parameters
sizeA=size(A,2);
q=[0 0 0; 0 1000 0; 0 0 100];
r=1;
pf=eye(size(A))*q ;
Q=1*q*C'*C;
R=1*r;

%% Build Quadprog matrices
Aeq=[[[zeros(sizeA,N*sizeA); kron(eye(N-1,N),-A)] + eye(sizeA*N)],kron(eye(N),-B)];
AA=[A;zeros(sizeA*(N-1),sizeA)];
RR=eye(N*size(B,2))*R; 
%QQ=blkdiag(kron(eye((N)),Q),pf);
QQ=kron(eye((N)),Q);
QR=blkdiag(QQ,RR);



%% Cost function
H=2*QR; %1/2
f=zeros(size(H,1),1);

options = optimset('Algorithm','interior-point-convex');

%% Generate leading vehicle
ymax=ones(1,N)*10;
ymin=zeros(1,N);
% ymin(floor(2*N/6):floor(3*N/6))=5*ones(1,length(ymin(floor(2*N/6):floor(3*N/6))));
ymin(floor(N/3):floor(N/3+10))=5*ones(1,length(ymin(floor(N/3):floor(N/3+10))));
%%

%% Inequality constraints
%Max acceleration and braking
AinInputs(1,1)=1;
AinInputs(2,1)=0;
binInputs(1,1)=2;
binInputs(2,1)=0;

%Max lane changing speed'
AinInputs(3,2)=1;
AinInputs(4,2)=-1;
binInputs(3,1)=sMax*xk(2);
binInputs(4,1)=sMax*xk(2);

%Stay on the road
AinStates(1,3)=1;
AinStates(2,3)=-1;
binStates(1,1)=task.road.lanewidth*2;
binStates(2,1)=0;

%Maximum speed
% AinStates(3,2)=1;
% binStates(3,1)=task.Ego.vxmax;

%Create Ain
Ain=blkdiag(kron(eye(N),AinStates),kron(eye(N),AinInputs));
bin=[kron(ones(N,1),binStates);kron(ones(N,1),binInputs)];

for i=1:N
    bin(i*2)=-ymin(i);
end

    %% calculate trajectory

   beq=AA*(xk-[xd;xdotd;yd]); 
   
    % The matrix AA defines how the last measured Akzk = bk for zk =ured state xk
    % determines the right hand side of the inequality condition.
    z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[],options);
   
    plotroad(task,N*xdotd)
    plot(ymin,'r')
    plot(ymax,'r')
    plot(z(3:3:N*3),'b--') 
    
    %% Follow path
    for i=1:N
    uk=z(sizeA*N+(2*i-1):sizeA*N+(2*i));
    xk=A*xk+B*uk;
    plotcar(i,xk(3),'g*')
    pause(0.001)
    end
    

    
%     for i=1:N
%         plotcar(xPos(i),yPos(i),'g*')
%         pause(0.1)
%     end
    