clc

% x = env_pos.x.Data;
% y = env_pos.y.Data;
% rotz = env_pos.rotz.Data;

% vx = vel.x.Data;
% vy = vel.y.Data;
% vr = vel.rotz.Data;

% vx1 = driv.x.Data;
% vy1 = driv.y.Data;
% vr1 = driv.rotz.Data;

% x = pos.x.Data;
% y = pos.y.Data;
% 
% ax = acc.x.Data;
% ay = acc.y.Data;
% ar = acc.rotz.Data;

% figure(1); clf; hold on
% plot(t, vy);



% figure(3); clf; hold on
% plot(t, env_pos.y.Data);
% plot(t, yref);
% 
% figure(5); clf; hold on;
% plot(xsp(:, 2:2:300)');
% 
figure(6); clf; hold on;
plot(env_pos.x.Data, env_pos.y.Data);
% 
% figure(7); clf; hold on;
% x = env_pos.x.Data;
% y = env_pos.y.Data;
% for k = 1:length(t)
%     
%     clf; hold on;
%     
%     plot(x, y);
%     plot(x(k), y(k), 'o');
%     plot(fcar(k), 2.5, 'o');
%     
%     pause(0.01);
%     
% end



% figure(4); clf; hold on
xv = (1:150)*2.8;

c = rand(30, 3);

% for k = 1:size(simout, 1)
%     
%     
% %     xv = xv + 70/3.6;
%     clf; hold on;
%     plot(xv, simout(k, :), 'Color', c(k, :));
%     plot(xv, xsp(k, 2:2:300), 'Color', c(k, :));
%     plot([0, 20], [y_sampled(k), y_sampled(k)], 'r');
%     plot(xv(10), simout(k, 10), 'ro')
%     pause
%     if k == 1
%         plot((1:150)*2.8, xsp(k, 2:2:300), 'r');
%     else
%         plot((1:150)*2.8, xsp(k, 2:2:300));
%     end
%     
% end


