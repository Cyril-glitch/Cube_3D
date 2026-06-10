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


void	compute_sprite_transformation(t_data *data, t_player *player, int sprite_id, t_sprite_type *sprite)
{
	sprite->x = data->sprites[sprite_id].x - player->pos_x;
	sprite->y = data->sprites[sprite_id].y - player->pos_y;
	sprite->inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y);
	sprite->transform_x = sprite->inv_det * (player->dir_y * sprite->x - player->dir_x * sprite->y);
	sprite->transform_y = sprite->inv_det * (-player->plane_y * sprite->x + player->plane_x * sprite->y);
}

void	compute_sprite_bounds(t_data *data, t_sprite_type *sprite)
{
	sprite->screen_x = (int)((data->screen.w / 2) * (1 + sprite->transform_x / sprite->transform_y));
	sprite->h = abs((int)(data->screen.h / sprite->transform_y));
	sprite->draw_start_y = - sprite->h / 2 + data->screen.h / 2;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->h / 2 + data->screen.h / 2;
	if (sprite->draw_end_y >= data->screen.h)
		sprite->draw_end_y = data->screen.h - 1;
	sprite->w = abs((int)(data->screen.h / sprite->transform_y)); // w au lieu de h ?
	sprite->draw_start_x = - sprite->w / 2 + sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->w / 2 + sprite->screen_x;
	if (sprite->draw_end_x >= data->screen.w)
		sprite->draw_end_x = data->screen.w - 1;
}

void	render_sprite(t_data *data, int sprite_id, t_sprite_type *sprite)
{
	int	x;
	int	y;

	x = sprite->draw_start_x;
	while (x < sprite->draw_end_x)
	{
		int	tex_x = (int)(256 * (x - (- sprite->w / 2 + sprite->screen_x)) * data->sprites[sprite_id].texture->w / sprite->w) / 256;
		if (sprite->transform_y > 0 && x > 0 && x < data->screen.w && sprite->transform_y < data->ray[x].perp_wall_dist)
		{
			y = sprite->draw_start_y;
			while (y < sprite->draw_end_y)
			{
				int d = y * 256 - data->screen.h * 128 + sprite->h * 128;
				int	tex_y = (d * data->sprites[sprite_id].texture->h / sprite->h) / 256;
				if (tex_x < data->sprites[sprite_id].texture->w && tex_x >= 0
					&& tex_y < data->sprites[sprite_id].texture->h && tex_y >= 0)
				{
					sprite->color = get_pixel(data->sprites[sprite_id].texture, tex_x, tex_y);
					if (sprite->color != 0)
						my_mlx_pixel_put(&data->screen, x, y, sprite->color);
				}
				y++;
			}
		}
		x++;
	}
}

void	draw_single_sprite(t_data *data, t_player *player, int sprite_id)
{
	t_sprite_type	sprite;

	compute_sprite_transformation(data, player, sprite_id, &sprite);
	if (sprite.transform_y <= 0)
		return ;
	compute_sprite_bounds(data, &sprite);
	render_sprite(data, sprite_id, &sprite);
}

int	draw_sprites(t_data *data, t_player *player)
{
	int		*order;
	int		i;

	order = sort_sprites(data, data->nb_sprites);
	if (!order)
		return (0);
	i = 0;
	while (i < data->nb_sprites)
	{
		draw_single_sprite(data, player, order[i]);
		i++;
	}
	free(order);
	return (1);
}
