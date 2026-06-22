#include "../../inc/cube_3d.h"

int	init_arrow(t_data *data, t_mini_map *map)
{
	map->arrow.img = mlx_xpm_file_to_image(data->mlx,
			"assets/map_textures/arrow1.xpm", &map->arrow.w, &map->arrow.h);
	if (!map->arrow.img)
		return (0);
	map->arrow.addr = mlx_get_data_addr(map->arrow.img, &map->arrow.bpp,
			&map->arrow.line_length, &map->arrow.endian);
	if (!map->arrow.addr)
		return (0);
	return (1);
}

t_img	rotate_sprite(t_data *data, t_mini_map *map, t_img src, double angle)
{
	t_img	dest;

	dest.img = mlx_new_image(data->mlx, map->arrow.w, map->arrow.h);
	if (!dest.img)
		return ((t_img){0});
	dest.addr = mlx_get_data_addr(dest.img, &dest.bpp, &dest.line_length,
			&dest.endian);
	if (!dest.addr)
		return ((t_img){0});
	dest.w = src.w;
	dest.h = src.h;
	ft_memset(dest.addr, 0, dest.line_length * dest.h);
	fill_rotated_sprite(&dest, src, angle);
	return (dest);
}

int	generate_rotated_arrows(t_data *data, t_mini_map *map)
{
	double	angle;
	int		i;

	i = 0;
	while (i < 64)
	{
		angle = (2 * PI * i) / 64;
		map->rotation[i] = rotate_sprite(data, map, map->arrow, angle);
		if (map->rotation[i].img == NULL)
			return (0);
		i++;
	}
	return (1);
}

void	init_mini_map(t_data *data, t_mini_map *map)
{
	map->exist = 1;
	map->size = data->win_size.x / 5;
	map->image.w = map->size;
	map->image.h = map->size;
	if (map->size < 32 || map->size > data->win_size.y / 2)
	{
		map->exist = 0;
		return ;
	}
	map->image.img = mlx_new_image(data->mlx, map->size, map->size);
	if (!map->image.img)
		ft_game_exit(data, "mini map init");
	map->image.addr = mlx_get_data_addr(map->image.img, &map->image.bpp,
			&map->image.line_length, &map->image.endian);
	if (!map->image.addr)
		ft_game_exit(data, "mini map init");
	map->tile_size = map->size / 13;
	map->radius = 7;
	if (!init_arrow(data, map))
		ft_game_exit(data, "mini map init");
	if (!generate_rotated_arrows(data, map))
		ft_game_exit(data, "mini map init");
}
