    function vE=getVD(vE,vL,vEo,obstacle,xPos,y)
    minDiff=4/3.6;
    vD=vE-vL;
currentObstacle=find(obstacle>xPos);
currentObstacle=obstacle(currentObstacle(1));
   if vD<minDiff && currentObstacle-xPos<200
       vE=vL;
   elseif vD>minDiff && vD<2*minDiff && abs(currentObstacle-xPos)<200
       vE=vE+vD;
   elseif abs(currentObstacle-xPos)>200 && y<3
       vE=vEo;
   end
    end