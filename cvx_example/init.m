% Initialise data
%% sampling interval
% task.N=round(task.E.horizon/(task.road.speedlimit-task.L.vx)/0.2);  % number of samples
task.s=linspace(0,task.E.horizon,task.N)';                          %[m] relative distance vector
task.ds=task.s(2)-task.s(1);                                        %[m] sampling interval
vrmean=mean(task.E.vref);

%% Critical zones
task.L.lf=(task.L.length+task.E.length)/2+task.E.longsafetymargin ...
    +task.E.timelagfront*(vrmean-task.L.vx);
task.L.lr=(task.L.length+task.E.length)/2+task.E.longsafetymargin ...
    +task.E.timelagrear*(vrmean-task.L.vx);
task.L.lflane=(task.L.length+task.E.length)/2+task.E.longsafetymargin ...
    +task.E.timelagfrontlane*(vrmean-task.L.vx);
task.L.lrlane=(task.L.length+task.E.length)/2+task.E.longsafetymargin ...
    +task.E.timelagrearlane*(vrmean-task.L.vx);

if task.oncomingveh
    task.O.lf=(task.O.length+task.E.length)/2+task.E.longsafetymargin ...
        +task.E.timelagfront*(vrmean+task.O.vx);
end
if task.adjacentveh
    task.A.lr=(task.A.length+task.E.length)/2+task.E.longsafetymargin ...
        +task.E.timelagrear*abs(task.A.vx-vrmean);
end

% maximum lateral limit
task.ymax=2*task.road.lanewidth*ones(task.N,1)-task.E.width/2-task.E.latsafetymargin;
task.ixov=task.s >= task.L.x0-task.L.lflane & task.s <= task.L.x0+task.L.lrlane; %samples in overtaking window
task.ymax(~task.ixov)=task.road.lanewidth-task.E.width/2-task.E.latsafetymargin;

% minimum lateral limit
task.zone.w=task.road.lanewidth+task.E.width/2+task.E.latsafetymargin;  %[m] width of the critical zone
task.ymin=(task.E.width/2+task.E.latsafetymargin)*ones(task.N,1);       %[m] minimum lateral position
ixz=task.s >= task.L.x0-task.L.lf & task.s <= task.L.x0+task.L.lr;      %samples in critical zone
task.ymin(ixz)=task.zone.w;

% reference lateral position
task.E.yref=0.5*task.road.lanewidth*ones(task.N,1);   
task.E.yref(ixz)=1.5*task.road.lanewidth;           %in the middle of adjacent lane within the critical zone






%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Created by Nikolce Murgovski, 2015-03.