/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:40:33 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/25 12:20:38 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_get_ray_dir(t_player player, t_ray *ray, int x, int w)
{
	ray->camera_x = 2 * x / (double)w - 1;
	ray->dir_x = player.dir_x + player.plane_x * ray->camera_x;
	ray->dir_y = player.dir_y + player.plane_y * ray->camera_x;
}

static void	ft_get_draw_data(t_ray *ray, int h)
{
	if (!ray->side)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	if (ray->hit == 2)
	{
		ray->side = !ray->door->vertical;
		ray->perp_wall_dist = ray->door_dist;
	}
	ray->line_height = (int)(h / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + ray->half_h;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + ray->half_h;
	if (ray->draw_end >= h)
		ray->draw_end = h - 1;
}

void	ft_raycaster(t_data *data, t_ray *ray)
{
	int	x;

	x = 0;
	while (x < data->win_size.x)
	{
		ft_get_ray_dir(data->player, &ray[x], x, data->win_size.x);
		ft_init_dda(&ray[x], data->player);
		ft_perform_dda(data, &ray[x], data->map.grid);
		ft_get_draw_data(&ray[x], data->win_size.y);
		ft_get_tex_coordinates(data->textures, &data->map, &ray[x],
			data->player);
		x++;
	}
	data->ray = ray;
}
