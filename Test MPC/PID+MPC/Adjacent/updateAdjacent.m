function task=updateAdjacent(task)

for i=1:length(task.adjacent)
   
    task.adjacent{i}.position=task.adjacent{i}.position+task.adjacent{i}.velocity-task.obstacle{1}.velocity;
    if task.adjacent{i}.position<task.Ego.position && task.Ego.yPosition > 2.6
        task.adjacent{i}.velocity=task.Ego.velocity;
    else
        task.adjacent{i}.velocity=task.Ego.velocity+1;
    end
    
end
end
