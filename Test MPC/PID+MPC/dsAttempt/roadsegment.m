function r=roadsegment
%ROADSEGMENT  Load parameters for a standard road segment
%
% R = ROADSEGMENT returns a struct R that contains parameters for a
% road segment.

r=struct;
r.numlanes=2;               % number of lanes
r.lanewidth=5;              %[m] lane width
r.speedlimit=70/3.6;        %[m/s] speed limit


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Created by Nikolce Murgovski, 2015-03.