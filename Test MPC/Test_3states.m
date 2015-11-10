clear
clc
clf
T=0.1;
%% Simulation conditions

M=100/T; %simulation time

%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
task.N=2;                                                                     %Number of samples (som Nikolce)                                                         %Som Nikolce
task.s=linspace(0,task.Ego.horizon,task.N)';                                    %[m] relative distance vector
task.ds=task.s(2)-task.s(1);  
A=[1 T 0;0 0 0;0 0 1];
B=[0 0;1 0; 0 1];
C=[1 0 0; 0 1 0;0 0 1];


xd=200;                          % Setpoint x
xdotd=70/3.6;                  % Setpoint xd
yd=task.road.lanewidth/2;     % Setpoint y

posX=0;
x=0;
xdot=0;
xv0=[x xdot task.road.lanewidth/2];
xk=xv0';
vx=0;
vy=0;
ax=0;
ay=0;
%T=task.Ego.horizon/task.N;
N=task.Ego.horizon;
vvec=[0 0 0]';
                                                 %[m] sampling interval

%% MPC parameters
sizeA=size(A,2);
q=[100 0 0; 0 1 0; 0 0 1];
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

% Max acceleration constraint
Ain=zeros(size(A,1)*N,(size(A,1)+size(B,2))*N);
Ain(1,sizeA*N+1)=1;
Ain(2,3)=1;
Ain(3,6)=1;
bin=zeros(size(Ain,1),1);
bin(1,1)=4;

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
   beq=AA*(xk-[xd;xdotd;yd]); 

    % The matrix AA defines how the last measured Akzk = bk for zk =ured state xk
    % determines the right hand side of the inequality condition.
    z=quadprog(H,f,Ain,bin,Aeq,beq,[],[],[],options);
    uk=z(sizeA*N+1:sizeA*N+2);
    xk=A*xk+B*uk;
    
    uvec(:,i)=uk;
    
    
    %% Plot vehicle
    %posX=posX+xk(1)*T;
    posX=xk(1);
    posY=xk(3);
    clf
    plotroad(task,M*20)
    plotcar(posX,posY)
   %pause(0.050)
    if i == 50
        bin(2,1)=2;
        bin(3,1)=2;
        5
    end
    
    if i == 400
        bin(2,1)=5;
        bin(3,1)=5;
        6
    end


end
figure(2)
hold off
plot(vvec(1,:));hold on
plot(vvec(2,:))
grid