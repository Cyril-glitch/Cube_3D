#include "../../inc/cube_3d.h"

void    ft_init_data(t_data *data)
{
        ft_bzero(data, sizeof(*data));
        if (!data)
                ft_game_exit(data, "memory allocation failed.\n");        
}

void	init_null(t_data *data)
{
	int	i;

	data->mlx = NULL;
	data->mlx_win = NULL;
	data->map.grid = NULL;
	data->mini_map.image.img = NULL;
	data->mini_map.arrow.img = NULL;
	i = 0;
	while (i < 64)
		data->mini_map.rotation[i++].img = NULL;
	data->screen.img = NULL;
	data->bgrd.floor.img = NULL;
	data->bgrd.ceiling.img = NULL;
	data->textures = NULL;
	data->ray = NULL;
	data->sprites = NULL;
	data->doors = NULL;
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
	data->keys.r = 0;
	data->keys.right = 0;
	data->keys.left = 0;
}


