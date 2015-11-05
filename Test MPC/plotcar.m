function []=plotcar(pos1,pos2)

% plot the road
figure(1)
hold on
plot(pos1,pos2,'r*')
%rectangle('Position', [pos1 pos2-task.road.lanewidth/4 20 task.road.lanewidth/2])
end