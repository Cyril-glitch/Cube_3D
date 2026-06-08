/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichaud <nmichaud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:22:53 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/04 14:22:54 by nmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

int	draw_sprites(t_data *data, t_player *player)
{
	int		*order;
	int		i;
	int		x;
	int		y;
	int		color;
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		sprite_h;
	int		sprite_w;
	int		draw_start_y;
	int		draw_start_x;
	int		draw_end_y;
	int		draw_end_x;

	order = sort_sprites(data, data->nb_sprites);
	if (!order)
		return (0);
	i = 0;
	while (i < data->nb_sprites)
	{
		sprite_x = data->sprites[order[i]].x - player->pos_x;
		sprite_y = data->sprites[order[i]].y - player->pos_y;
		inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y);
		transform_x = inv_det * (player->dir_y * sprite_x - player->dir_x * sprite_y);
		transform_y = inv_det * (-player->plane_y * sprite_x + player->plane_x * sprite_y);
		if (transform_y <= 0)
		{
			i++;
			continue ;
		}
		sprite_screen_x = (int)((data->screen.w / 2) * (1 + transform_x / transform_y));
		sprite_h = abs((int)(data->screen.h / transform_y));
		draw_start_y = - sprite_h / 2 + data->screen.h / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		draw_end_y = sprite_h / 2 + data->screen.h / 2;
		if (draw_end_y >= data->screen.h)
			draw_end_y = data->screen.h - 1;
		sprite_w = abs((int)(data->screen.h / transform_y)); // w au lieu de h ?
		draw_start_x = - sprite_w / 2 + sprite_screen_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		draw_end_x = sprite_w / 2 + sprite_screen_x;
		if (draw_end_x >= data->screen.w)
			draw_end_x = data->screen.w - 1;
		x = draw_start_x;
		while (x < draw_end_x)
		{
			int	tex_x = (int)(256 * (x - (- sprite_w / 2 + sprite_screen_x)) * data->sprites[order[i]].texture->w / sprite_w) / 256;
			if (transform_y > 0 && x > 0 && x < data->screen.w && transform_y < data->ray[x].perp_wall_dist)
			{
				y = draw_start_y;
				while (y < draw_end_y)
				{
					int d = y * 256 - data->screen.h * 128 + sprite_h * 128;
					int	tex_y = (d * data->sprites[order[i]].texture->h / sprite_h) / 256;
					if (tex_x < data->sprites[order[i]].texture->w && tex_x >= 0
						&& tex_y < data->sprites[order[i]].texture->h && tex_y >= 0)
					{
						color = get_pixel(data->sprites[order[i]].texture, tex_x, tex_y);
						if (color != 0)
							my_mlx_pixel_put(&data->screen, x, y, color);
					}
					y++;
				}
			}
			x++;
		}
		i++;
	}
	free(order);
	return (1);
}
