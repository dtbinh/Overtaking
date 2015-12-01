function oncoming=generateOncoming(p,M,vE,task)
n=0;
oncoming=[];
for i=100:M-100
if rand < p
    n=n+1;
    oncoming(n)=i*vE;
end
end

if isempty(oncoming)
    oncoming(1)=M*vE/2;
end
end