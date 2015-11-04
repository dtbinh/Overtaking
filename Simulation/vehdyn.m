function dx = vehdyn(z)

m = 1700;    % Mass of the vehicle [kg].
a = 1.5;     % Distance from front axle to COG [m].
b = 1.5;     % Distance from rear axle to COG [m].
Cx = 1.5e5;       % Longitudinal tire stiffness [N].
Cy = 4e4;       % Lateral tire stiffness [N/rad].
CA = 0.5;    % or 0.7, air resistance coefficient [1/m].
J = ((0.5*(a+b))^2)*m;   % Moment of inertia

x1 = z(1);
x2 = z(2);
x3 = z(3);
u1 = z(4);
u2 = z(5);
u3 = z(6);
u4 = z(7);
u5 = z(8);


dx(1) = x2*x3 + 1/m*(   - 2*Cy*( -(x2+a*x3)/x1)*sin(u5) + Cx*(u3+u4) - CA*x1^2);
 
dx(2) = -x1*x3 + 1/m*(  Cx*(u1+u2)*sin(u5) + 2*Cy*(u5-(x2+a*x3)/x1)*cos(u5) + 2*Cy*(b*x3-x2)/x1);

dx(3) = (1/J)*(  a*(  Cx*(u1+u2*sin(u5)+ 2*Cy*(u5 - (x2+a*x3)/x1)*cos(u5)) - 2*b*Cy*(b*x3-x2)/x1));





end