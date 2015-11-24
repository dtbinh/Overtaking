clear
clc

%% Parameters
task=struct;
task.road=roadsegment;
task.Ego=standardcar;  
laneWidth=task.road.lanewidth;
safetymargin=task.Ego.longsafetymargin;
ph = 150; 
q=1;
r=1;
% Ego vehicle
vE=70/3.6;
pE=0;

% Leading car
vL=60/3.6;

% Array of obstacles and obstacleindex
obstacle=[];
obstacleNr=0;

% Setpoint for xdot and y pos.
xsp=[ones(1,ph)*(vE-vL);ones(1,ph)*laneWidth/2];

% Initial state value
x0=[vE-vL;laneWidth/2];

% Moving reference frame
ds=1;               % delta s = 1 meter

%Point mass system
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
xvec(1)=0;
clf
mpcInterval=5;
obstacleInterval=50;
M=1000;




for i = 1:M
    
    if i == 1
        obstacleNr=obstacleNr+1;
        obstacle(obstacleNr)=100;        
    elseif mod(i,obstacleInterval)==0
        obstacleNr=obstacleNr+1;
        obstacle(obstacleNr)=xPos+500;
        xPos;        
    end
    %obstacle(:)=obstacle(:)-xk(1,i);
    if mod(i,mpcInterval)==0 || i==1    
        [vTemp,yTemp,boundTemp,xaTemp]=MPCtrajectory(A,B,C,D,task,ph,obstacle(end),xsp,xk(:,i),q,r);
         if i>1
                % Build spatial vectors
            yvec=[yvec(1:i) yTemp(1:end)];
            vvec=[vvec(1:i) vTemp(1:end)];
            bound=[bound(1:i) boundTemp(1:end)'];
            xa=[xa(:,1:i) xaTemp(:,1:end)];
            
                % Build x vector
            xvecTemp(1)=xPos;
            for k=2:ph
                xvecTemp(k)=xvecTemp(k-1)+vvec(k);
            end 
            xvec=[xvec(1:i) xvecTemp];
            
         else
                yvec=yTemp;    
                vvec=vTemp;
                bound=boundTemp';
                xa=xaTemp;
            for k=2:ph
                xvec(k)=xvec(k-1)+vvec(k);
            end
         end     
         
         for k=1:ph
              if xvec(k+i-1)>=obstacle(obstacleNr)-10*safetymargin && xvec(k+i-1)<=obstacle(obstacleNr)+10*safetymargin
              xsp(2,k)=7.5;
              else
              xsp(2,k)=2.5;    
              end
         end
          
         
        plotroad(task,ph*vE)
        hold on
        plot(xvec,bound(:),'b')
        hold on
        plot(xvec(i:end),xa(2,i:end),'--')
        hold on
        plot(xvec(i:end),yvec(i:end))
    end
    % PID calculations
    xref=[vvec(i);yvec(i)];
    errorD=error-(xref-xk(:,i));
    error=(xref-xk(:,i));
    errorSum=errorSum+error;
    Cpid=pid(Kp,Ki,Kd);
    uk=error*Cpid.Kp+errorSum*Cpid.Ki+errorD*Cpid.Kp;      
    xk(:,i+1)=A*xk(:,i)+B*uk;
    xPos=xPos+xk(1,i+1);
    plotcar(xPos,xk(2,i+1),'ro')
    pause(0.05);
    % Locks axis
    axis([0 ph*vE 0 10])
end
