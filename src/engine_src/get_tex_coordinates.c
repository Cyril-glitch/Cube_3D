/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:19:41 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/25 12:25:17 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	get_tex_number(char **grid, int h, t_ray *ray)
{
	if (ray->hit == 2)
		ray->tex_num = DOOR_TEXT;
	else
	{
		ray->tex_num = get_map_tile(grid, h, ray->map_x, ray->map_y) - 1;
		if (ray->tex_num < 0 || ray->tex_num > 1)
			return ;
		if (ray->side == 0)
		{
			if (ray->step_x == 1)
				ray->tex_num = 3;
			else
				ray->tex_num = 2;
		}
		else if (ray->side == 1)
		{
			if (ray->step_y == 1)
				ray->tex_num = 1;
			else
				ray->tex_num = 0;
		}
	}
}

void	ft_get_tex_coordinates(t_img *textures, t_map *map, t_ray *ray,
		t_player player)
{
	double	wall_x;

	get_tex_number(map->grid, map->height, ray);
	if (ray->side == 0)
		wall_x = player.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = player.pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (double)textures[ray->tex_num].w);
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1
			&& ray->dir_y < 0))
		ray->tex_x = textures[ray->tex_num].w - ray->tex_x - 1;
	if (ray->hit == 2)
	{
		ray->tex_x = (int)((wall_x - ray->door->open)
				* (double)textures[ray->tex_num].w);
		ray->tex_x = ray->tex_x % textures[ray->tex_num].w;
	}
	ray->step = 1.0 * textures[ray->tex_num].h / ray->line_height;
	ray->tex_pos = (ray->draw_start - ray->half_h + ray->line_height / 2)
		* ray->step;
}
