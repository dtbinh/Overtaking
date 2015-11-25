function obstacle=generateObstacle(p,M,vE,task)
n=0;
obstacle=[];
for i=100:M-100
if rand < p
    n=n+1;
    obstacle(n)=i*vE;
end
end

if isempty(obstacle)
    obstacle(ceil(M/3))=M/3*vE/2;
    obstacle(ceil(2*M/3))=2*M/3*vE/2;
end

l=1:2*length(obstacle)

end