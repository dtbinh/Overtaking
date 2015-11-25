function xsp=generateXsp(obstacle,xPos,task,ph,vD)
laneWidth=task.road.lanewidth;
safetyMargin=task.Ego.longsafetymargin;

xsp(2,:)=ones(1,ph)*laneWidth/2;
xsp(1,:)=ones(1,ph)*vD;

for k=1:length(obstacle)
    for i=1:ph
        if abs(xPos(i)-obstacle(k)) < safetyMargin
            xsp(2,i)=3*laneWidth/2;
        end
    end
end

end