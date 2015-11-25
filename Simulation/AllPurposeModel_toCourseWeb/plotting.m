clc

% x = env_pos.x.Data;
% y = env_pos.y.Data;
% rotz = env_pos.rotz.Data;

vx = vel.x.Data;
vy = vel.y.Data;
vr = vel.rotz.Data;

% vx1 = driv.x.Data;
% vy1 = driv.y.Data;
% vr1 = driv.rotz.Data;

x = pos.x.Data;
y = pos.y.Data;

ax = acc.x.Data;
ay = acc.y.Data;
ar = acc.rotz.Data;

% figure(1); clf; hold on
% plot(t, vy);

load('testPath');

% figure(2); clf; hold on
% plot(x, y);
% plot(path(1, :), path(2, :)-2.5)
% axis equal

% figure(4); clf; hold on
% plot(t, xdc);
% 
figure(3); clf; hold on
plot(t, y);
plot(t, yref);

figure(3); clf; hold on
plot(path(1, :), path(2, :));


% Par.Init.v_x = 20;

