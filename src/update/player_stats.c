#include "../../inc/cube_3d.h"

static void    ft_update_health(t_data *data)
{
    ft_healing(&data->player, data->sprites, data->t_sprites->number);
    ft_damage(data, &data->player, data->monsters, data->m_sprites->number);
}

void    ft_player_stats(t_data *data)
{
    ft_update_health(data);
}