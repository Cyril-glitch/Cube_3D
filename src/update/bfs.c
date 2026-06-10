#include "../../inc/cube_3d.h"

void    ft_bfs(t_data *data, t_bfs *bfs)
{
    t_point cur;

    ft_init_research(data->monster, data->player, bfs);
    ft_get_target_path(data, bfs, &cur);
    ft_get_next_step(&data->monster, bfs, bfs->start, bfs->target);
}