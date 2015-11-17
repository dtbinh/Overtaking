function [out] = PlotPathAndForces(pos_irp3,delta_w4,F_z4,v_xv4,v_yv4,F_xv4,F_yv4, Par, nstep)
%Test: PlotPathAndForces(pos_irp3,delta_w4,F_z4,v_xv4,v_yv4,F_xv4,F_yv4, Par, 24)
%Test: PlotPathAndForces(pos_irp3,delta_w4,F_z4,v_xv4,v_yv4,F_xv4,F_yv4, Par, -2)

if nstep<0, nstep=ceil(sqrt((max(pos_irp3.x.Data)-min(pos_irp3.x.Data))^2+(max(pos_irp3.y.Data)-min(pos_irp3.y.Data))^2)/(-nstep*Par.Veh.L)); end
t_plot=linspace(pos_irp3.x.Time(1),pos_irp3.x.Time(end),nstep);

x_plot  =interp1(pos_irp3.x.Time  ,pos_irp3.x.Data  ,t_plot);
y_plot  =interp1(pos_irp3.y.Time  ,pos_irp3.y.Data  ,t_plot);
p_z_plot=interp1(pos_irp3.rotz.Time,pos_irp3.rotz.Data,t_plot);
F_1z_plot=interp1(F_z4.fl.Time  ,F_z4.fl.Data   ,t_plot);
F_2z_plot=interp1(F_z4.fr.Time  ,F_z4.fr.Data   ,t_plot);
F_3z_plot=interp1(F_z4.rl.Time  ,F_z4.rl.Data   ,t_plot);
F_4z_plot=interp1(F_z4.rr.Time  ,F_z4.rr.Data   ,t_plot);
delta_1w_plot=interp1(delta_w4.fl.Time  ,delta_w4.fl.Data, t_plot);
delta_2w_plot=interp1(delta_w4.fr.Time  ,delta_w4.fr.Data, t_plot);
delta_3w_plot=interp1(delta_w4.rl.Time  ,delta_w4.rl.Data, t_plot);
delta_4w_plot=interp1(delta_w4.rr.Time  ,delta_w4.rr.Data, t_plot);
v_1xv_plot=interp1(v_xv4.fl.Time ,v_xv4.fl.Data, t_plot);
v_2xv_plot=interp1(v_xv4.fr.Time ,v_xv4.fr.Data, t_plot);
v_3xv_plot=interp1(v_xv4.rl.Time ,v_xv4.rl.Data, t_plot);
v_4xv_plot=interp1(v_xv4.rr.Time ,v_xv4.rr.Data, t_plot);
v_1yv_plot=interp1(v_yv4.fl.Time ,v_yv4.fl.Data, t_plot);
v_2yv_plot=interp1(v_yv4.fr.Time ,v_yv4.fr.Data, t_plot);
v_3yv_plot=interp1(v_yv4.rl.Time ,v_yv4.rl.Data, t_plot);
v_4yv_plot=interp1(v_yv4.rr.Time ,v_yv4.rr.Data, t_plot);
F_1xv_plot=interp1(F_xv4.fl.Time ,F_xv4.fl.Data, t_plot);
F_2xv_plot=interp1(F_xv4.fr.Time ,F_xv4.fr.Data, t_plot);
F_3xv_plot=interp1(F_xv4.rl.Time ,F_xv4.rl.Data, t_plot);
F_4xv_plot=interp1(F_xv4.rr.Time ,F_xv4.rr.Data, t_plot);
F_1yv_plot=interp1(F_yv4.fl.Time ,F_yv4.fl.Data, t_plot);
F_2yv_plot=interp1(F_yv4.fr.Time ,F_yv4.fr.Data, t_plot);
F_3yv_plot=interp1(F_yv4.rl.Time ,F_yv4.rl.Data, t_plot);
F_4yv_plot=interp1(F_yv4.rr.Time ,F_yv4.rr.Data, t_plot);


nFC=24; %Number of points in each friction circle
ForceScale=min(abs([Par.Veh.TrackWidth/2,Par.Veh.lf,Par.Veh.lr]))/max([F_1z_plot,F_2z_plot,F_3z_plot,F_4z_plot]); %m/N
VelocityScale=2*min(abs([Par.Veh.TrackWidth/2,Par.Veh.lf,Par.Veh.lr]))/max([v_1xv_plot,v_2xv_plot,v_3xv_plot,v_4xv_plot, v_1yv_plot,v_2yv_plot,v_3yv_plot,v_4yv_plot]); %m/N

