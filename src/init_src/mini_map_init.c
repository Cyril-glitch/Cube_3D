#include "../../inc/cube_3d.h"

typedef struct s_rotation
{
	int			center; // center of a square image (image width / 2)
	double		cos_a; // cosinus de l'angle
	double		sin_a; // sinus de l'angle
	t_point		dst; // point dans l'image de destination
	t_point		src; // point dans l'image source
	t_point		d; // vecteur du centre vers le point de destination
}	t_rotation;


int	init_arrow(t_data *data, t_mini_map *map)
{
	map->arrow.img = mlx_xpm_file_to_image(data->mlx, "assets/map_textures/arrow1.xpm",
			&map->arrow.w, &map->arrow.h);
	if (!map->arrow.img)
		return (0);
	map->arrow.addr = mlx_get_data_addr(map->arrow.img, &map->arrow.bpp,
			&map->arrow.line_length, &map->arrow.endian);
	if (!map->arrow.addr)
		return (0);
	return (1);
}

void	fill_rotated_sprite(t_img *dest, t_img arrow, double angle)
{
	t_rotation	rotation;
	int			color;

	rotation.center = arrow.w / 2;
	rotation.cos_a = cos(angle);
	rotation.sin_a = sin(angle);
	rotation.dst.y = 0;
	while (rotation.dst.y < dest->h)
	{
		rotation.dst.x = 0;
		while (rotation.dst.x < dest->w)
		{
			rotation.d.x = rotation.dst.x - rotation.center;
			rotation.d.y = rotation.dst.y - rotation.center;
			rotation.src.x = rotation.d.x * rotation.cos_a + rotation.d.y * rotation.sin_a;
			rotation.src.y = -rotation.d.x * rotation.sin_a + rotation.d.y * rotation.cos_a;
			rotation.src.x += rotation.center;
			rotation.src.y += rotation.center;
			if (rotation.src.x >= 0 && rotation.src.x < arrow.w
				&& rotation.src.y >= 0 && rotation.src.y < arrow.h)
			{
				color = get_pixel(&arrow, rotation.src.x, rotation.src.y);
				my_mlx_pixel_put(dest, rotation.dst.x, rotation.dst.y, color);
			}
			rotation.dst.x++;
		}
		rotation.dst.y++;
	}
}

t_img	rotate_sprite(t_data *data, t_mini_map *map, t_img src, double angle)
{
	t_img	dest;

	dest.img = mlx_new_image(data->mlx, map->arrow.w, map->arrow.h);
	if (!dest.img)
		return ((t_img){0});
	dest.addr = mlx_get_data_addr(dest.img, &dest.bpp,
			&dest.line_length, &dest.endian);
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

int	init_mini_map(t_data *data, t_mini_map *map)
{
	map->image.img = NULL;
	map->image.addr = NULL;
	map->exist = 1;
	map->size = data->win_size.x / 5;
	map->image.w = map->size;
	map->image.h = map->size;
	if (map->size < 32 || map->size > data->win_size.y / 2)
	{
		map->exist = 0;
		return (1);
	}
	map->image.img = mlx_new_image(data->mlx, map->size, map->size);
	if (!map->image.img)
		return (0);
	map->image.addr = mlx_get_data_addr(map->image.img, &map->image.bpp,
			&map->image.line_length, &map->image.endian);
	if (!map->image.addr)
		return (0);
	map->tile_size = map->size / 13;
	map->radius = 7;
	if (!init_arrow(data, map))
		return (0);
	if (!generate_rotated_arrows(data, map))
		return (0);
	return (1);
}
