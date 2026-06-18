#include "../../inc/cube_3d.h"

void	init_map_size(t_map *map)
{
	int	x;
	int	y;
	int	tmp;
	char	**grid;

	tmp = 0;
	grid = map->grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			x++;
		}
		tmp = fmax((int)x, (int)tmp);
		y++;
	}
	map->width = tmp;
	map->height = y;
}

void	init_global(t_data *data, char **av)
{
	init_null(data);
	ft_parser(data, &data->map, av[1]);
	init_map_size(&data->map);
	data->start = get_time(0);
	data->time = data->start;
	init_mlx_and_ray(data);
	init_screen(data);
	init_textures(data);
	init_sprites_textures(data);
	ft_init_backgrd(data, &data->bgrd);
	ft_init_global_sprites_tab(data);
	ft_init_stats(data, &data->player.hp);
	ft_init_game_over(data, &data->over);
	init_offsets(data);
	init_mini_map(data, &data->mini_map);
	init_doors(data, data->map.grid);
	ft_init_bfs(data, data->monsters);
	init_player_dir(data);
	init_keys(data);
	init_hooks(data);
}
