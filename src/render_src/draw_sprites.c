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
	t_sprite	*sprites;

	sprites = data->sprites;
	sprite->x = sprites[sprite_id].x - player->pos_x;
	sprite->y = sprites[sprite_id].y - player->pos_y;
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

void	put_pixel_sprite(t_data *data, t_sprite_type *sprite, int sprite_id, t_point p)
{
	int	d;
	int	current_frame;
	t_sprite	*sprites;

	sprites = data->sprites;
	current_frame = sprite->current_frame;
	d = p.y * 256 - data->screen.h * 128 + sprite->h * 128;
	sprite->tex_y = (d * sprites[sprite_id].textures[current_frame].h / sprite->h) / 256;
	if (sprite->tex_x < sprites[sprite_id].textures[current_frame].w && sprite->tex_x >= 0
		&& sprite->tex_y < sprites[sprite_id].textures[current_frame].h && sprite->tex_y >= 0)
	{
		sprite->color = get_pixel(&sprites[sprite_id].textures[current_frame], sprite->tex_x, sprite->tex_y);
		if (!is_close_color(sprite->color, 0))
			my_mlx_pixel_put(&data->screen, p.x, p.y, sprite->color);
	}
}

void	render_sprite(t_data *data, int sprite_id, t_sprite_type *sprite)
{
	t_point	p;
	t_sprite	*sprites;
	int		current_frame;
	int		nb_frames;
	double	time;

	sprites = data->sprites;
	if (sprite->type == SPRITE_M)
		nb_frames = SPRITE_M_TEXT_NB;
	else
		nb_frames = SPRITE_T_TEXT_NB;
	p.x = sprite->draw_start_x;
	while (p.x < sprite->draw_end_x)
	{
		time = get_time(data->start);
		sprite->current_frame = (int)(time / 150.0) % nb_frames;
		current_frame = sprite->current_frame;
		sprite->tex_x = (int)(256 * (p.x - (- sprite->w / 2 + sprite->screen_x)) * sprites[sprite_id].textures[current_frame].w / sprite->w) / 256;
		if (sprite->transform_y > 0 && p.x > 0 && p.x < data->screen.w && sprite->transform_y < data->ray[p.x].perp_wall_dist)
		{
			p.y = sprite->draw_start_y;
			while (p.y < sprite->draw_end_y)
			{
				put_pixel_sprite(data, sprite, sprite_id, p);
				p.y++;
			}
		}
		p.x++;
	}
}

void	draw_single_sprite(t_data *data, t_player *player, int sprite_id, int type)
{
	t_sprite_type	sprite;

	sprite.type = type;
	compute_sprite_transformation(data, player, sprite_id, &sprite);
	if (sprite.transform_y <= 0)
		return ;
	compute_sprite_bounds(data, &sprite);
	render_sprite(data, sprite_id, &sprite);
}

int	draw_sprites(t_data *data, t_player *player)
{
	t_sprite_order		*order;
	int		i;
	int		count;
	
	count = data->t_sprites->number + data->m_sprites->number;
	order = sort_sprites(data, count);
	if (!order)
		return (0);
	i = 0;
	while (i < count)
	{
		draw_single_sprite(data, player, order[i].index, order[i].type);
		i++;
	}
	free(order);
	return (1);
}
