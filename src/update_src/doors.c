/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:43:17 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 19:17:07 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	close_or_open_door(t_data *data)
{
	t_player	*player;
	t_door		*door;
	double		x;
	double		y;

	player = &data->player;
	x = player->pos_x + player->dir_x * (player->move_speed + INTERACT_DIST);
	y = player->pos_y + player->dir_y * (player->move_speed + INTERACT_DIST);
	door = get_door(data->map.grid, data->doors, (int)x, (int)y);
	if (!door)
		return ;
	if (!door->opening && door->open < 1.0)
	{
		door->opening = true;
		door->closing = false;
	}
	else if (!door->closing && door->open > 0.0)
	{
		door->opening = false;
		door->closing = true;
	}
}
