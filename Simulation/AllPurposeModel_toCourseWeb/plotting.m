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

x = env_pos.x.Data;
y = env_pos.y.Data;

ax = acc.x.Data;
ay = acc.y.Data;
ar = acc.rotz.Data;

% figure(1); clf; hold on
% plot(t, vy);


figure(2); clf; hold on
plot(x, y);
% plot(t, ar);
% 
% figure(3); clf; hold on
% plot(t, rotz);
% plot(t, vr);





