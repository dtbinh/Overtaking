function xsp = generateXsp(relPos)


vD = 2.8;  % relative velocity

ph = 150;

laneWidth = 5; % task.road.lanewidth;
safetyMargin = 20; % task.Ego.longsafetymargin;

xsp(2,:) = ones(1,ph)*laneWidth/2;
xsp(1,:) = ones(1,ph)*vD;
% xRel = (ph:-1:1)*vD - relPos;
% xRel = (1:ph)*vD - relPos*vD;
xRel = (-ph/2:ph/2)*vD - relPos;


for i=1:ph

    if abs(xRel(i)) < safetyMargin
        xsp(2,i)=3*laneWidth/2;
    end
end


end