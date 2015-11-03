function res=cvxsolveprob(task)

ds=task.ds; N=task.N; yr=task.E.yref; road=task.road;
vL=task.L.vx; vr=task.E.vref-vL; vrmean=mean(vr);
slip=tan(task.E.maxslipangle);

%% Scaling factors
Sy=max(task.ymax); Sdy=task.E.vymax/vrmean/2; Sddy=task.E.aymax/vrmean^2; 
Sv=task.E.vxmax-vL; Sdv=task.E.axmax/vrmean^2; Sddv=2e-2;
Scost=10*vrmean; 
St=task.s(end)/vrmean*1.5;

%% Penalties
Wy=1; Wdy=2; Wddy=2; Wv=0.1; Wdv=0.5; Wddv=0.5;
% rescale penalties
Wy=Wy/vrmean; Wv=Wv/vrmean;
Wdy=Wdy*vrmean; Wddy=Wddy*vrmean^3; Wdv=Wdv*vrmean; Wddv=Wddv*vrmean^3;

Wv=0.01; Wy=0.1; Wdv=2; Wdy=20; Wddv=100; Wddy=400;

%% CVX
cvx_clear;
cvx_precision low;         
cvx_solver sedumi;          % in case of numerical problems, try using sdpt3.
% cvx_solver ecos;   
cvx_quiet(true);
cvx_tic;
cvx_begin
    variables y(N) v(N);  
    expressions cost dy(N-1) ddy(N-2) dv(N-1) ddv(N-2);
    if task.adjacentveh || task.oncomingveh
        variables t(N);
    else 
        t=zeros(N,1);
    end
    
    dy = (y(2:N)-y(1:N-1))/ds*Sy/Sdy;              % dy/ds
    ddy= (dy(2:N-1)-dy(1:N-2))/ds*Sdy/Sddy;        % d^2y/ds^2
    dv = (v(2:N)-v(1:N-1))/ds*Sv/Sdv;              % dv/ds
    ddv= (dv(2:N-1)-dv(1:N-2))/ds*Sdv/Sddv;        % d^2v/ds^2
    
    cost = (sum_square(y*Sy-yr)*Wy + sum_square(dy)*Wdy*Sdy^2 ...
        + sum_square(ddy)*Wddy*Sddy^2 + sum_square(ddv)*Wddv*Sddv^2 ...
        + sum_square(v*Sv - vr)*Wv + sum_square(dv)*Wdv*Sdv^2)*ds/Scost;
    
    minimize cost;
    subject to
    
    y >= task.ymin/Sy;
    y <= task.ymax/Sy;
    v >= 0;
    v <= (task.E.vxmax - vL)/Sv;
    dv >= task.E.axmin./vr(1:N-1).*(2-v(1:N-1)./vr(1:N-1)*Sv)/Sdv;
    dv <= task.E.axmax./vr(1:N-1).*(2-v(1:N-1)./vr(1:N-1)*Sv)/Sdv;
    dy >= -slip*(1 + vL./vr(1:N-1).*(2-v(1:N-1)./vr(1:N-1)*Sv))/Sdy;
    dy <=  slip*(1 + vL./vr(1:N-1).*(2-v(1:N-1)./vr(1:N-1)*Sv))/Sdy;
    v(1) == (task.E.vx0 - vL)/Sv;
    y(1) == task.E.y0/Sy;
    y(N) == task.E.y0/Sy;
    dy(1) == 0/Sdy;  
    dv(1) == 0/Sdv;
    
    if task.adjacentveh || task.oncomingveh
        t(2:N) - t(1:N-1) >=  inv_pos(v(1:N-1))*ds/Sv/St;
        t(1) == 0;
    end
    if task.oncomingveh
        y(task.ixov) <= (task.O.y0 - road.lanewidth ...
            -road.lanewidth/task.O.lf*(task.s(task.ixov)-task.O.x0 + (vL+task.O.vx)*t(task.ixov)*St))/Sy;
    end
    if task.adjacentveh
        y(task.ixov) <= (task.A.y0 - road.lanewidth + ...
            road.lanewidth/task.A.lr*(task.s(task.ixov)-task.A.x0 + (vL-task.A.vx)*t(task.ixov)*St))/Sy;
    end
cvx_end

res=struct;
res.time=cvx_toc;
res.status=cvx_status;
res.cost=cost;
res.yE=y*Sy;                                %[m] lateral position
res.vEx=v*Sv + vL;                          %[m/s] longitudinal speed
res.vEy=[dy; dy(N-1)]*Sdy.*(res.vEx-vL);    %[m/s] lateral speed
res.ts=ds./(res.vEx-vL);                    %[s] time samples
res.t=[0;cumsum(res.ts(1:N-1))];            %[s] travel time
res.xE=task.s + vL*res.t;                   %[m] longitudinal position
res.topt=t*St;

