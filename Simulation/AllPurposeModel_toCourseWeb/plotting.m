clc

% x = env_pos.x.Data;
% y = env_pos.y.Data;
% rotz = env_pos.rotz.Data;
% 
% ax = acc.x.Data;
% ay = acc.y.Data;
% ar = acc.rotz.Data;
vx = vel.x.Data;
vy = vel.y.Data;
vr = vel.rotz.Data;

% vx1 = driv.x.Data;
% vy1 = driv.y.Data;
% vr1 = driv.rotz.Data;

x = pos.x.Data;
y = pos.y.Data;

figure(1); clf; hold on
subplot(2, 1, 1); hold on
plot([x(1), x(2600)], [2.5, 2.5], '--');
plot(x(1:2600), y(1:2600));
legend('Lane center', 'Vehicle trajectory');
xlabel('Absolute longitudinal position [m]');
ylabel('Absolute lateral position [m]');
title('Absolute position of vehicle in global xy coordinate system');
axis([70, 589.3, 1.5, 12]);

subplot(2, 1, 2); hold on;
% figure(3); clf; hold on
plot(t(270:2600), env_pos.y.Data(270:2600));
plot(t(270:2600), yref(270:2600));
xlabel('Time [s]');
ylabel('Absolute lateral position [m]');
title('Absolute lateral position of vehicle over time');
legend('Output', 'Reference')
axis([2.145, 22.56, 1.5, 12]);

figure(4); clf; hold on
for k = 1:57
    
    plot3(1:150, k*ones(1, 150), simout(k, :)');
    
end
xlabel('Trajectory sample');
ylabel('MPC iteration');
zlabel('MPC output trajectory');
title('');