clear
clf

%% Parameters
A=[0 1 0; 0 0 0; 0 0 0];
B=[0 0; 1 0; 0 1];

x=0;
xv0=[x task.road.lanewidth/2];
xv=xv0;
vx=0;
vy=0;
ax=1;
ay=1;
T=task.Ego.horizon/task.N;

task=struct;
task.N=100;                                                                     %Number of samples (som Nikolce)
task.Ego=standardcar;                                                           %Som Nikolce
task.s=linspace(0,task.Ego.horizon,task.N)';                                    %[m] relative distance vector
task.ds=task.s(2)-task.s(1);                                                    %[m] sampling interval
task.road=roadsegment;


% plot the road
hold on
fill([0;1;1;0]*task.s(end),[0;0;1;1]*task.road.lanewidth*2,0.8*[1 1 1],'EdgeColor',0.7*[1 1 1]);
plot([0,task.s(end)],task.road.lanewidth*[1 1],'w--','LineWidth',2);
%plot(task.s,task.ymin,'b',task.s,task.ymax,'b');
%plot(task.s,task.E.yref,'k-.');
%plot(task.E.x0,task.E.y0,'r*');
%plot(task.L.x0,task.L.y0,'g*');


ux=[1 zeros(1,task.Ego.horizon-1)];
uy=[ zeros(1,task.Ego.horizon)];

%For loop
for i=1:task.Ego.horizon

    %% Controller
    yd=task.road.lanewidth/2;
    xd=task.s(i)';
    
    
    %% Update model
    ax(i+1) = ux(i);
    ay(i+1) = uy(i);
    vx(i+1) = vx(i)+ax(i+1)*T;
    vy(i+1) = vy(i)+ay(i+1)*T;
    xv(i+1,:)=[xv(i,1)+T*vx(i+1) xv(i,2)+T*vy(i+1)];

    %% Plot vehicle
    plot(xv(:,1),xv(:,2),'r*')
    pause(0.050)
    
end
