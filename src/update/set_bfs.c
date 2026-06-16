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

void ft_init_research(t_point start, t_point target, t_bfs *bfs)
{
	bfs->count = 0;
	bfs->waiters = 0;
	bfs->start = start;
	bfs->target = target;
	ft_init_camefrom(bfs);
	bfs->queue[bfs->waiters] = start;
	bfs->waiters++;
	bfs->came_from[ft_get_index(start, *bfs)] = start;
}
