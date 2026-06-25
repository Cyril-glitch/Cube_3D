/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:13:05 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/25 12:25:09 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static int	get_hit_pos(t_data *data, t_ray *ray, double *t, double *hit_pos)
{
	if ((fabs(ray->dir_x) < 0.001 && ray->door->vertical)
		|| (fabs(ray->dir_y) < 0.001 && !ray->door->vertical))
	{
		ray->door_dist = DBL_MAX;
		return (1);
	}
	if (ray->door->vertical)
	{
		*t = ((double)ray->map_x + 0.5 - data->player.pos_x) / ray->dir_x;
		*hit_pos = data->player.pos_y + *t * ray->dir_y;
		if (*hit_pos < ray->map_y || *hit_pos > ray->map_y + 1.0)
			return (0);
	}
	else
	{
		*t = ((double)ray->map_y + 0.5 - data->player.pos_y) / ray->dir_y;
		*hit_pos = data->player.pos_x + *t * ray->dir_x;
		if (*hit_pos < ray->map_x || *hit_pos > ray->map_x + 1.0)
			return (0);
	}
	*hit_pos -= floor(*hit_pos);
	return (1);
}

int	ray_hits_visible_part_of_door(t_data *data, t_ray *ray)
{
	double	t;
	double	hit_pos;

	t = 0;
	ray->door = get_door(data->map.grid, data->doors, ray->map_x, ray->map_y);
	if (!ray->door)
		return (0);
	if (!get_hit_pos(data, ray, &t, &hit_pos))
		return (0);
	if (t <= 0)
		return (0);
	if (hit_pos >= ray->door->open)
	{
		ray->door_dist = t;
		return (1);
	}
	return (0);
}

void	ft_perform_dda(t_data *data, t_ray *ray, char **map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
		else if (map[ray->map_y][ray->map_x] == VER_DOOR
			|| map[ray->map_y][ray->map_x] == HOR_DOOR)
		{
			if (ray_hits_visible_part_of_door(data, ray))
				ray->hit = 2;
		}
	}
}
