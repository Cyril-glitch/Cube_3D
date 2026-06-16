#include "../../inc/cube_3d.h"

/*static void	ft_get_tex_pos(t_backgrd *flr, t_img tex, int x,int w)
{
	double	weight;
	double	cur_x;
	double	cur_y;

	weight = (double)x / (double)(w - 1);
	cur_x = (1.0 - weight) * flr->pos_x_left + weight * flr->pos_x_right;
	cur_y = (1.0 - weight) * flr->pos_y_left + weight * flr->pos_y_right;
	flr->tex_x = (int)((cur_x - (int)cur_x) * tex.w) % tex.w;
	flr->tex_y = (int)((cur_y - (int)cur_y) * tex.h) % tex.h;	
	if (flr->tex_x < 0)
		flr->tex_x = 0;
	if (flr->tex_y < 0)
		flr->tex_y = 0;
}*/

static void	ft_get_floor_edge(t_player *player, t_backgrd *flr, int y)
{
	double dist;

	dist = flr->dist[y];
	flr->pos_x_left = player->pos_x + dist * flr->dir_x_left;
	flr->pos_y_left = player->pos_y + dist * flr->dir_y_left;
	flr->pos_x_right = player->pos_x + dist * flr->dir_x_right;
	flr->pos_y_right = player->pos_y + dist * flr->dir_y_right;
}

void	ft_render_fc(t_data *data, t_backgrd *flr, t_img *floor_tex, t_img *cieling_tex)
{
	int x;
	int y;
	int color_floor;
	int color_ceil;
	double cur_x;
	double cur_y;
	double step_x;
	double step_y;
	double frac_x;
	double frac_y;

	flr->dir_x_left = data->player.dir_x - data->player.plane_x;
	flr->dir_y_left = data->player.dir_y - data->player.plane_y;
	flr->dir_x_right = data->player.dir_x + data->player.plane_x;
	flr->dir_y_right = data->player.dir_y + data->player.plane_y;
	y = (data->screen.half_h) + 1;
	while (y < data->win_size.y)
	{
		ft_get_floor_edge(&data->player, flr, y);
		cur_x = flr->pos_x_left;
		cur_y = flr->pos_y_left;
		step_x = (flr->pos_x_right - flr->pos_x_left)
			/ data->win_size.x;
		step_y = (flr->pos_y_right - flr->pos_y_left)
			/ data->win_size.x;
		x = 0;
		while (x < data->win_size.x)
		{
			frac_x = cur_x - (int)cur_x;
			frac_y = cur_y - (int)cur_y;

			flr->tex_x = (int)(frac_x * floor_tex->w);
			flr->tex_y = (int)(frac_y * floor_tex->h);

			color_floor = get_pixel(floor_tex, flr->tex_x, flr->tex_y);
			color_ceil = get_pixel(cieling_tex, flr->tex_x, flr->tex_y);

			my_mlx_pixel_put(&data->screen, x, y, color_floor);
			my_mlx_pixel_put(&data->screen,
							x,
							data->win_size.y - y - 1,
							color_ceil);

			cur_x += step_x;
			cur_y += step_y;

			x++;
		}
		y++;
	}
}
