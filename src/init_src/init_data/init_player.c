/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:17:06 by cyril             #+#    #+#             */
/*   Updated: 2026/06/22 14:17:13 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	init_player_dir(t_data *data)
{
	if (data->player.dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
	else if (data->player.dir == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
	else if (data->player.dir == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
	else if (data->player.dir == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
	data->player.plane_x = (-data->player.dir_y) * 0.66;
	data->player.plane_y = data->player.dir_x * 0.66;
}

void	ft_init_stats(t_data *data, t_hp *hp)
{
	hp->pos_x = data->win_size.x / 150;
	hp->pos_y = data->win_size.y - (data->win_size.y / 10);
	hp->w = data->win_size.x / 5;
	hp->h = data->win_size.y / 50;
	hp->thickness = hp->w / 100;
	hp->color = 0x00FF00;
	hp->health = 100;
}
