#include "../../inc/cube_3d.h"

static int ft_unvisited(t_point parent)
{
    return (parent.x == -1 && parent.y == -1);
}

static int ft_staystill(t_point start, t_point target, t_point parent)
{
    if (start.x == target.x && start.y == target.y)
		return (1); 
    else if (ft_unvisited(parent))
        return (1);
    return 0;
}

void ft_get_next_step(t_player *monster, t_bfs *bfs, t_point start, t_point target)
{
    t_point cur;
    t_point parent;

    cur = target;
    parent = bfs->came_from[ft_get_index(target, *bfs)];
    if (ft_staystill(start, target, parent))
    {
        monster->next_step = start;
        return ;
    } 
    while (!(parent.x == start.x && parent.y == start.y))
    {
        if (ft_unvisited(parent))
            return ;
        cur = parent;
        parent = bfs->came_from[ft_get_index(cur, *bfs)];
    }
    monster->next_step = cur;
}