function a=generateAdjacent(p,M,task)
a{1}=struct;
a{1}=standardObstacle;
a{1}.position=-500;               %i*vE
a{1}.yPosition=7.5;            % which lane
a{1}.velocity=task.Ego.velocity+1;               %[m/s] obstacle velocity

a{2}=struct;
a{2}=standardObstacle;
a{2}.position=-1500;               %i*vE
a{2}.yPosition=7.5;            % which lane
a{2}.velocity=task.Ego.velocity+1;               %[m/s] obstacle velocity

a{3}=struct;
a{3}=standardObstacle;
a{3}.position=-2500;               %i*vE
a{3}.yPosition=7.5;            % which lane
a{3}.velocity=task.Ego.velocity+1;               %[m/s] obstacle velocity
end