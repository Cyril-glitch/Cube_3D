/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichaud <nmichaud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:22:36 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/04 14:22:37 by nmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

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

int	ft_assign_sprites_textures(t_data *data, int type)
{
	int	i;
	int	j;

	if (!init_sprite_textures(data))
		return (0);
	data->nb_sprites = count_sprites(&data->map, type);
	printf("nb sprites : %d\n", data->nb_sprites);
	data->sprites = malloc(sizeof(t_sprite) * data->nb_sprites);
	if (!data->sprites)
		return (0);
	i = 0;
	while (i < data->nb_sprites)
	{
		j = 0;
		while (j < SPRITE_1_TEXT_NB)
		{
			data->sprites[i].texture[j] = &data->textures[j + 5];
			j++;
		}
		i++;
	}
	return (1);
}

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

static void	ft_sort2(int *res, double *dist, int count)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - 1)
		{
			if (dist[res[j]] < dist[res[j + 1]])
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

int	*sort_sprites(t_data *data, int count)
{
	int	i;
	int	*res;
	double	*dist;

	res = malloc(sizeof(int) * count);
	if (!res)
		return (NULL);
	dist = malloc(sizeof(double) * count);
	if (!dist)
		return (free(res), NULL);
	i = 0;
	while (i < count)
	{
		res[i] = i;
		dist[i] = (data->player.pos_x - data->sprites[i].x) * (data->player.pos_x - data->sprites[i].x) +
					(data->player.pos_y - data->sprites[i].y) * (data->player.pos_y - data->sprites[i].y);
		i++;
	}
	ft_sort2(res, dist, count);
	free(dist);
	return (res);
}
