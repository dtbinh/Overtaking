clc, clear

m = 1700;    % Mass of the vehicle [kg].
a = 1.5;     % Distance from front axle to COG [m].
b = 1.5;     % Distance from rear axle to COG [m].
Cx = 1.5e5;       % Longitudinal tire stiffness [N].   
Cy = 4e4;       % Lateral tire stiffness [N/rad].
CA = 0.5;    % or 0.7, air resistance coefficient [1/m].
J = ((0.5*(a+b))^2)*m;   % Moment of inertia

%%


plot(xc, yc)