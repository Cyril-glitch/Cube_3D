#include "../../inc/cube_3d.h"

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

int	ft_init_backgrd(t_data *data, t_backgrd *b)
{
	b->floor.img = mlx_xpm_file_to_image(data->mlx, "./assets/bonus/floor.xpm", &b->floor.w, &b->floor.h);
	if (!b->floor.img)
		return 0;
	b->floor.addr = mlx_get_data_addr( b->floor.img, &b->floor.bpp, &b->floor.line_length, &b->floor.endian);
	if (!b->floor.addr)
		return 0;
	b->cieling.img = mlx_xpm_file_to_image(data->mlx, "./assets/bonus/ciel.xpm", &b->cieling.w, &b->cieling.h);
	if (!b->cieling.img)
		return 0;
	b->cieling.addr = mlx_get_data_addr( b->cieling.img, &b->cieling.bpp, &b->cieling.line_length, &b->cieling.endian);
	if (!b->cieling.addr)
		return 0;

	return 1;
}
