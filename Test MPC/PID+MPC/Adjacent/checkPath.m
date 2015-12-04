    function pathClear=checkPath(oncoming,vE,ph,xPos)
    oncomingSafetyMargin=vE*2*ph;
 for k=1:length(oncoming)
    for i=1:ph
        if abs(xPos(i)-oncoming(k)) < oncomingSafetyMargin 
            forbidden(i)=1;
        end
    end
 end
 
 if sum(forbidden)>=1
     pathClear=0;
 else
     pathClear=1;
 end
    end