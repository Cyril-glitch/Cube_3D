/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:37:01 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 14:40:43 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

void	init_sprites_pos(t_sprite *sprites, t_map *map, int type)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == type)
			{
				sprites[i].x = (double)x + 0.5;
				sprites[i].y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

int	count_sprites(t_map *map, int type)
{
	int	x;
	int	y;
	int	res;

	res = 0;
	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == type)
				res++;
			x++;
		}
		y++;
	}
	return (res);
}

static void	ft_sort2(t_sprite_order *res, int count)
{
	int				i;
	int				j;
	t_sprite_order	tmp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - 1)
		{
			if (res[j].dist < res[j + 1].dist)
			{
				tmp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

t_sprite_order	*sort_sprites(t_data *data, int count)
{
	int				i;
	t_sprite_order	*res;

	res = malloc(sizeof(t_sprite_order) * count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count)
	{
		res[i].index = i;
		res[i].type = data->sprites[i].type;
		res[i].dist = (data->player.pos_x - data->sprites[i].x)
			* (data->player.pos_x - data->sprites[i].x) + (data->player.pos_y
				- data->sprites[i].y) * (data->player.pos_y
				- data->sprites[i].y);
		i++;
	}
	ft_sort2(res, count);
	return (res);
}
