function profile=setProfile(prof)
%%
% To set profiles, choose the following letters:
% Comfortable = C
% Agressive = A
% Normal = N
% Autobahn = B
%
% N is used as standard
%%
profile=struct;
if nargin == 0
    prof='N';
end
% Set profile
if prof=='N'
    disp('Normal driving mode selected')
    pause(0.5)
    profile.qx_ref = [10 0;0 10];
    profile.qax = 200;
    profile.qvy = 400;
    profile.qjx = 100;
    profile.qay = 300;
end

if prof == 'A'
    disp('Agressive driving mode selected')
    pause(0.5)
    profile.qx_ref = [1 0;0 70];
    profile.qax = 20;
    profile.qvy = 400;
    profile.qjx = 100;
    profile.qay = 300;
end

if prof=='C'
    disp('Comfortable driving mode selected')
    pause(0.5)
    profile.qx_ref = [1 0;0 0.005];
    profile.qax = 0;
    profile.qvy = 10;
    profile.qjx = 10;
    profile.qay = 1000;
end

if prof=='B'
    disp('"Autobahn" driving mode selected')
    pause(0.5)
    profile.qx_ref = [1 0;0 1e-5];
    profile.qax = 0;
    profile.qvy = 1;
    profile.qjx = 0;
    profile.qay = 1000;
end
end