#include "../../inc/cube_3d.h"

static void ft_interpolate(t_data *data, t_point *tex, int x, int y)
{
	int tex_w;
	int tex_h;

	tex_w = data->over.w;
	tex_h = data->over.h;
	tex->x = (x * tex_w) / data->win_size.x;
	tex->y = (y * tex_h) / data->win_size.y;
}

void    ft_render_death(t_data *data, t_img over)
{
	int x;
	int y;
	t_point tex;
	int color;

	y = 0;
	while(y < data->win_size.y)
	{
		x = 0;
		while(x < data->win_size.x)
		{
			ft_interpolate(data, &tex, x, y);
			color = get_pixel(&over, tex.x, tex.y);
			my_mlx_pixel_put(&data->screen, x, y, color);
			x++;
		}
        y++;
	}
}