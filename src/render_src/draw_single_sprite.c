/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_single_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:26:08 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 18:26:50 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_get_sprite_tex_x(t_sprite_type *sprite, int x)
{
	t_sprite	*sprites;
	int			frame;

	sprites = sprite->sprites;
	frame = sprite->current_frame;
	sprite->tex_x = (int)(256 * (x - (-sprite->half_w + sprite->screen_x))
			* sprites[sprite->sprite_id].textures[frame].w * sprite->inv_w)
		/ 256;
}

static void	ft_draw_sprite_column(t_img *screen, t_sprite_type *sprite, int x)
{
	t_point	p;

	p.x = x;
	p.y = sprite->draw_start_y;
	while (p.y < sprite->draw_end_y)
	{
		put_pixel_sprite(screen, sprite, p);
		p.y++;
	}
}

static void	render_sprite(t_data *data, t_img *screen, double time,
		t_sprite_type *sprite)
{
	t_point	p;
	int		nb_frames;

	ft_nb_frames(sprite, &nb_frames);
	sprite->current_frame = ((int)time + sprite->sprite_id) % nb_frames;
	p.x = sprite->draw_start_x;
	while (p.x < sprite->draw_end_x)
	{
		if (!ft_is_hidden(data, p.x, screen, sprite))
		{
			ft_get_sprite_tex_x(sprite, p.x);
			ft_draw_sprite_column(screen, sprite, p.x);
		}
		p.x++;
	}
}

void	draw_single_sprite(t_data *data, t_player *player, int sprite_id,
		int type)
{
	t_sprite_type	sprite;
	double			time;

	time = get_time(data->start) / 150.0;
	sprite.type = type;
	sprite.sprites = data->sprites;
	sprite.sprite_id = sprite_id;
	if (type == SPRITE_P && data->sprites[sprite_id].consumed == true)
		return ;
	compute_sprite_transformation(player, &sprite);
	if (sprite.transform_y <= 0)
		return ;
	compute_sprite_bounds(&data->screen, &sprite);
	render_sprite(data, &data->screen, time, &sprite);
}
