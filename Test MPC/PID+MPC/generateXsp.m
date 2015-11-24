function xsp=generateXsp(obstacle,xPos,task,ph,vE)
laneWidth=task.road.lanewidth;
safetyMargin=task.Ego.longsafetymargin;

for i=1:ph
    xsp(2,i)=laneWidth/2;
    xsp(1,i)=vE;
    if abs(xPos(i)-obstacle) < safetyMargin*100
        xsp(2,i)=3*laneWidth/2;
    end

end
end