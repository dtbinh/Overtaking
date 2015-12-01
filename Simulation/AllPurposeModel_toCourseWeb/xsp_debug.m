clc, clear
relPos = 30;

vD = 2.8;  % relative velocity

ph = 150;

laneWidth = 5; % task.road.lanewidth;
safetyMargin = 20; % task.Ego.longsafetymargin;

xsp(2,:) = ones(1,ph)*laneWidth/2;
xsp(1,:) = ones(1,ph)*vD;
xRel = (1:ph)*vD - relPos*vD;
% xRel = (-ph/2:ph/2)*vD - relPos*vD;

% xsp(2, ) = 3*laneWidth/2;
for i=1:ph

    if abs(xRel(i)) < safetyMargin
        xsp(2,i)=3*laneWidth/2;
    end
end

figure(1); clf; hold on;
plot(xsp(2, :));
stem([relPos, relPos], [2.5, 7.5]);

% figure(2); clf; hold on;
% plot(xRel)

