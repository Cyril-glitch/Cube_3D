/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:51:27 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/29 16:46:41 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	ft_wall_draw(t_ray *ray, t_data *data)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;

	x = 0;
	while (x < data->win_size.x)
	{
		y = ray[x].draw_start;
		while (y < ray[x].draw_end)
		{
			tex_x = ray[x].tex_x;
			tex_y = (int)ray[x].tex_pos & (data->textures[ray[x].tex_num].h
					- 1);
			ray[x].tex_pos += ray[x].step;
			color = get_pixel(&data->textures[ray[x].tex_num], tex_x, tex_y);
			if (ray[x].side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(&data->screen, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_render_map(t_data *data, t_mini_map *map)
{
	int	x;
	int	y;
	int	color;

	ft_memset(data->mini_map.image.addr, 0, data->mini_map.size
		* data->mini_map.size * 4);
	draw_map_img(data, &data->mini_map, data->player);
	x = 10;
	while (x < map->size + 10)
	{
		y = 10;
		while (y < map->size + 10)
		{
			color = get_pixel(&map->image, x - 10, y - 10);
			my_mlx_pixel_put(&data->screen, x, y, color);
			y++;
		}
		x++;
	}
}

static int	ft_render_event(t_data *data)
{
	if (data->player.hp.health <= 0 && !data->player.scored)
		return (ft_render_death(data, data->over), 1);
	else if (data->player.scored == 1)
		return (ft_render_win(data, data->congrats), 1);
	return (0);
}

void	ft_render_draw(t_ray *ray, t_data *data)
{
	if (ft_render_event(data))
		return ;
	ft_render_fc(data, &data->bgrd, &data->bgrd.floor, &data->bgrd.ceiling);
	ft_wall_draw(ray, data);
	if (!draw_sprites(data, &data->player))
		return ;
	ft_render_ath(data);
	ft_render_map(data, &data->mini_map);
	ft_red_filter(data, &data->player, (unsigned int *)data->screen.addr);
	ft_green_filter(data, &data->player, (unsigned int *)data->screen.addr);
}
