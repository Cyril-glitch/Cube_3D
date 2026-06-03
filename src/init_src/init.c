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
	data->screen.addr = NULL;
	data->textures = NULL;
	data->ray = NULL;
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
	data->player.plane_x = (-data->player.dir_y) * 0.66;
	data->player.plane_y = data->player.dir_x * 0.66;
}

void	init_keys(t_data *data)
{
	data->keys.w = 0;
	data->keys.a = 0;
	data->keys.s = 0;
	data->keys.d = 0;
	data->keys.right = 0;
	data->keys.left = 0;
}

int	init_mlx_and_ray(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	mlx_get_screen_size(data->mlx, &data->win_size.x, &data->win_size.y);
	printf("win_size_x : %d, win_size_y : %d\n", data->win_size.x, data->win_size.y);
	data->mlx_win = mlx_new_window(data->mlx, data->win_size.x,
			data->win_size.y, "Raycaster");
	if (!data->mlx_win)
		return (0);
	data->ray = malloc(sizeof(t_ray) * data->win_size.x);
	if (!data->ray)
		return (0);
	return (1);
}

int	init_textures(t_data *data)
{
	int	i;
	data->textures = malloc(sizeof(t_img) * 4);
	if (!data->textures)
		return (0);
	i = 0;
	while (i < 4)
	{
		data->textures[i].img = NULL;
		data->textures[i].addr = NULL;
		i++;
	}

	data->textures[0].img = mlx_xpm_file_to_image(data->mlx, data->map.no_path,
			&data->textures[0].w, &data->textures[0].h);
	if (!data->textures[0].img)
		return (0);
	data->textures[0].addr = mlx_get_data_addr(data->textures[0].img, &data->textures[0].bpp,
			&data->textures[0].line_length, &data->textures[0].endian);
	if (!data->textures[0].addr)
		return (0);

	data->textures[1].img = mlx_xpm_file_to_image(data->mlx, data->map.so_path,
			&data->textures[1].w, &data->textures[1].h);
	if (!data->textures[1].img)
		return (0);
	data->textures[1].addr = mlx_get_data_addr(data->textures[1].img, &data->textures[1].bpp,
			&data->textures[1].line_length, &data->textures[1].endian);
	if (!data->textures[1].addr)
		return (0);

	data->textures[2].img = mlx_xpm_file_to_image(data->mlx, data->map.we_path,
			&data->textures[2].w, &data->textures[2].h);
	if (!data->textures[2].img)
		return (0);
	data->textures[2].addr = mlx_get_data_addr(data->textures[2].img, &data->textures[2].bpp,
			&data->textures[2].line_length, &data->textures[2].endian);
	if (!data->textures[2].addr)
		return (0);

	data->textures[3].img = mlx_xpm_file_to_image(data->mlx, data->map.ea_path,
			&data->textures[3].w, &data->textures[3].h);
	if (!data->textures[3].img)
		return (0);
	data->textures[3].addr = mlx_get_data_addr(data->textures[3].img, &data->textures[3].bpp,
			&data->textures[3].line_length, &data->textures[3].endian);
	if (!data->textures[3].addr)
		return (0);
	
	return (1);
}

int	init_screen(t_data *data)
{
	data->screen.img = mlx_new_image(data->mlx, data->win_size.x, data->win_size.y);
	if (!data->screen.img)
		return (0);
	data->screen.addr = mlx_get_data_addr(data->screen.img, &data->screen.bpp,
			&data->screen.line_length, &data->screen.endian);
	if (!data->screen.addr)
		return (0);
	data->screen.w = data->win_size.x;
	data->screen.h = data->win_size.y;
	return (1);
}
