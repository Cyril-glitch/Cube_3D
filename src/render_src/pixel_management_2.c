#include "../../inc/cube_3d.h"

void	put_img(t_img *dst, t_img *src, int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < src->h)
	{
		while (pos_y + y < 0)
			y++;
		x = 0;
		while (x < src->w)
		{
			while (pos_x + x < 0)
				x++;
			color = get_pixel(src, x, y);
			if (pos_y + y < dst->h && pos_x + x < dst->w)
				my_mlx_pixel_put(dst, pos_x + x, pos_y + y, color);
			x++;
		}
		y++;
	}
}

void	put_tr(t_img *dst, t_img *src, int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < src->h)
	{
		while (pos_y + y < 0)
			y++;
		x = 0;
		while (x < src->w)
		{
			while (pos_x + x < 0)
				x++;
			color = get_pixel(src, x, y);
			if (!is_transparent_color(color)
				&& pos_x + x < dst->w && pos_y + y < dst->h)
				my_mlx_pixel_put(dst, pos_x + x, pos_y + y, color);
			x++;
		}
		y++;
	}
}

void	put_tr2(t_img *dst, t_img *src, int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < src->h)
	{
		while (pos_y + y < 0)
			y++;
		x = 0;
		while (x < src->w)
		{
			while (pos_x + x < 0)
				x++;
			color = get_pixel(src, x, y);
			if (!is_close_color(0x000000, color)
				&& pos_x + x < dst->w && pos_y + y < dst->h)
				my_mlx_pixel_put(dst, pos_x + x, pos_y + y, color);
			x++;
		}
		y++;
	}
}

int ft_anti_aliasing(int color)
{
	int r;
	int g;
	int b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;

	return ((g > 30 && g > r * 1.4 && g > b * 1.4));
}
