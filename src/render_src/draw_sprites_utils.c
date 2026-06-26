/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:22:53 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/26 18:27:08 by cycolonn         ###   ########.fr       */
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
	sprite->inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x
			* player->plane_y);
	sprite->transform_x = sprite->inv_det * (player->dir_y * sprite->x
			- player->dir_x * sprite->y);
	sprite->transform_y = sprite->inv_det * (-player->plane_y * sprite->x
			+ player->plane_x * sprite->y);
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
	sprite->screen_x = (int)((screen->half_w) * (1 + sprite->transform_x
				* sprite->inv_transform_y));
	sprite->draw_start_y = -sprite->half_h + screen->half_h;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->half_h + screen->half_h;
	if (sprite->draw_end_y >= screen->h)
		sprite->draw_end_y = screen->h - 1;
	sprite->w = fabs(screen->h * sprite->inv_transform_y);
	sprite->draw_start_x = -sprite->half_w + sprite->screen_x;
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
	sprite->tex_y = (d * sprites[sprite_id].textures[current_frame].h
			* sprite->inv_h) / 256;
	if (sprite->tex_x < sprites[sprite_id].textures[current_frame].w
		&& sprite->tex_x >= 0
		&& sprite->tex_y < sprites[sprite_id].textures[current_frame].h
		&& sprite->tex_y >= 0)
	{
		sprite->color = get_pixel(&sprites[sprite_id].textures[current_frame],
				sprite->tex_x, sprite->tex_y);
		if (sprite->color != 0x00FF00)
			my_mlx_pixel_put(screen, p.x, p.y, sprite->color);
	}
}

void	ft_nb_frames(t_sprite_type *sprite, int *nb_frames)
{
	if (sprite->type == SPRITE_M)
		*nb_frames = SPRITE_M_TEXT_NB;
	else if (sprite->type == SPRITE_P)
		*nb_frames = SPRITE_P_TEXT_NB;
	else
		*nb_frames = SPRITE_T_TEXT_NB;
}

int	ft_is_hidden(t_data *data, int cur_x, t_img *screen, t_sprite_type *sprite)
{
	if (cur_x < 0 || cur_x >= screen->w)
		return (1);
	if (sprite->transform_y <= 0)
		return (1);
	if (sprite->transform_y >= data->ray[cur_x].perp_wall_dist)
		return (1);
	return (0);
}
