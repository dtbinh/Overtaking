function obstacle=generateObstacle(p,M,task)

n=0;
temp=standardObstacle;
vL=temp.velocity;
pp=0.25;
t=0;
obstacle={};

vD=task.Ego.velocity-vL;

for i=20:M-20
if rand < p && i-t>20
    n=n+1;
    t=i;
    if rand > pp
    obstacle{n}=standardObstacle;
    obstacle{n}.position=i*vD;
    else
    obstacle{n}=truckObstacle;
    obstacle{n}.position=i*vD;        
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

end