function xsp=generateXsp(obstacle,oncoming,xPos,task,ph,vD)
laneWidth=task.road.lanewidth;
safetyMargin=task.Ego.longsafetymargin;
minDist=safetyMargin;

xsp(2,:)=ones(1,ph)*laneWidth/2;
xsp(1,:)=ones(1,ph)*vD;
dist=[minDist+1 diff(obstacle)];
for k=1:length(obstacle)
    for i=1:ph
        if abs(xPos(i)-obstacle(k)) < safetyMargin 
            xsp(2,i)=3*laneWidth/2;
        end
        
    end
end

    if xsp(2,1)==3*laneWidth/2 && xsp(2,ceil(1+minDist))==3*laneWidth/2 
        
        xsp(2,1:ceil(1+minDist))=3*laneWidth/2;
    end

end