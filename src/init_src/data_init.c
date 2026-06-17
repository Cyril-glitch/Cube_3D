#include "../../inc/cube_3d.h"

void    ft_init_data(t_data *data)
{
        ft_bzero(data, sizeof(*data));
        if (!data)
                ft_game_exit(data, "memory allocation failed.\n");        
}

static void	init_null_map(t_map *map)
{
	map->grid = NULL;
	map->no_path = NULL;
	map->so_path = NULL;
	map->ea_path = NULL;
	map->we_path = NULL;
	map->ceiling_color = 0;
	map->floor_color = 0;
}

static void	init_null_mini_map(t_mini_map *mini_map)
{
	int	i;

	mini_map->image.img = NULL;
	mini_map->arrow.img = NULL;
	i = 0;
	while (i < 64)
		mini_map->rotation[i++].img = NULL;
}

void	init_null(t_data *data)
{
	ft_init_data(data);
	data->line = NULL;
	data->mlx = NULL;
	data->mlx_win = NULL;
	init_null_map(&data->map);
	init_null_mini_map(&data->mini_map);
	data->screen.img = NULL;
	data->textures = NULL;
	data->t_textures = NULL;
	data->m_textures = NULL;
	data->t_sprites = NULL;
	data->m_sprites = NULL;
	data->sprites = NULL;
	data->monsters = NULL;
	data->doors = NULL;
	data->bgrd.floor.img = NULL;
	data->bgrd.ceiling.img = NULL;
	data->bgrd.dist = NULL;
	data->ray = NULL;
	//data->frame_time = 2000 / 60;
}

void	init_player_dir(t_data *data)
{
	if (data->player.dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
	else if (data->player.dir == 'S')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
	else if (data->player.dir == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
	else if (data->player.dir == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
	data->player.plane_x = (-data->player.dir_y) * 0.66;
	data->player.plane_y = data->player.dir_x * 0.66;
}

void	init_keys(t_data *data)
{
	data->keys.w = 0;
	data->keys.a = 0;
	data->keys.s = 0;
	data->keys.d = 0;
	data->keys.e = 0;
	data->keys.right = 0;
	data->keys.left = 0;
}

void	ft_init_stats(t_data *data)
{
	data->player.health = 100;
}
