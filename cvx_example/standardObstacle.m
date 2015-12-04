function o=standardObstacle
%STANDARDCAR  Load parameters for a standard car
%
% V = STANDARDCAR returns a struct V that contains parameters for a car.

o=struct;
o.position=0;               %i*vE
o.velocity=60/3.6;               %[m/s] obstacle velocity
o.width=2;                  %[m] obstacle width
o.length=4.5 ;              %[m] obstacle length
o.latsafetymargin=0.5;      %[m] lateral safety margin to surrounding object
o.longsafetymargin=40;       %[m] longitudinal safety margin to surrounding object
o.longsafetymarginF=o.longsafetymargin/2; 
o.longsafetymarginB=o.longsafetymargin/2;
o.timelagfront=1;           %[s] minimum time lag to the vehicle in front
o.timelagrear=0.5;          %[s] minimum time lag to the vehicle behind.
o.timelagrearlane=5;        %[s] minimum time lag to the vehicle behind, after which the vehicle has to be in its own lane.
o.timelagfrontlane=5.5;     %[s] minimum time lag to the vehicle in front, before which the vehicle has to be in its own lane.
o.vxmin=0;                  %[m/s] minimum longitudinal speed
o.vxmax=220/3.6;            %[m/s] maximum longitudinal speed
o.vymin=-4;                 %[m/s] minimum lateral speed
o.vymax=4;                  %[m/s] maximum lateral speed
o.axmin=-4;                 %[m/s2] minimum longitudinal acceleration
o.axmax=1;                  %[m/s2] maximum longitudinal acceleration
o.aymin=-2;                 %[m/s2] minimum lateral acceleration
o.aymax=2;                  %[m/s2] maximum lateral acceleration
o.Daxmin=-15;               %[m/s3] minimum longitudinal jerk
o.Daxmax=7.5;               %[m/s3] maximum longitudinal jerk
o.Daymin=-2.5;              %[m/s3] minimum lateral jerk
o.Daymax=2.5;               %[m/s3] maximum lateral jerk
o.colour='r*';
o.maxslipangle=10*pi/180;   %[rad] max slip angle
o.horizon=2;              %[m] receeding horizon





%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Created by Nikolce Murgovski, 2015-03.

