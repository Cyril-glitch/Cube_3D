/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:35:20 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/26 12:49:07 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_ceiling_draw(t_data *data, t_ray *ray, int x)
{
	int	color;
	int	y;

	y = 0;
	while (y < ray[x].draw_start)
	{
		color = data->map.ceiling_color;
		my_mlx_pixel_put(&data->screen, x, y, color);
		y++;
	}
}

static void	ft_floor_draw(t_data *data, int x, int y)
{
	int	color;

	while (y < data->win_size.y)
	{
		color = data->map.floor_color;
		my_mlx_pixel_put(&data->screen, x, y, color);
		y++;
	}
}

static void	ft_brightness(t_ray *ray, int x, int *color)
{
	if (ray[x].side == 1)
		*color = (*color >> 1) & 8355711;
}

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
		ft_ceiling_draw(data, ray, x);
		y = ray[x].draw_start;
		while (y <= ray[x].draw_end)
		{
			tex_x = ray[x].tex_x;
			tex_y = (int)ray[x].tex_pos & (data->textures[ray[x].tex_num].h
					- 1);
			ray[x].tex_pos += ray[x].step;
			color = get_pixel(&data->textures[ray[x].tex_num], tex_x, tex_y);
			ft_brightness(ray, x, &color);
			my_mlx_pixel_put(&data->screen, x, y, color);
			y++;
		}
		ft_floor_draw(data, x, y);
		x++;
	}
}

void	ft_render_draw(t_ray *ray, t_data *data)
{
	(void)ray;
	ft_wall_draw(ray, data);
}
