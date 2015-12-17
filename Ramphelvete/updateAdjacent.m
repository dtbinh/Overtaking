function task=updateAdjacent(task)

for i=1:length(task.obstacle)
    if task.obstacle{i}.velocity > task.Ego.velocity
        task.obstacle{i}.position=task.obstacle{i}.position+task.obstacle{i}.velocity-task.obstacle{1}.velocity;
    end
end
end
