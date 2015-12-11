%
clear all;
clc;
task=struct;
task.N=300;                                         % number of samples
task.road=roadsegment;              
task.road.speedlimit=70/3.6;                        % [m/s] speed limit
task.oncomingveh=false;                             % is there an oncoming vehicle
task.adjacentveh=true;                              % is there a vehicle on the adjacent lane

% Ego vehicle
task.E=standardcar;    
task.E.vref=task.road.speedlimit*ones(task.N,1);    %[m/s] reference velocity
task.E.horizon=150;                                 %[m] prediction horizon
task.E.vxmax=80/3.6;                
task.E.x0=0;                                        %[m] initial longitudinal position
task.E.vx0=task.E.vref(1);                          %[m/s] initial longitudinal speed
task.E.y0=task.road.lanewidth/2;                    %[m] initial lateral position

% Leading vehicle
task.L=standardcar;                 
task.L.vx=50/3.6;                                   %[m/s] speed
task.L.x0=75;                                       %[m] initial longitudinal position
task.L.y0=task.road.lanewidth/2;                    %[m] initial lateral position

% Oncoming vehicle
if task.oncomingveh
    task.O=standardcar;                 
    task.O.vx=70/3.6;                               %[m/s] speed
    task.O.x0=650;                                  %[m] initial longitudinal position
    task.O.y0=1.5*task.road.lanewidth;              %[m] initial lateral position
end

% Vehicle on an adjacent lane
if task.adjacentveh
    task.A=standardcar;                 
    task.A.vx=70/3.6;                               %[m/s] speed
    task.A.x0=0;                                    %[m] initial longitudinal position
    task.A.y0=1.5*task.road.lanewidth;              %[m] initial lateral position
end

init;

%% solve concex problem
% tic
res=cvxsolveprob(task); % keep results in structure res
Ax=diff(res.vEx)./diff(res.t); Ax=[Ax; Ax(end)];
Ay=diff(res.vEy)./diff(res.t); Ay=[Ay; Ay(end)];
fprintf('%s: cost=%1.4f, vx~[%1.0f, %1.0f]km/h, ax~[%1.1f, %1.1f]m/s2, vy~[%1.1f, %1.1f]m/s, ay~[%1.1f, %1.1f]m/s^2, t=%1.2f ms\n', ...
    res.status,res.cost, min(res.vEx)*3.6, max(res.vEx)*3.6, ...
    min(Ax), max(Ax), min(res.vEy), max(res.vEy), min(Ay), max(Ay),res.time(end)*1000);

task.res=res;
save task.mat task;
% toc
% some plots
%% Plot results in the moving (TV) frame
f=figure; 
f.Position(2)=50;
f.Position(4)=700;
subplot(3,1,1); hold on;

% plot the road
fill([0;1;1;0]*task.s(end),[0;0;1;1]*task.road.lanewidth*2,0.8*[1 1 1],'EdgeColor',0.7*[1 1 1]);
plot([0,task.s(end)],task.road.lanewidth*[1 1],'w--','LineWidth',2);
plot(task.s,task.ymin,'b',task.s,task.ymax,'b');
plot(task.s,task.E.yref,'k-.');
plot(task.E.x0,task.E.y0,'r*');
plot(task.L.x0,task.L.y0,'b*');

% plot optimal path
plot(task.s,res.yE,'k','LineWidth',2);
% xlim([0,task.E.horizon]); ylim([0 2]*task.road.lanewidth);
% xlabel('Relative longitudinal position (m)');
% ylabel('Lateral position (m)');

% legend(h,'Optimal path of the ego vehicle');
% title('Moving (TV) frame');

% subplot(3,1,2); hold on;
% [AX,H1,H2] =plotyy(task.s,res.vEx*3.6,task.s,res.vEy);
% set(get(AX(1),'Ylabel'),'String','Longitudinal speed (km/h)')
% set(get(AX(2),'Ylabel'),'String','Lateral speed (m/s)') 
% xlabel('Relative position of the ego vehicle (m)');
% % legend('Longitudinal speed','Lateral speed');
% xlim([0,task.s(end)]);
% 
% subplot(3,1,3); hold on;
% [AX,H1,H2] =plotyy(task.s,Ax,task.s,Ay);
% set(get(AX(1),'Ylabel'),'String','Longitudinal acceleration (m/s^2)')
% set(get(AX(2),'Ylabel'),'String','Lateral acceleration (m/s^2)') 
% xlabel('Relative position of the ego vehicle (m)');
% % legend('Longitudinal speed','Lateral speed');
% xlim([0,task.s(end)]);