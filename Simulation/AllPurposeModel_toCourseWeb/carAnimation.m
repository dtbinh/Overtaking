clc, close all

car = [-2.3, 2.3, 2.3, -2.3, -2.3;
       -1.35,   -1.35,  1.35,    1.35    -1.35];
   
h = figure(1); clf; hold on;
x = env_pos.x.Data;
y = env_pos.y.Data;
r = env_pos.rotz.Data;
h.Position = [1, 686, 1415, 119];
dt = diff(t);

for k = 1:(length(t)-101)
    
    clf; hold on;
    
    plotCar(x(k), y(k), r(k), 0, car);
    plotCar(fcar(k), 2.5, 0, 0, car);
    
    plot(x(k:(k+300)), y(k:(k+300)));
    plot(x(k:(k+300)), yref(k:(k+300)));
    axis([x(k)-10, x(k)+100, 0, 11.5]);
%     pause(0.001);
    pause(dt(k));
    
end


