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

void	compute_sprite_transformation(t_player *player, t_sprite_type *sprite)
{
	t_sprite	*sprites;
	int			sprite_id;

	sprite_id = sprite->sprite_id;
	sprites = sprite->sprites; 
	sprite->x = sprites[sprite_id].x - player->pos_x;
	sprite->y = sprites[sprite_id].y - player->pos_y;
	sprite->inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y);
	sprite->transform_x = sprite->inv_det * (player->dir_y * sprite->x - player->dir_x * sprite->y);
	sprite->transform_y = sprite->inv_det * (-player->plane_y * sprite->x + player->plane_x * sprite->y);
}

void	compute_sprite_bounds(t_img *screen, t_sprite_type *sprite)
{
	sprite->inv_transform_y = 1.0 / sprite->transform_y;
	sprite->h = fabs(screen->h * sprite->inv_transform_y);
	sprite->w = fabs(screen->h * sprite->inv_transform_y);
	sprite->half_h = sprite->h / 2;
	sprite->half_w = sprite->w / 2;
	sprite->inv_h = 1.0 / sprite->h;
	sprite->inv_w = 1.0 / sprite->w;
	sprite->screen_x = (int)((screen->half_w) *
						(1 + sprite->transform_x * sprite->inv_transform_y));
	sprite->draw_start_y = - sprite->half_h + screen->half_h;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->half_h + screen->half_h;
	if (sprite->draw_end_y >= screen->h)
		sprite->draw_end_y = screen->h - 1;
	sprite->w = fabs(screen->h * sprite->inv_transform_y); // w au lieu de h ?
	sprite->draw_start_x = - sprite->half_w + sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->half_w + sprite->screen_x;
	if (sprite->draw_end_x >= screen->w)
		sprite->draw_end_x = screen->w - 1;
}

void	put_pixel_sprite(t_img *screen, t_sprite_type *sprite, t_point p)
{
	int			d;
	int			current_frame;
	t_sprite	*sprites;
	int			sprite_id;

	sprite_id = sprite->sprite_id;
	sprites = sprite->sprites;
	current_frame = sprite->current_frame;
	d = p.y * 256 - screen->h * 128 + sprite->h * 128;
	sprite->tex_y = (d * sprites[sprite_id].textures[current_frame].h * sprite->inv_h) / 256;
	if (sprite->tex_x < sprites[sprite_id].textures[current_frame].w && sprite->tex_x >= 0
		&& sprite->tex_y < sprites[sprite_id].textures[current_frame].h && sprite->tex_y >= 0)
	{
		sprite->color = get_pixel(&sprites[sprite_id].textures[current_frame], sprite->tex_x, sprite->tex_y);
		if (sprite->color != 0)
			my_mlx_pixel_put(screen, p.x, p.y, sprite->color);
	}
}

void	render_sprite(t_data *data, t_img *screen, double time, t_sprite_type *sprite)
{
	t_point	p;
	t_sprite	*sprites;
	int		current_frame;
	int		nb_frames;

	sprites = sprite->sprites;
	if (sprite->type == SPRITE_M)
		nb_frames = SPRITE_M_TEXT_NB;
	else
		nb_frames = SPRITE_T_TEXT_NB;
	p.x = sprite->draw_start_x;
	while (p.x < sprite->draw_end_x)
	{
		sprite->current_frame = (int)(time / 150.0) % nb_frames;
		current_frame = sprite->current_frame;
		sprite->tex_x = (int)(256 * (p.x - (- sprite->half_w + sprite->screen_x)) * sprites[sprite->sprite_id].textures[current_frame].w * sprite->inv_w) / 256;
		if (sprite->transform_y <= 0 || sprite->transform_y >= data->ray[p.x].perp_wall_dist)
		{
			p.x++;
			continue;
		}
		if (sprite->transform_y > 0 && p.x > 0 && p.x < screen->w && sprite->transform_y < data->ray[p.x].perp_wall_dist)
		{
			p.y = sprite->draw_start_y;
			while (p.y < sprite->draw_end_y)
			{
				put_pixel_sprite(screen, sprite, p);
				p.y++;
			}
		}
		p.x++;
	}
}

void	draw_single_sprite(t_data *data, t_player *player, int sprite_id, int type)
{
	t_sprite_type	sprite;
	double			time;

	time = get_time(data->start);
	sprite.type = type;
	sprite.sprites = data->sprites;
	sprite.sprite_id = sprite_id;
	compute_sprite_transformation(player, &sprite);
	if (sprite.transform_y <= 0)
		return ;
	compute_sprite_bounds(&data->screen, &sprite);
	render_sprite(data, &data->screen, time, &sprite);
}

int	draw_sprites(t_data *data, t_player *player)
{
	t_sprite_order		*order;
	int					i;
	int					count;
	
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
