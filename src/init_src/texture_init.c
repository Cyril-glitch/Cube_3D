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

void	treat_transparency(t_img *image, int ref_color, unsigned int tolerance)
{
	int		x;
	int		y;
	int		*pixel;

	y = 0;
	while (y < image->h)
	{
		x = 0;
		while (x < image->w)
		{
			pixel = (int *)(image->addr
				+ x * image->line_length
				+ y * (image->bpp / 8));

			if (is_close_color(ref_color, *pixel, tolerance))
				*pixel = 0x00FF00;
			x++;
		}
		y++;
	}
}

void	init_textures(t_data *data)
{
	int		i;
	char	*s;

	data->textures = malloc(sizeof(t_img) * 5);
	if (!data->textures)
		ft_game_exit(data, "textures init");
	i = 0;
	while (i < 5)
		data->textures[i++].img = NULL;
	i = 0;
	while (i < 5)
	{
		s = ft_get_dir_str(&data->map, i);
		data->textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
			&data->textures[i].w, &data->textures[i].h);
		if (!data->textures[i].img)
			ft_game_exit(data, "textures init");
		data->textures[i].addr = mlx_get_data_addr(data->textures[i].img, &data->textures[i].bpp,
				&data->textures[i].line_length, &data->textures[i].endian);
		if (!data->textures[i].addr)
			ft_game_exit(data, "textures init");
		i++;
	}
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

void	init_monster_textures(t_data *data)
{
	int		i;
	int		nb_frames;
	char	*s;

	nb_frames = SPRITE_M_TEXT_NB;
	data->m_textures = malloc(sizeof(t_img) * nb_frames);
	if (!data->t_textures)
		ft_game_exit(data, "monster textures init");
	i = 0;
	while (i < nb_frames)
		data->m_textures[i++].img = NULL;
	i = 0;
	while (i < nb_frames)
	{
		s = get_asset_path(i + 1, "assets/carboard/", "_carboard.xpm");
		if (!s)
			ft_game_exit(data, "monster textures init");
		data->m_textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
			&data->m_textures[i].w, &data->m_textures[i].h);
		free(s);
		if (!data->m_textures[i].img)
			ft_game_exit(data, "monster textures init");
		data->m_textures[i].addr = mlx_get_data_addr(data->m_textures[i].img, &data->m_textures[i].bpp,
				&data->m_textures[i].line_length, &data->m_textures[i].endian);
		if (!data->m_textures[i].addr)
			ft_game_exit(data, "monster textures init");
		treat_transparency(&data->m_textures[i].img, 0, 10);
		i++;
	}
}

void	init_treasure_textures(t_data *data)
{
	int		i;
	int		nb_frames;
	char	*s;

	nb_frames = SPRITE_T_TEXT_NB;
	data->t_textures = malloc(sizeof(t_img) * nb_frames);
	if (!data->t_textures)
		ft_game_exit(data, "treasure textures init");
	i = 0;
	while (i < nb_frames)
		data->t_textures[i++].img = NULL;
	i = 0;
	while (i < nb_frames)
	{
		s = get_asset_path(i + 1, "assets/bonus/", "_medkit.xpm");
		if (!s)
			ft_game_exit(data, "sprites init");
		data->t_textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
			&data->t_textures[i].w, &data->t_textures[i].h);
		free(s);
		if (!data->t_textures[i].img)
			ft_game_exit(data, "treasure textures init");
		data->t_textures[i].addr = mlx_get_data_addr(data->t_textures[i].img, &data->t_textures[i].bpp,
				&data->t_textures[i].line_length, &data->t_textures[i].endian);
		if (!data->t_textures[i].addr)
			ft_game_exit(data, "treasure textures init");
		treat_transparency(&data->t_textures[i].img, 0x00FF00, 10);
		i++;
	}
}

void	init_sprites_textures(t_data *data)
{
	init_treasure_textures(data);
	init_monster_textures(data);
}

void	init_screen(t_data *data)
{
	data->screen.img = mlx_new_image(data->mlx, data->win_size.x, data->win_size.y);
	if (!data->screen.img)
		ft_game_exit(data, "screen init");;
	data->screen.addr = mlx_get_data_addr(data->screen.img, &data->screen.bpp,
			&data->screen.line_length, &data->screen.endian);
	if (!data->screen.addr)
		ft_game_exit(data, "screen init");
	data->screen.w = data->win_size.x;
	data->screen.h = data->win_size.y;
	data->screen.half_w = data->win_size.x / 2;
	data->screen.half_h = data->win_size.y / 2;
}

void	ft_init_backgrd(t_data *data, t_backgrd *b)
{
	int	i;

	b->floor.img = mlx_xpm_file_to_image(data->mlx, "./assets/bonus/sol.xpm", &b->floor.w, &b->floor.h);
	if (!b->floor.img)
		ft_game_exit(data, "background init");
	b->floor.addr = mlx_get_data_addr( b->floor.img, &b->floor.bpp, &b->floor.line_length, &b->floor.endian);
	if (!b->floor.addr)
		ft_game_exit(data, "background init");
	b->ceiling.img = mlx_xpm_file_to_image(data->mlx, "./assets/bonus/plafond.xpm", &b->ceiling.w, &b->ceiling.h);
	if (!b->ceiling.img)
		ft_game_exit(data, "background init");
	b->ceiling.addr = mlx_get_data_addr( b->ceiling.img, &b->ceiling.bpp, &b->ceiling.line_length, &b->ceiling.endian);
	if (!b->ceiling.addr)
		ft_game_exit(data, "background init");
	b->dist = malloc(sizeof(double) * data->win_size.y);
	if (!b->dist)
		ft_game_exit(data, "background init");
	i = 0;
	while (i < data->win_size.y)
	{
		b->dist[i] = (data->win_size.y / 2.0) / (i - data->win_size.y / 2.0);
		i++;
	}
}

void	ft_init_game_over(t_data *data, t_img *over)
{	
	over->img = mlx_xpm_file_to_image(data->mlx,"./assets/bonus/game_over.xpm", &over->w, &over->h);
	if (!over->img)
		ft_game_exit(data, "memory allocation failed (over)");
	over->addr = mlx_get_data_addr(over->img, &over->bpp, &over->line_length, &over->endian);
	if (!over->addr)
		ft_game_exit(data, "memory allocation failed (over)");
}
