clear all;

%%% Bus formats:
open_system('AllPurposeModel_TyreRelaxation_CreateBusFormats')
dummy = Simulink.Bus.createObject('AllPurposeModel_TyreRelaxation_CreateBusFormats', 'AllPurposeModel_TyreRelaxation_CreateBusFormats/BusCreator_irp_vec3');
dummy = Simulink.Bus.createObject('AllPurposeModel_TyreRelaxation_CreateBusFormats', 'AllPurposeModel_TyreRelaxation_CreateBusFormats/BusCreator_oorp_vec3');
dummy = Simulink.Bus.createObject('AllPurposeModel_TyreRelaxation_CreateBusFormats', 'AllPurposeModel_TyreRelaxation_CreateBusFormats/BusCreator_whl_vec4');
dummy = Simulink.Bus.createObject('AllPurposeModel_TyreRelaxation_CreateBusFormats', 'AllPurposeModel_TyreRelaxation_CreateBusFormats/BusCreator_obst_vec2');
close_system('AllPurposeModel_TyreRelaxation_CreateBusFormats')

% open_system('AllPurposeModel_TyreRelaxation')

%%% Parameters
%%% %%% Environment
Par.Env.g=9.80665;

Par.Env.left1.x=150; %x-coordinate of Obstacle to have on left side, number 1
Par.Env.left1.y=0;  %y-coordinate of Obstacle to have on left side, number 1
Par.Env.right1.x=170; %x coordinate of Obstacle to have on right side, number 1
Par.Env.right1.y=3;
Par.Env.right2.x=190; %x coordinate of Obstacle to have on left side, number 2
Par.Env.right2.y=3;
Par.Env.left2.x=210; %x coordinate of Obstacle to have on right side, number 2
Par.Env.left2.y=0;
Par.Env.right3.x=215; %x coordinate of Obstacle to have on right side, number 3
Par.Env.right3.y=0;

Par.Env.mu=1;

%%% %%% Vehicle
Par.Veh.m=1700; %total, sprung + unsprung
Par.Veh.Jz=3000; %total, sprung + unsprung

Par.Veh.m_sprung=300; %only sprung
Par.Veh.Jx_sprung=1000; %only sprung 
Par.Veh.Jy_sprung=3000; %only sprung 

Par.Veh.lf=1.25;
Par.Veh.lr=-1.75;
Par.Veh.L=Par.Veh.lf-Par.Veh.lr;
Par.Veh.TrackWidth=1.7;
Par.Veh.h=0.5;
Par.Veh.HalfRohACd=0.5*1*(2*1)*0.3;
Par.Veh.F_z4_static=Par.Veh.m*Par.Env.g*[-Par.Veh.lr*[0.5 0.5], +Par.Veh.lf*[0.5 0.5]]/Par.Veh.L;

Par.Veh.Rw=0.3;

%%% %%% %%% Suspension geometry
Par.Veh.r_long.fl=[-1; Par.Veh.TrackWidth/2; 0.1];
Par.Veh.r_long.fr=[1; -1; 1].*Par.Veh.r_long.fl;
Par.Veh.r_long.rl=[0.5; Par.Veh.TrackWidth/2; 0.1];
Par.Veh.r_long.rr=[1; -1; 1].*Par.Veh.r_long.rl;

Par.Veh.r_lat.fl=[0; -2; 0.2];
Par.Veh.r_lat.fr=[1; -1; 1].*Par.Veh.r_lat.fl;
Par.Veh.r_lat.rl=[0; -2; 0.4];
Par.Veh.r_lat.rr=[1; -1; 1].*Par.Veh.r_lat.rl;

Par.Veh.r_lever.fl=-Par.Veh.r_long.fl;
Par.Veh.r_lever.fr=-Par.Veh.r_long.fr;
Par.Veh.r_lever.rl=-Par.Veh.r_long.rl;
Par.Veh.r_lever.rr=-Par.Veh.r_long.rr;

Par.Veh.r_pivot.fl=Par.Veh.r_lat.fl-Par.Veh.r_long.fl;
Par.Veh.r_pivot.fr=Par.Veh.r_lat.fr-Par.Veh.r_long.fr;
Par.Veh.r_pivot.rl=Par.Veh.r_lat.rl-Par.Veh.r_long.rl;
Par.Veh.r_pivot.rr=Par.Veh.r_lat.rr-Par.Veh.r_long.rr;

% Par.Veh.hf=0.3; %0.2;
% Par.Veh.hr=0.3; %0.4;
% Par.Veh.ff=1;
% Par.Veh.fr=2;

%%% %%% %%% Suspension stiffness & damping
Par.Veh.cw=35000;
Par.Veh.carb_f=8000; %N/m, anti-roll-bar, front
Par.Veh.carb_r=6000; %N/m, anti-roll-bar, rear
Par.Veh.dw=3000;
%Par.Veh.ct=350000;
%Par.Veh.dt=30000;

Par.Veh.Jw=0.5;
Par.Veh.C0=15;
Par.Veh.RelaxLength=2*pi*Par.Veh.Rw*0.5;
Par.Veh.RRC=0.01;

Par.Veh.Pmax=100e3;
Par.Veh.PropDistrFrnt=1;
Par.Veh.BrkDistrFrnt=0.7;
Par.Veh.SteRatio=15;

%%% %%% Driver
Par.Drvr.v_set=20;

%%%Initial Values
Par.Init.v_x=20;
Par.Init.F_fz=Par.Veh.m*9.80665*(-Par.Veh.lr/Par.Veh.L);
Par.Init.F_rz=Par.Veh.m*9.80665*(+Par.Veh.lf/Par.Veh.L);

y0 = 2.5;
tp = 1; % MPC trigger period
tip = tp/10;    %Interpolator trigger period