function [xsp adj]=generateXsp(xPos,task,ph)

laneWidth=task.road.lanewidth;
safetyMargin=task.Ego.longsafetymargin;
vD=task.Ego.velocity-task.obstacle{1}.velocity;

xsp(2,:)=ones(1,ph)*laneWidth/2;
xsp(1,:)=ones(1,ph)*vD;

for k=1:length(task.obstacle)
    if abs(task.obstacle{k}.position-xPos(1))<10*ph
        for i=1:ph
            if xPos(i)-task.obstacle{k}.position > -task.obstacle{k}.longsafetymarginB && xPos(i)-task.obstacle{k}.position < task.obstacle{k}.longsafetymarginF
                xsp(2,i)=3*laneWidth/2;
            end
        end
    end
end

adj=ones(1,ph)*laneWidth*2;

% for k=1:length(task.adjacent)
%     if abs(task.adjacent{k}.position-xPos(1))<5*ph
%         for i=1:ph
%             if abs(xPos(i)-task.adjacent{k}.position) < 5*task.adjacent{k}.longsafetymargin
%                 adj(i)=laneWidth;
%             end
%         end
%     end
% end

end