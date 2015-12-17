function obstacle=generateObstacle(p,M,task,lanes,c)

%%
%generateObstacle(p,M,task,lanes,c)
%p = posibility of obstacle (0.001-0.01 is appropiate)
%M = Simulation time
%lanes = Nr of Lanes
%c = 1 is a overtaking with adjacent, empty is
%random
%%
n=0;
temp=standardObstacle;
vL=temp.velocity;
if lanes==2
    pp1=0;
elseif lanes==3
    pp1=0.3;
end

t=0;
obstacle={};

vD=task.Ego.velocity-vL;
if nargin < 4
    disp('Too few arguments')
    return;
    
elseif nargin==4
    for i=20:M-20
        if rand < p && i-t>20
            n=n+1;
            t=i;
            if rand > pp1
                obstacle{n}=standardObstacle;
                obstacle{n}.position=i*vD;
            else
                obstacle{n}=standardObstacle;
                obstacle{n}.position=i*vD;
                obstacle{n}.yPosition=3*task.road.lanewidth/2;
                
            end
        end
    end
    
    if length(obstacle)<2
        obstacle{1}=standardObstacle;
        obstacle{1}.position=M/2*vD/2;
        obstacle{2}=standardObstacle;
        obstacle{2}.position=M/3*vD/2;
    end
    for u=1:length(obstacle)-1
        if (obstacle{u+1}.position-obstacle{u+1}.longsafetymarginB)-(obstacle{u}.position+obstacle{u}.longsafetymarginF)<2*task.Ego.overtakingLength
            %obstacle{u}.longsafetymarginF=obstacle{u}.longsafetymarginF+task.Ego.overtakingLength;
            %obstacle{u+1}.longsafetymarginB=obstacle{u+1}.longsafetymarginF+task.Ego.overtakingLength;
            obstacle{u}.longsafetymarginF=obstacle{u+1}.position-obstacle{u}.position-obstacle{u+1}.longsafetymarginB;
        end
    end
elseif nargin==5
    
    obstacle{1}=standardObstacle;
    obstacle{1}.position=1000;
    obstacle{2}=standardObstacle;
    obstacle{2}.position=-200; 
    obstacle{2}.yPosition=7.5;
    obstacle{2}.velocity=task.Ego.velocity+2;
    
end

end