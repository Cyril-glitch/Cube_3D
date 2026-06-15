#include "../../inc/cube_3d.h"

int ft_get_index(t_point p, t_bfs bfs)
{
    return p.y * bfs.max_w + p.x;
}

