clear
clc
clf
T=1;
%% Simulation conditions
simulate=1;
M=200/T; %simulation time

%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
task.N=2; 
N=task.N; %Number of samples (som Nikolce)                                                         %Som Nikolce
task.s=linspace(0,task.Ego.horizon,task.N)';                                    %[m] relative distance vector
task.ds=task.s(2)-task.s(1);  
A=[1 T 0;0 1 0;0 0 1];
B=[T^2/2 0;T 0; 0 T];
C=[0 0 0;0 1 0;0 0 1];


xd=0;                          % Setpoint x
xdotd=110/3.6;                  % Setpoint xd
yd=task.road.lanewidth/2;     % Setpoint y

posX=0;
x=0;
xdot=0;
xv0=[x xdot task.road.lanewidth/2];
xk=xv0';
%T=task.Ego.horizon/task.N;
% N=task.Ego.horizon;
vvec=[0 0 0]';
slipAngle=pi/200; 
sMax=atan(slipAngle);
%% MPC parameters
sizeA=size(A,2);
q=[0 0 0; 0 1 0; 0 0 1];
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

%% Inequality constraints
nCon=5; %number of constraints
Ain=zeros(nCon,(size(A,1)+size(B,2))*N);
bin=zeros(nCon,1);


%% Cost function
H=2*QR; %1/2
f=zeros(size(H,1),1);

options = optimset('Algorithm','interior-point-convex','Display','off');


%plot(task.s,task.ymin,'b',task.s,task.ymax,'b');
%plot(task.s,task.E.yref,'k-.');
%plot(task.E.x0,task.E.y0,'r*');
%plot(task.L.x0,task.L.y0,'g*');

%% Generate leading vehicle
vL=70/3.6;
xL=700;
yL=task.road.lanewidth/2;

%For loop
for i=1:M
    
    

    %% Update leading vehicle
    xL=xL+vL;
    
    
    %% Inequality constraints
%Max acceleration and braking
Ain(1,sizeA*N+1)=1;
Ain(1,sizeA*N+1)=-1;
bin(1,1)=2;
bin(2,1)=2;

%Max lane changing speed
Ain(3,sizeA*N+2)=0;%1;
Ain(4,sizeA*N+2)=0;%-1;
bin(3,1)=sMax*xk(2);
bin(4,1)=sMax*xk(2);

%Stay on the road
Ain(5,3)=1;
Ain(6,3)=-1;
bin(5,1)=task.road.lanewidth*2;
bin(6,1)=0;

%Min distance to car ahead 
if abs(xL-xk(1))<100
    xk(3)
    Ain(7,6)=1;
    bin(7,1)=xk(3)-yL-task.road.lanewidth;
else
    Ain(7,3)=0;
    bin(7,1)=0;
end

    

    %% Controller
   vvec=[vvec xk];
   beq=AA*(xk-[xd;xdotd;yd]); 
   
    % The matrix AA defines how the last measured Akzk = bk for zk =ured state xk
    % determines the right hand side of the inequality condition.
    z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[],options);
    uk=z(sizeA*N+1:sizeA*N+2);
    xk=A*xk+B*uk;
    
    uvec(:,i)=uk;
    
    %% Plot vehicle
    if simulate==1
        posX=xk(1);
        posY=xk(3);
        posXL=xL;
        plotroad(task,M*110/3.6)
        plotcar(posX,posY,'r*')
        plotcar(posXL,yL,'g*')
        pause(0.00001)
    else
        posX(i)=xk(1);
        posY(i)=xk(3);
        posXL(i)=xL;
    end
    
    %posX=posX+xk(1)*T;
    posX(i)=xk(1);
    posY(i)=xk(3);
    
    %plotcar(posX,posY)
   %pause(0.001)



end
if simulate == 0
    plotroad(task,M*110/3.6)
    plotcar(posX,posY)
    plotcar(posXL,yL*ones(1,M))
end
% figure(2)
% hold off
% plot(vvec(1,:));hold on
% plot(vvec(2,:))
% grid