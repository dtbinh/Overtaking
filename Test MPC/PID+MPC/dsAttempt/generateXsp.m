function xsp=generateXsp(xPos,task,ph,N)
%%
%generateXsp(xPos,task,ph)
%
%xPos = Current position
%ph = prediction horizon
%
%%
    laneWidth=task.road.lanewidth;
    safetyMargin=task.Ego.longsafetymargin;
    vD=task.Ego.velocity-task.obstacle{1}.velocity;

    xsp(2,:)=ones(1,N)*laneWidth/2;
    xsp(1,:)=ones(1,N)*vD;

    for k=1:length(task.obstacle)
        if abs(task.obstacle{k}.position-xPos(1))< ph
            for i=1:N
                if xPos(i)-task.obstacle{k}.position > -task.obstacle{k}.longsafetymarginB && xPos(i)-task.obstacle{k}.position < task.obstacle{k}.longsafetymarginF
                    
                    if task.obstacle{k}.yPosition==laneWidth/2;
                    xsp(2,i)=3*laneWidth/2;
                    elseif task.obstacle{k}.yPosition==3*laneWidth/2;
                    xsp(2,i)=5*laneWidth/2;    
                    end
                end
            end
        end
    end

end