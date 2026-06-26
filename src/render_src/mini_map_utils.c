/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:08:57 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 18:27:04 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

int	get_tile_color(int a)
{
	if (a == 0)
		return (0x00D4D4D4);
	else if (a == 1)
		return (0x00555555);
	else if (a == VER_DOOR - '0')
		return (0x00336699);
	else if (a == HOR_DOOR - '0')
		return (0x00336699);
	return (0x00D4D4D4);
}

void	draw_big_pixel(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int	is_edge_of_square(t_data *data, t_mini_map *map, int x, int y)
{
	if (x == map->screen.x && get_map_tile(data->map.grid, data->map.height,
			map->map_tile.x - 1, map->map_tile.y) != 1)
		return (1);
	if (x == map->screen.x + map->tile_size - 1 && get_map_tile(data->map.grid,
			data->map.height, map->map_tile.x + 1, map->map_tile.y) != 1)
		return (1);
	if (y == map->screen.y && get_map_tile(data->map.grid, data->map.height,
			map->map_tile.x, map->map_tile.y - 1) != 1)
		return (1);
	if (y == map->screen.y + map->tile_size - 1 && get_map_tile(data->map.grid,
			data->map.height, map->map_tile.x, map->map_tile.y + 1) != 1)
		return (1);
	return (0);
}
