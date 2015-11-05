function []=plotroad(task,M)

% plot the road
figure(1)
hold on
fill(([0;1;1;0]*M),[0;0;1;1]*task.road.lanewidth*2,0.8*[1 1 1],'EdgeColor',0.7*[1 1 1]);
plot([0,M],task.road.lanewidth*[1 1],'w--','LineWidth',2);
end