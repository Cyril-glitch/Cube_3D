/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:08:57 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 12:34:08 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	draw_squares(t_data *data, t_mini_map *map, int tile_value)
{
	int	color;
	int	x;
	int	y;

	color = get_tile_color(tile_value);
	x = map->screen.x;
	while (x < map->screen.x + map->tile_size)
	{
		y = map->screen.y;
		while (y < map->screen.y + map->tile_size)
		{
			if (x < map->size && y < map->size && x >= 0 && y >= 0)
				my_mlx_pixel_put(&map->image, x, y, color);
			if (tile_value == 1)
			{
				if (is_edge_of_square(data, map, x, y))
					my_mlx_pixel_put(&map->image, x, y, 0x000000);
			}
			y++;
		}
		x++;
	}
}

static void	ft_init_icon(t_mini_map *map, t_player player, t_player_icon *icon)
{
	icon->angle = atan2(player.dir_y, player.dir_x);
	if (icon->angle < 0)
		icon->angle += 2 * PI;
	icon->size = map->size / 7;
	icon->index = (icon->angle * 64) / (2 * PI);
	icon->index %= 64;
	icon->start.x = map->size / 2 - icon->size / 2;
	icon->start.y = map->size / 2 - icon->size / 2;
}

void	draw_player(t_mini_map *map, t_player player)
{
	t_player_icon	icon;
	int				color;
	int				x;
	int				y;

	ft_init_icon(map, player, &icon);
	x = 0;
	while (x < icon.size)
	{
		y = 0;
		while (y < icon.size)
		{
			icon.src.x = x * map->rotation[icon.index].w / icon.size;
			icon.src.y = y * map->rotation[icon.index].h / icon.size;
			color = get_pixel(&map->rotation[icon.index], icon.src.x,
					icon.src.y);
			if (!is_close_color(0x0000FF, color, 10)
				&& !is_close_color(0x000000, color, 10))
				my_mlx_pixel_put(&map->image, icon.start.x + x, icon.start.y
					+ y, color);
			y++;
		}
		x++;
	}
}

void	draw_map_img(t_data *data, t_mini_map *map, t_player player)
{
	int	tile_value;

	map->center = map->size / 2;
	map->map_tile.x = (int)player.pos_x - map->radius;
	while (map->map_tile.x <= (int)player.pos_x + map->radius)
	{
		map->map_tile.y = (int)player.pos_y - map->radius;
		while (map->map_tile.y <= (int)player.pos_y + map->radius)
		{
			tile_value = get_map_tile(data->map.grid, data->map.height,
					map->map_tile.x, map->map_tile.y);
			if (tile_value >= 0)
			{
				map->screen.x = map->center + (map->map_tile.x - player.pos_x)
					* map->tile_size;
				map->screen.y = map->center + (map->map_tile.y - player.pos_y)
					* map->tile_size;
				draw_squares(data, map, tile_value);
			}
			map->map_tile.y++;
		}
		map->map_tile.x++;
	}
	draw_player(map, player);
}
