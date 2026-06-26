/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:01:37 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 13:01:55 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_move_left(t_player *monster, double target_x, double speed)
{
	if (monster->pos_x < target_x)
	{
		monster->pos_x += speed;
		if (monster->pos_x > target_x)
			monster->pos_x = target_x;
	}
}

static void	ft_move_right(t_player *monster, double target_x, double speed)
{
	if (monster->pos_x > target_x)
	{
		monster->pos_x -= speed;
		if (monster->pos_x < target_x)
			monster->pos_x = target_x;
	}
}

static void	ft_move_down(t_player *monster, double target_y, double speed)
{
	if (monster->pos_y > target_y)
	{
		monster->pos_y -= speed;
		if (monster->pos_y < target_y)
			monster->pos_y = target_y;
	}
}

static void	ft_move_up(t_player *monster, double target_y, double speed)
{
	if (monster->pos_y < target_y)
	{
		monster->pos_y += speed;
		if (monster->pos_y > target_y)
			monster->pos_y = target_y;
	}
}

void	ft_bot_move(t_data *data, int i)
{
	double	speed;
	double	target_x;
	double	target_y;

	speed = 0.03;
	target_x = data->monsters[i].next_step.x + 0.5;
	target_y = data->monsters[i].next_step.y + 0.5;
	ft_move_left(&data->monsters[i], target_x, speed);
	ft_move_right(&data->monsters[i], target_x, speed);
	ft_move_up(&data->monsters[i], target_y, speed);
	ft_move_down(&data->monsters[i], target_y, speed);
	data->monsters[i].sprite->x = data->monsters[i].pos_x;
	data->monsters[i].sprite->y = data->monsters[i].pos_y;
}
