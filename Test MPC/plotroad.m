function []=plotroad(task,S,M)


% plot the road
figure(1)
hold on
fill(([S;M;M;S]),[0;0;1;1]*task.road.lanewidth*2,0.8*[1 1 1],'EdgeColor',0.7*[1 1 1]);
plot([S,M],task.road.lanewidth*[1 1],'w--','LineWidth',2);
axis([S M 0 task.road.lanewidth*2])
end