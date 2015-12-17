function []=plotroad(task,S,M,lanes)
%%
%plotroad(task,S,M,lanes)
%
%S = start of roadsegment
%M = end of roadsegment
%lanes = Number of lanes
%
%%


% plot the road
figure(1)
hold on
fill(([S;M;M;S]),[0;0;1;1]*task.road.lanewidth*(lanes),0.6*[1 1 1],'EdgeColor',0.5*[1 1 1]);
if lanes==2
    plot([S,M],task.road.lanewidth*[1 1],'w--','LineWidth',2);
    axis([S M 0 task.road.lanewidth*2])
    
elseif lanes==3
    plot([S,M],task.road.lanewidth*[1 1],'w--','LineWidth',2);
    plot([S,M],2*task.road.lanewidth*[1 1],'w--','LineWidth',2);
    axis([S M 0 task.road.lanewidth*3])
end
end