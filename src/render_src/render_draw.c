#include "../inc/cube_3d.h"

int	choose_color(int n)
{
	if (n == 1)
		return (0xf54242);
	if (n == 2)
		return (0x5df542);
	if (n == 3)
		return (0x4542f5);
	if (n == 4)
		return (0xf542d7);
	if (n == 5)
		return (0xf5d142);
	return (0x0d0d0d);
}

int    ft_set_color(t_ray ray, char **map)
{
	int color;

	color = choose_color(map[ray.map_y][ray.map_x] - 48);
	if (ray.side)
		color /= 2;
	return color;
}

void    ft_wall_draw(t_ray *ray, t_var *var)
{
	int x;
	int y;
	int	tex_x;
	int	tex_y;
	int color;

	x = 0;
	y = 0;
	while(x < var->win_size.x)
	{
		y = 0;
		while (y < ray[x].draw_start)
		{
			color = 0x750000;
			my_mlx_pixel_put(&var->screen, x, y, color);
			y++;
		}
		y = ray[x].draw_start;
		while(y < ray[x].draw_end)
		{
			tex_x = ray[x].tex_x;
			tex_y = (int)ray[x].tex_pos & (var->textures[ray[x].tex_num].h - 1);
			ray[x].tex_pos += ray[x].step;
			color = get_pixel(&var->textures[ray[x].tex_num], tex_x, tex_y);
			if (ray[x].side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(&var->screen, x, y, color);
			y++;
		}
		while (y < var->win_size.y)
		{
			color = 0x616161;
			my_mlx_pixel_put(&var->screen, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_render_map(t_var *var, t_map *map)
{
	int	x;
	int	y;
	int	color;

	x = 10;
	while (x < map->size + 10)
	{
		y = 10;
		while (y < map->size + 10)
		{
			color = get_pixel(&map->image, x - 10, y - 10);
			/*ft_putnbr_base((long)color, "0123456789ABCDEF");
			write(1, "\n", 1);*/
			my_mlx_pixel_put(&var->screen, x, y, color);
			y++;
		}
		x++;
	}
}

void    ft_render_draw(t_ray *ray, t_var *var)
{
	ft_wall_draw(ray, var);
	if (var->mini_map.exist)
	{
		ft_memset(var->mini_map.image.addr, 0, var->mini_map.size * var->mini_map.size * 4);
		draw_map_img(var, &var->mini_map, var->player);
		ft_render_map(var, &var->mini_map);
	}
}