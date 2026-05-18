#include "raycasting.h"

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
			if (!is_close_color(color)
				&& pos_x + x < dst->w && pos_y + y < dst->h)
				my_mlx_pixel_put(dst, pos_x + x, pos_y + y, color);
			x++;
		}
		y++;
	}
}
