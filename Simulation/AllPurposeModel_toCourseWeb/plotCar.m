function plotCar(x, y, phi, delta, car)



ct = cos(phi);
st = sin(phi);

R = [ct, -st; st, ct];

rot = R*car;

td = phi+delta;

% ct = cos(-phi);
% st = sin(-phi);

xtheta = 3*ct;
ytheta = 3*st;

xtd = 3*cos(td);
ytd = 3*sin(td);

plot(x + rot(1, :), y+rot(2, :));
plot([x, x+xtheta], [y, y+ytheta], 'r');
plot([x, x+xtd], [y, y+ytd], 'b');


end