for i=1:length(t_plot)
    x_w4=[x_plot+cos(p_z_plot)*Par.Veh.lf-sin(p_z_plot)*(+Par.Veh.TrackWidth/2); ...
          x_plot+cos(p_z_plot)*Par.Veh.lf-sin(p_z_plot)*(-Par.Veh.TrackWidth/2); ...
          x_plot+cos(p_z_plot)*Par.Veh.lr-sin(p_z_plot)*(+Par.Veh.TrackWidth/2); ...
          x_plot+cos(p_z_plot)*Par.Veh.lr-sin(p_z_plot)*(-Par.Veh.TrackWidth/2); ...
          x_plot+cos(p_z_plot)*Par.Veh.lf*1.5];
    y_w4=[y_plot+sin(p_z_plot)*Par.Veh.lf+cos(p_z_plot)*(+Par.Veh.TrackWidth/2); ...
          y_plot+sin(p_z_plot)*Par.Veh.lf+cos(p_z_plot)*(-Par.Veh.TrackWidth/2); ...
          y_plot+sin(p_z_plot)*Par.Veh.lr+cos(p_z_plot)*(+Par.Veh.TrackWidth/2); ...
          y_plot+sin(p_z_plot)*Par.Veh.lr+cos(p_z_plot)*(-Par.Veh.TrackWidth/2); ...
          y_plot+sin(p_z_plot)*Par.Veh.lf*1.5];
      
      [x_1FrictionCircle,y_1FrictionCircle]=pol2cart(linspace(0,2*pi,nFC)'*ones(1,nstep), ForceScale*ones(nFC,1)*F_1z_plot);
      [x_2FrictionCircle,y_2FrictionCircle]=pol2cart(linspace(0,2*pi,nFC)'*ones(1,nstep), ForceScale*ones(nFC,1)*F_2z_plot);
      [x_3FrictionCircle,y_3FrictionCircle]=pol2cart(linspace(0,2*pi,nFC)'*ones(1,nstep), ForceScale*ones(nFC,1)*F_3z_plot);
      [x_4FrictionCircle,y_4FrictionCircle]=pol2cart(linspace(0,2*pi,nFC)'*ones(1,nstep), ForceScale*ones(nFC,1)*F_4z_plot);
      x_1FrictionCircle=ones(nFC,1)*x_w4(1,:)+x_1FrictionCircle;
      x_2FrictionCircle=ones(nFC,1)*x_w4(2,:)+x_2FrictionCircle;
      x_3FrictionCircle=ones(nFC,1)*x_w4(3,:)+x_3FrictionCircle;
      x_4FrictionCircle=ones(nFC,1)*x_w4(4,:)+x_4FrictionCircle;
      y_1FrictionCircle=ones(nFC,1)*y_w4(1,:)+y_1FrictionCircle;
      y_2FrictionCircle=ones(nFC,1)*y_w4(2,:)+y_2FrictionCircle;
      y_3FrictionCircle=ones(nFC,1)*y_w4(3,:)+y_3FrictionCircle;
      y_4FrictionCircle=ones(nFC,1)*y_w4(4,:)+y_4FrictionCircle;
      
      [x_1Ste,y_1Ste]=pol2cart([p_z_plot+delta_1w_plot;p_z_plot+delta_1w_plot+pi], Par.Veh.Rw*ones(2,nstep));
      [x_2Ste,y_2Ste]=pol2cart([p_z_plot+delta_2w_plot;p_z_plot+delta_2w_plot+pi], Par.Veh.Rw*ones(2,nstep));
      [x_3Ste,y_3Ste]=pol2cart([p_z_plot+delta_3w_plot;p_z_plot+delta_3w_plot+pi], Par.Veh.Rw*ones(2,nstep));
      [x_4Ste,y_4Ste]=pol2cart([p_z_plot+delta_4w_plot;p_z_plot+delta_4w_plot+pi], Par.Veh.Rw*ones(2,nstep));
      x_1Ste=ones(2,1)*x_w4(1,:)+x_1Ste;
      x_2Ste=ones(2,1)*x_w4(2,:)+x_2Ste;
      x_3Ste=ones(2,1)*x_w4(3,:)+x_3Ste;
      x_4Ste=ones(2,1)*x_w4(4,:)+x_4Ste;
      y_1Ste=ones(2,1)*y_w4(1,:)+y_1Ste;
      y_2Ste=ones(2,1)*y_w4(2,:)+y_2Ste;
      y_3Ste=ones(2,1)*y_w4(3,:)+y_3Ste;
      y_4Ste=ones(2,1)*y_w4(4,:)+y_4Ste;
  
      [x_1Vel,y_1Vel]=pol2cart(p_z_plot+atan2(v_1yv_plot,v_1xv_plot), VelocityScale*sqrt(v_1yv_plot.^2+v_1xv_plot.^2));
      [x_2Vel,y_2Vel]=pol2cart(p_z_plot+atan2(v_2yv_plot,v_2xv_plot), VelocityScale*sqrt(v_2yv_plot.^2+v_2xv_plot.^2));
      [x_3Vel,y_3Vel]=pol2cart(p_z_plot+atan2(v_3yv_plot,v_3xv_plot), VelocityScale*sqrt(v_3yv_plot.^2+v_3xv_plot.^2));
      [x_4Vel,y_4Vel]=pol2cart(p_z_plot+atan2(v_4yv_plot,v_4xv_plot), VelocityScale*sqrt(v_4yv_plot.^2+v_4xv_plot.^2));
      x_1Vel=ones(2,1)*x_w4(1,:)+[zeros(1,nstep);x_1Vel];
      x_2Vel=ones(2,1)*x_w4(2,:)+[zeros(1,nstep);x_2Vel];
      x_3Vel=ones(2,1)*x_w4(3,:)+[zeros(1,nstep);x_3Vel];
      x_4Vel=ones(2,1)*x_w4(4,:)+[zeros(1,nstep);x_4Vel];
      y_1Vel=ones(2,1)*y_w4(1,:)+[zeros(1,nstep);y_1Vel];
      y_2Vel=ones(2,1)*y_w4(2,:)+[zeros(1,nstep);y_2Vel];
      y_3Vel=ones(2,1)*y_w4(3,:)+[zeros(1,nstep);y_3Vel];
      y_4Vel=ones(2,1)*y_w4(4,:)+[zeros(1,nstep);y_4Vel];

      [x_1Force,y_1Force]=pol2cart(p_z_plot+atan2(F_1yv_plot,F_1xv_plot), ForceScale*sqrt(F_1yv_plot.^2+F_1xv_plot.^2));
      [x_2Force,y_2Force]=pol2cart(p_z_plot+atan2(F_2yv_plot,F_2xv_plot), ForceScale*sqrt(F_2yv_plot.^2+F_2xv_plot.^2));
      [x_3Force,y_3Force]=pol2cart(p_z_plot+atan2(F_3yv_plot,F_3xv_plot), ForceScale*sqrt(F_3yv_plot.^2+F_3xv_plot.^2));
      [x_4Force,y_4Force]=pol2cart(p_z_plot+atan2(F_4yv_plot,F_4xv_plot), ForceScale*sqrt(F_4yv_plot.^2+F_4xv_plot.^2));
      x_1Force=ones(2,1)*x_w4(1,:)+[zeros(1,nstep);x_1Force];
      x_2Force=ones(2,1)*x_w4(2,:)+[zeros(1,nstep);x_2Force];
      x_3Force=ones(2,1)*x_w4(3,:)+[zeros(1,nstep);x_3Force];
      x_4Force=ones(2,1)*x_w4(4,:)+[zeros(1,nstep);x_4Force];
      y_1Force=ones(2,1)*y_w4(1,:)+[zeros(1,nstep);y_1Force];
      y_2Force=ones(2,1)*y_w4(2,:)+[zeros(1,nstep);y_2Force];
      y_3Force=ones(2,1)*y_w4(3,:)+[zeros(1,nstep);y_3Force];
      y_4Force=ones(2,1)*y_w4(4,:)+[zeros(1,nstep);y_4Force];
end

figure(1), clf %figure('Name','Path plot')
for i=1:length(t_plot)  
    patch(x_w4([1 5 2 4 3],:),y_w4([1 5 2 4 3],:),'w'); hold on
    
    patch(x_1FrictionCircle,y_1FrictionCircle,'y'); 
    patch(x_2FrictionCircle,y_2FrictionCircle,'y');
    patch(x_3FrictionCircle,y_3FrictionCircle,'y');
    patch(x_4FrictionCircle,y_4FrictionCircle,'y');
    
    plot(x_1Ste,y_1Ste,'k','LineWidth',2);
    plot(x_2Ste,y_2Ste,'k','LineWidth',2);
    plot(x_3Ste,y_3Ste,'k','LineWidth',2);
    plot(x_4Ste,y_4Ste,'k','LineWidth',2);
    
    plot(x_1Vel,y_1Vel,'g');
    plot(x_2Vel,y_2Vel,'g');
    plot(x_3Vel,y_3Vel,'g');
    plot(x_4Vel,y_4Vel,'g');
    
    plot(x_1Force,y_1Force,'b','LineWidth',2);
    plot(x_2Force,y_2Force,'b','LineWidth',2);
    plot(x_3Force,y_3Force,'b','LineWidth',2);
    plot(x_4Force,y_4Force,'b','LineWidth',2);
end
plot(x_plot,y_plot,'o');
plot(pos_irp3.x.Data,pos_irp3.y.Data,'-')
plot(pos_irp3.x.Data,pos_irp3.x.Time,'m:')
plot(pos_irp3.x.Time,pos_irp3.y.Data,'m:')

plot(Par.Env.left1.x,Par.Env.left1.y,'r^','LineWidth',2)
plot(Par.Env.left2.x,Par.Env.left2.y,'r^','LineWidth',2)
plot(Par.Env.right1.x,Par.Env.right1.y,'g^','LineWidth',2)
plot(Par.Env.right2.x,Par.Env.right2.y,'g^','LineWidth',2)
plot(Par.Env.right3.x,Par.Env.right3.y,'g^','LineWidth',2)
grid on;  axis equal; %axis image;
hold off;









