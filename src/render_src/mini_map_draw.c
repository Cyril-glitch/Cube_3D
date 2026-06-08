#include "../../inc/cube_3d.h"

typedef struct s_player_icon
{
	double	angle;
	int		size;
	int		index;
	t_point	src;
	t_point	start;
}	t_player_icon;

int	get_map_tile(t_data *data, int x, int y)
{
	int	res;
	int	len;

	if (y < 0 || y > 13)
		return (-1);
	len = ft_strlen(data->map.grid[y]);
	if (x < 0 || x >= len)
		return (-1);
	res = data->map.grid[y][x] - '0';
	return (res);
}

int	get_tile_color(int a)
{
	if (a == 0)
		return (0x00D4D4D4);
	else if (a == 1)
		return (0x00555555);
	else if (a == 2)
		return (0x00D4D4D4);
	else if (a == 3)
		return (0x00336699);
	else if (a == 4)
		return (0x00777777);
	return (0x00FF00FF);
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
	if (x == map->screen.x && get_map_tile(data, map->map_tile.x - 1, map->map_tile.y) != 1)
		return (1);
	if (x == map->screen.x + map->tile_size - 1 && get_map_tile(data, map->map_tile.x + 1, map->map_tile.y) != 1)
		return (1);
	if (y == map->screen.y && get_map_tile(data, map->map_tile.x, map->map_tile.y - 1) != 1)
		return (1);
	if (y == map->screen.y + map->tile_size - 1 && get_map_tile(data, map->map_tile.x, map->map_tile.y + 1) != 1)
		return (1);
	return (0);
}

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

void	draw_player(t_mini_map *map, t_player player)
{
	t_player_icon	icon;
	int				color;
	int				x;
	int				y;

	icon.angle = atan2(player.dir_y, player.dir_x);
	if (icon.angle < 0)
		icon.angle += 2 * PI;
	icon.size = map->size / 7;
	icon.index = (icon.angle * 64) / (2 * PI);
	icon.index %= 64;
	icon.start.x = map->size / 2 - icon.size / 2;
	icon.start.y = map->size / 2 - icon.size / 2;
	x = 0;
	while (x < icon.size)
	{
		y = 0;
		while (y < icon.size)
		{
			icon.src.x = x * map->rotation[icon.index].w / icon.size;
			icon.src.y = y * map->rotation[icon.index].h / icon.size;
			color = get_pixel(&map->rotation[icon.index], icon.src.x, icon.src.y);
			if (!is_close_color(0x0000FF, color) && !is_close_color(0x000000, color))
				my_mlx_pixel_put(&map->image, icon.start.x + x, icon.start.y + y, color);
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
			tile_value = get_map_tile(data, map->map_tile.x, map->map_tile.y);
			if (tile_value >= 0)
			{
				map->screen.x = map->center + (map->map_tile.x - player.pos_x) * map->tile_size;
				map->screen.y = map->center + (map->map_tile.y - player.pos_y) * map->tile_size;
				draw_squares(data, map, tile_value);
			}
			map->map_tile.y++;
		}
		map->map_tile.x++;
	}
	draw_player(map, player);
}
