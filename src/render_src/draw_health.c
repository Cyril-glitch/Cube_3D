/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_health.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:40:14 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/25 11:40:26 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static int	ft_outline(t_hp hp, int x, int y, int thick)
{
	int	in;
	int	out_w;
	int	out_h;

	in = thick;
	out_w = hp.w - thick;
	out_h = hp.h - thick;
	return (y > in && y < out_h && x > in && x < out_w);
}

static int	ft_cur_hp(int w, int health)
{
	int	damage;
	int	new_w;
	int	tmp;

	damage = 100 - health;
	tmp = w;
	if (!damage)
		return (w);
	tmp *= damage;
	tmp /= 100;
	new_w = w - tmp;
	return (new_w);
}

static void	ft_draw_hp(t_data *data, t_hp hp)
{
	int	y;
	int	x;

	y = 0;
	while (y < hp.h)
	{
		x = 0;
		while (x < hp.w)
		{
			if (!ft_outline(hp, x, y, hp.thickness))
				my_mlx_pixel_put(&data->screen, hp.pos_x + x, hp.pos_y + y,
					0xFFFFFF);
			else if (x < ft_cur_hp(hp.w, hp.health))
				my_mlx_pixel_put(&data->screen, hp.pos_x + x, hp.pos_y + y,
					hp.color);
			x++;
		}
		y++;
	}
}

void	ft_draw_health(t_data *data)
{
	ft_draw_hp(data, data->player.hp);
}
