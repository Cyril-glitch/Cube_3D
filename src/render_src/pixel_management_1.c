#include "../../inc/cube_3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > img->w || y > img->h)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x > img->w || y > img->h)
		return (0);
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

int	is_close_color(int ref_color, int color)
{
	unsigned int	tolerance;

	tolerance = 190;
	if (ft_abs(getr1(color) - getr1(ref_color)) <= tolerance
		&& ft_abs(getg1(color) - getg1(ref_color)) <= tolerance
		&& ft_abs(getb1(color) - getb1(ref_color)) <= tolerance)
		return (1);
	return (0);
}

int	is_transparent_color(int color)
{
	int	r;
	int	g;
	int	b;

	r = getr1(color);
	g = getg1(color);
	b = getb1(color);
	if (r == 0xff && g == 0x00 && b == 0xdb)
		return (1);
	return (0);
}
