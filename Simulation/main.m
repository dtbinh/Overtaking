clc, clear

m = 1700;    % Mass of the vehicle [kg].
a = 1.5;     % Distance from front axle to COG [m].
b = 1.5;     % Distance from rear axle to COG [m].
Cx = 1.5e5;       % Longitudinal tire stiffness [N].   
Cy = 4e4;       % Lateral tire stiffness [N/rad].
CA = 0.5;    % or 0.7, air resistance coefficient [1/m].
J = ((0.5*(a+b))^2)*m;   % Moment of inertia

%%

% figure(1); clf; hold on;
plot(xc, yc)
% plot(t, x)
% plot(t, delta)


%%
minx = min(xc);
maxx = max(xc);
miny = min(yc);
maxy = max(yc);
figure(1); clf; hold on;

for k = 400:length(t)

    s1 = subplot(2, 2, 1);
    cla(s1); hold on;
    plot(xc, yc);
    plotCar(xc(k), yc(k), phi(k), delta(k));
    axis([minx-5, maxx+5, miny-5, maxy+5]);
    
    s2 = subplot(2, 2, 2);
    cla(s2); hold on;
    plot(xc, yc);
    plotCar(xc(k), yc(k), phi(k), delta(k));
    axis([xc(k)-5, xc(k)+5, yc(k)-5, yc(k)+5]);
    axis equal
    
%     s3 = subplot(2, 2, 3);
%     cla(s3); hold on;
%     plot(t, delta);
%     plot(t, phi);
%     
%     scatter(t(k), delta(k), 'ro');
%     scatter(t(k), phi(k), 'bo');
%     legend('Steering angle', 'Angle');
    
    pause(0.01);
    
end


