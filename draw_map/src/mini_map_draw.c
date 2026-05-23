#include "raycasting.h"

int	get_map_tile(t_var *var, int x, int y)
{
	int	res;

	if (x < 0 || x >= var->map_width)
		return (-1);
	if (y < 0 || y >= var->map_height)
		return (-1);
	res = var->map[y][x] - '0';
	return (res);
}

int	get_tile_color(int a)
{
	if (a == 0)
		return (0x00D4D4D4); // jaune clair
	else if (a == 1)
		return (0x00555555); // mur gris foncé
	else if (a == 2)
		return (0x008B4513); // mur marron
	else if (a == 3)
		return (0x00336699); // mur bleu
	else if (a == 4)
		return (0x00777777); // mur pierre
	return (0x00FF00FF); // fallback magenta
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

int	is_edge_of_square(t_var *var, t_map *map, int x, int y)
{
	if (x == map->screen.x && get_map_tile(var, map->map_tile.x - 1, map->map_tile.y) != 1)
		return (1);
	if (x == map->screen.x + map->tile_size - 1 && get_map_tile(var, map->map_tile.x + 1, map->map_tile.y) != 1)
		return (1);
	if (y == map->screen.y && get_map_tile(var, map->map_tile.x, map->map_tile.y - 1) != 1)
		return (1);
	if (y == map->screen.y + map->tile_size - 1 && get_map_tile(var, map->map_tile.x, map->map_tile.y + 1) != 1)
		return (1);
	return (0);
}

void	draw_squares(t_var *var, t_map *map, int tile_value)
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
				if (is_edge_of_square(var, map, x, y))
					my_mlx_pixel_put(&map->image, x, y, 0x000000);
			}
			y++;
		}
		x++;
	}
}

void	draw_player(t_map *map, t_player player)
{
	double	angle;
	int		size;
	int		index;
	int		color;
	int		x;
	int		y;
	t_point	src;
	t_point	start;

	angle = atan2(player.dir_y, player.dir_x);
	if (angle < 0)
		angle += 2 * PI;
	size = map->size / 7;
	index = (angle * 64) / (2 * PI);
	index %= 64;
	start.x = map->size / 2 - size / 2;
	start.y = map->size / 2 - size / 2;
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			src.x = x * map->rotation[index].w / size;
			src.y = y * map->rotation[index].h / size;
			color = get_pixel(&map->rotation[index], src.x, src.y);
			if (!is_close_color(0x0000FF, color) && !is_close_color(0x000000, color))
				my_mlx_pixel_put(&map->image, start.x + x, start.y + y, color);
			y++;
		}
		x++;
	}
}

void	draw_map_img(t_var *var, t_map *map, t_player player)
{
	int	tile_value;

	map->center = map->size / 2;
	map->map_tile.x = (int)player.pos_x - map->radius;
	while (map->map_tile.x <= (int)player.pos_x + map->radius)
	{
		map->map_tile.y = (int)player.pos_y - map->radius;
		while (map->map_tile.y <= (int)player.pos_y + map->radius)
		{
			tile_value = get_map_tile(var, map->map_tile.x, map->map_tile.y);
			if (tile_value >= 0)
			{
				map->screen.x = map->center + (map->map_tile.x - player.pos_x) * map->tile_size;
				map->screen.y = map->center + (map->map_tile.y - player.pos_y) * map->tile_size;
				draw_squares(var, map, tile_value);
			}
			map->map_tile.y++;
		}
		map->map_tile.x++;
	}
	draw_player(map, player);
}
