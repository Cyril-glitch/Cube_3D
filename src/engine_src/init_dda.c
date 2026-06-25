/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:55:57 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/25 12:25:01 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_get_map_pos(t_ray *ray, t_player player)
{
	ray->map_x = (int)player.pos_x;
	ray->map_y = (int)player.pos_y;
}

static void	ft_get_delta(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->delta_dist_x = DBL_MAX;
	else
		ray->delta_dist_x = ft_abs2(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = DBL_MAX;
	else
		ray->delta_dist_y = ft_abs2(1 / ray->dir_y);
}

static void	ft_get_sidedist(t_ray *ray, t_player player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player.pos_y)
			* ray->delta_dist_y;
	}
}

void	ft_init_dda(t_ray *ray, t_player player)
{
	ft_get_map_pos(ray, player);
	ft_get_delta(ray);
	ft_get_sidedist(ray, player);
}
