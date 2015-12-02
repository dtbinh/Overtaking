function obstacle=generateObstacle(p,M,vE,task)
n=0;
obstacle=[];
v=vE/8;
for i=ceil(v*20):M-100
if rand < p
    n=n+1;
    obstacle(n)=i*v+100;
end
end

if isempty(obstacle)
    obstacle(1)=M/3*v/2;
    obstacle(2)=2*M/3*v/2;
end



end