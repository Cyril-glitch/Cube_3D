#include "../../inc/cube_3d.h"

void ft_init_camefrom(t_bfs *bfs)
{
    int i;
    i = 0;

	while (i < bfs->max_w * bfs->max_h)
	{
		bfs->came_from[i].x = -1;
		bfs->came_from[i].y = -1;
		i++;
	}
}

void ft_init_start(t_player monster,t_bfs *bfs)
{
    bfs->start.x = monster.pos_x;
    bfs->start.y = monster.pos_y;
}

void ft_init_target(t_player player, t_bfs *bfs)
{
    bfs->target.x = player.pos_x;
    bfs->target.y = player.pos_y;
}

void ft_init_research(t_player monster, t_player player, t_bfs *bfs)
{
    ft_init_start(monster, bfs);
    ft_init_target(player, bfs);
    ft_init_camefrom(bfs);
    bfs->queue[bfs->waiters] = bfs->start;
    bfs->waiters++;
    bfs->came_from[ft_get_index(bfs->start, *bfs)] = bfs->start; 
}