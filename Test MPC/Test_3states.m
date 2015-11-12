clear
clc
clf
T=1;
%% Simulation conditions
simulate=1; % Show simulation in RT
M=200/T; %simulation time

%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
task.N=2; 
N=150; %Number of samples (som Nikolce)                                                         %Som Nikolce
task.s=linspace(0,task.Ego.horizon,task.N)';                                    %[m] relative distance vector
task.ds=task.s(2)-task.s(1);  
A=[1 T 0;0 1 0;0 0 1];
B=[0;0;T];
C=[0 0 1];


xd=0;                          % Setpoint x
xdotd=110/3.6;                  % Setpoint xd
yd=task.road.lanewidth/2;     % Setpoint y

x0=0;
posX=x0;
xdot0=0;
y0=task.road.lanewidth/2;
xv0=[x0 xdot0 task.road.lanewidth/2];
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
nCon=7; %number of constraints
AinStates=zeros(nCon,size(A,2));
AinInput=zeros(nCon,size(B,2));
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
ymax=ones(1,N)*8;
ymin=zeros(1,N);
ymin(floor(N/3):floor(N/2))=3*ones(1,length(ymin(floor(N/3):floor(N/2))));
%%
%For loop
for i=1:M
%% Update leading vehicle
    xL=xL+vL;
    
    
    %% Inequality constraints
%Max acceleration and braking
AinInput(1,1)=1;
AinInput(2,1)=-1;
bin(1,1)=2;
bin(2,1)=2;

%Max lane changing speed
AinInput(3,2)=1;
AinInput(4,2)=-1;
bin(3,1)=sMax*xk(2);
bin(4,1)=sMax*xk(2);

%Stay on the road
AinStates(5,3)=1;
AinStates(6,3)=-1;
bin(5,1)=task.road.lanewidth*2;
bin(6,1)=0;

%Min distance to car ahead 
AinStates(7,1)=1;
bin(7,1)=xL-100;

%Create Ain
Ain=AinStates;
for i=1:N-1
Ain=[Ain AinStates];
end
for i=1:N
Ain=[Ain AinInput];
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

    
    %plotcar(posX,posY)
   %pause(0.001)



end
if simulate == 0
    plotroad(task,M*110/3.6)
    plotcar(posX,posY,'r*')
    plotcar(posXL,yL*ones(1,M),'b*')
end
figure(2)
hold off
% plot(vvec(1,:));hold on
plot(vvec(2,:))
% grid