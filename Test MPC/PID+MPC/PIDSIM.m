clear
clc

%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
laneWidth=task.road.lanewidth;
ph = 150; 
q=1;
r=30;
% Ego vehicle
vE=70/3.6;
pE=0;

% Leading car
vL=60/3.6;
obstacle=500;

xsp=[ones(1,ph)*(vE-vL);ones(1,ph)*laneWidth/2];    % Setpoint for xdot and y pos.
x0=[vE-vL;laneWidth/2];                     % Initial state value

%% Moving reference frame
ds=1;                                   % delta s = 1 meter
A = [0 0;0 0];
B = [1 0;0 1];

C = [1 0;0 1];
D = [0 0;0 0];

sys=ss(A,B,C,D);
sysd=c2d(ss(A,B,C,D),ds);
A=sysd.a;B=sysd.b;C=sysd.c;



%% PID
xref=[];
xk(:,1)=x0;
uk=[0;0];
Kp=0.6;
Ki=0;
Kd=0;
errorSum=0;
error=0;
xPos=0;
clf
for i = 1:ph
% obstacle=obstacle-xk(1,i);
     if i==1 || i==50 || i==100
        [vvec yvec bound xa]=MPCtrajectory(A,B,C,D,task,ph,obstacle,xsp,xk(:,i),q,r,vE); 
        
        d(1)=0;
        for k=2:ph
            d(k)=d(k-1)+vvec(k)+vL;
        end
        plotroad(task,ph*vE)
        hold on
        plot(d,bound(1:ph),'b')
        plot(d,xa(2,:),'--')
        plot(d,yvec)
     end
xref=[vvec(i);yvec(i)];

errorD=error-(xref-xk(:,i));
error=(xref-xk(:,i));
errorSum=errorSum+error;

Cpid=pid(Kp,Ki,Kd);
uk=error*Cpid.Kp+errorSum*Cpid.Ki+errorD*Cpid.Kp;  
    
xk(:,i+1)=A*xk(:,i)+B*uk;
xPos=xPos+xk(1,i+1);
plotcar(xPos,xk(2,i),'r*')
pause(0.01);
end
