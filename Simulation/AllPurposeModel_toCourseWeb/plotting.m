clc


vx = vel.x.Data;
vy = vel.y.Data;
vr = vel.rotz.Data;

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
plot(t(270:2600), y(270:2600));
plot(t(270:2600), yref(270:2600));
xlabel('Time [s]');
ylabel('Absolute lateral position [m]');
title('Absolute lateral position of vehicle over time');
legend('Output', 'Reference')
axis([2.145, 22.56, 1.5, 12]);


figure(2); clf; hold on
for k = 1:57
    
    plot3(1:150, k*ones(1, 150), simout(k, :)');
    % az-el 40-30
end
xlabel('Trajectory sample');
ylabel('MPC iteration');
zlabel('Requested y position');
title('Output trajectories form the MPC algorithm in every step');

figure(3); clf; hold on
plot(t, ydc);
xlabel('Time [s]');
ylabel('Velocity y [m/s]');
title('Velocity in the global y direction');

