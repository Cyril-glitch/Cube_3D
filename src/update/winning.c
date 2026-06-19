#include "../../inc/cube_3d.h"

static int     ft_is_treasure(t_player *player, t_sprite *treasure)
{
    return ((int)treasure->x == (int)(player->pos_x) && (int)treasure->y == (int)player->pos_y);
}

void    ft_player_win(t_player *player, t_sprite *treasure, int trs_index)
{
        if (ft_is_treasure(player, &treasure[trs_index]))
            player->scored = 1;
}