#include "../../inc/cube_3d.h"

static char *ft_get_dir_str(t_map *map, int i)
{
	if (i == 0)
		return (map->no_path);
	else if (i == 1)
		return (map->so_path);
	else if (i == 2)
		return (map->ea_path);
	else if (i == 3)
		return (map->we_path);
	else
		return ("./assets/wolftex2/barrel.xpm");
}

int	init_textures(t_data *data)
{
	int		i;
	char	*s;

	data->textures = malloc(sizeof(t_img) * 5);
	if (!data->textures)
		return (0);
	i = 0;
	while (i < 5)
	{
		data->textures[i].img = NULL;
		data->textures[i].addr = NULL;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		s = ft_get_dir_str(&data->map, i);
		data->textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
			&data->textures[i].w, &data->textures[i].h);
		if (!data->textures[i].img)
			return (0);
		data->textures[i].addr = mlx_get_data_addr(data->textures[i].img, &data->textures[i].bpp,
				&data->textures[i].line_length, &data->textures[i].endian);
		if (!data->textures[i].addr)
			return (0);
		i++;
	}
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

void   ft_init_bot_tex(t_data *data)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	image->img = mlx_xpm_file_to_image(data->mlx, "./assets/bonus/boo.xpm", &image->w, &image->h);
	if (!image->img)
		ft_game_exit(data, "cannot load image (bot)");
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->line_length, &image->endian);
	if (!image->addr)
		ft_game_exit(data, "cannot load image (bot)");
	data->monster.sprite.texture = image;
}
