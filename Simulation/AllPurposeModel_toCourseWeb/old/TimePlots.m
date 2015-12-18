%TimePlots

figure(2), clf 

subplot(3,1,1),plot(drvr_op4.APed.Time,[drvr_op4.APed.Data -drvr_op4.BPed.Data 0.01*(180/pi)*drvr_op4.SteWhlAn.Data drvr_op4.LongDir.Data],'Linewidth',2)
axis([0 max(drvr_op4.APed.Time) -1.1 1.1]), grid on,
legend('APed /[0..1]','-BPed /[0..-1]','0.01*[SteWhlAn /[deg]]','Longitudinal Direction request','Location', 'Best') 


subplot(3,1,[2,3]),plot(v_irp3.x.Time, [v_irp3.x.Data atan2d(v_irp3.y.Data,v_irp3.x.Data) (180/pi)*v_irp3.rotz.Data a_irp3.y.Data],'Linewidth',2)
legend('v_x /[m/s]','beta /[deg]','w_z /[deg/s]','a_y /[m/(s*s)]','Location', 'Best'), grid on
xlabel('t /[s]')


figure(3), clf 
subplot(3,1,1),plot(s_x4.fl.Time,s_x4.fl.Data,'b-','Linewidth',2), hold on
subplot(3,1,1),plot(s_x4.fl.Time,s_x4.fr.Data,'g--','Linewidth',2)
subplot(3,1,1),plot(s_x4.fl.Time,s_x4.rl.Data,'r-','Linewidth',2)
subplot(3,1,1),plot(s_x4.fl.Time,s_x4.rr.Data,'c--','Linewidth',2)
legend('fl','fr','rl','rr','Location', 'Best'), grid on, hold off
ylabel('s_x /[1=(m/s)/(m/s)]')
axis([0 s_x4.fl.Time(end) -0.2 0.3])

subplot(3,1,2),plot(s_x4.fl.Time,s_y4.fl.Data,'b-','Linewidth',2), hold on
subplot(3,1,2),plot(s_x4.fl.Time,s_y4.fr.Data,'g--','Linewidth',2)
subplot(3,1,2),plot(s_x4.fl.Time,s_y4.rl.Data,'r-','Linewidth',2)
subplot(3,1,2),plot(s_x4.fl.Time,s_y4.rr.Data,'c--','Linewidth',2)
grid on, ylabel('s_y /[1=(m/s)/(m/s)]')
axis([0 s_x4.fl.Time(end) -0.3 0.3])

subplot(3,1,3),plot(s_y4.fl.Time,F_z4.fl.Data,'b-','Linewidth',2), hold on
subplot(3,1,3),plot(s_y4.fl.Time,F_z4.fr.Data,'g--','Linewidth',2)
subplot(3,1,3),plot(s_y4.fl.Time,F_z4.rl.Data,'r-','Linewidth',2)
subplot(3,1,3),plot(s_y4.fl.Time,F_z4.rr.Data,'c--','Linewidth',2)
grid on, ylabel('F_z /[N]')
xlabel('t /[s]'), axis([0 s_x4.fl.Time(end) 0 8000])




figure(4), clf 
plot(aim_rel.x.Time, sqrt(aim_rel.x.Data.^2+aim_rel.y.Data.^2),'b-','Linewidth',2), hold on
plot(aim_rel.x.Time, atan2d(aim_rel.y.Data, aim_rel.x.Data),'g-','Linewidth',2)
legend('dist_{aim,rel} /[m]','angle_{aim,rel} /[deg]'), grid on, hold off
% plot(aim_rel.x.Time, aim_rel.x.Data,'b-','Linewidth',2), hold on
% plot(aim_rel.x.Time, aim_rel.y.Data,'g-','Linewidth',2)
% legend('aim_{rel.x} /[m]','aim_{rel.y} /[m]'), grid on, hold off
xlabel('t /[s]')

