#include "../../inc/cube_3d.h"

void    ft_bfs(t_data *data, t_player *monster, t_bfs *bfs)
{
    t_point cur;

    ft_init_research(*monster, data->player, bfs);
    ft_get_target_path(data, bfs, &cur);
    ft_get_next_step(monster, bfs, bfs->start, bfs->target);
}