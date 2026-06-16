#include "../../inc/cube_3d.h"

void    ft_wall_draw(t_ray *ray, t_data *data)
{
	int x;
	int y;
	int	tex_x;
	int	tex_y;
	int color;

	x = 0;
	while(x < data->win_size.x)
	{
		/*
		while (y < ray[x].draw_start)
		{
			color = data->map.ceiling_color;
			my_mlx_pixel_put(&data->screen, x, y, color);
			y++;
		}
		*/
		y = ray[x].draw_start;
		while(y < ray[x].draw_end)
		{
			tex_x = ray[x].tex_x;
			tex_y = (int)ray[x].tex_pos & (data->textures[ray[x].tex_num].h - 1);
			ray[x].tex_pos += ray[x].step;
			color = get_pixel(&data->textures[ray[x].tex_num], tex_x, tex_y);
			if (ray[x].side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(&data->screen, x, y, color);
			y++;
		}
		/*
		while (y < data->win_size.y)
		{
			color = data->map.floor_color;
			my_mlx_pixel_put(&data->screen, x, y, color);
			y++;
		}
		*/
		x++;
	}
}

void	ft_render_map(t_data *data, t_mini_map *map)
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
			my_mlx_pixel_put(&data->screen, x, y, color);
			y++;
		}
		x++;
	}
}

void    ft_render_draw(t_ray *ray, t_data *data)
{
	(void)ray;
	double t0 = get_time(data->start);
	ft_render_fc(data, &data->bgrd, &data->bgrd.floor, &data->bgrd.ceiling);
	printf("floor / ceiling: %.3f ms\n", get_time(data->start) - t0);
	t0 = get_time(data->start);
	ft_wall_draw(ray, data);
	printf("wall_draw: %.3f ms\n", get_time(data->start) - t0);
	t0 = get_time(data->start);
	if (!draw_sprites(data, &data->player))
		return ;
	printf("sprites: %.3f ms\n", get_time(data->start) - t0);
	ft_draw_health(data, data->player.health);
	if (data->mini_map.exist)
	{
		ft_memset(data->mini_map.image.addr, 0, data->mini_map.size * data->mini_map.size * 4);
		draw_map_img(data, &data->mini_map, data->player);
		ft_render_map(data, &data->mini_map);
	}
}