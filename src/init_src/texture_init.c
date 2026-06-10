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
	else if (i == 4)
		return ("assets/wolftex2/eagle.xpm");
	return (map->no_path);
}

int	init_textures(t_data *data)
{
	int		i;
	char	*s;

	data->textures = malloc(sizeof(t_img) * (5 + SPRITE_TEXT_TOTAL));
	if (!data->textures)
		return (0);
	i = 0;
	while (i < (5 + SPRITE_TEXT_TOTAL))
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

static char	*get_asset_path(int i, char *path, char *asset_name)
{
	char	*nb;
	char	*dir;
	char	*res;

	nb = ft_itoa(i);
	if (!nb)
		return (NULL);
	dir = ft_strjoin(path, nb);
	free(nb);
	if (!dir)
		return (NULL);
	res = ft_strjoin(dir, asset_name);
	free(dir);
	if (!res)
		return (NULL);
	return (res);
}

int	init_sprite_textures(t_data *data)
{
	int		i;
	char	*s;

	i = 5;
	while (i < (5 + SPRITE_1_TEXT_NB))
	{
		s = get_asset_path(i + 1 - 5, "assets/carboard/", "_carboard.xpm");
		if (!s)
			return (0);
		data->textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
			&data->textures[i].w, &data->textures[i].h);
		if (!data->textures[i].img)
			return (0);
		data->textures[i].addr = mlx_get_data_addr(data->textures[i].img, &data->textures[i].bpp,
				&data->textures[i].line_length, &data->textures[i].endian);
		if (!data->textures[i].addr)
			return (0);
		free(s);
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
		return (0);
	b->floor.addr = mlx_get_data_addr( b->floor.img, &b->floor.bpp, &b->floor.line_length, &b->floor.endian);
	if (!b->floor.addr)
		return (0);
	b->ceiling.img = mlx_xpm_file_to_image(data->mlx, "./assets/bonus/ciel.xpm", &b->ceiling.w, &b->ceiling.h);
	if (!b->ceiling.img)
		return (0);
	b->ceiling.addr = mlx_get_data_addr( b->ceiling.img, &b->ceiling.bpp, &b->ceiling.line_length, &b->ceiling.endian);
	if (!b->ceiling.addr)
		return (0);

	return 1;
}
