#include "../../inc/cube_3d.h"

void	ft_init_fc_tex(t_data *data, t_img *image)
{
	image = malloc(sizeof(t_img));
	image->img = mlx_xpm_file_to_image(data->mlx, "./assets/bonus/wall.xpm", &image->w, &image->h);
	image->addr = mlx_get_data_addr( &image->img, &image->bpp, &image->line_length, &image->endian);
}

static void	ft_get_floor_dist(t_floor *flr, int y)
{
	flr->dist = (WIN_H / 2.0) / (y - WIN_H / 2.0);
}

static void	ft_get_floor_edge(t_player *player, t_floor *flr)
{
	flr->dir_x_left = player->dir_x - player->plane_x;
	flr->dir_y_left = player->dir_y - player->plane_y;
	flr->dir_x_right = player->dir_x + player->plane_x;
	flr->dir_y_right = player->dir_y + player->plane_y;
	flr->pos_x_left = player->pos_x + flr->dist * flr->dir_x_left;
	flr->pos_y_left = player->pos_y + flr->dist * flr->dir_y_left;
	flr->pos_x_right = player->pos_x + flr->dist * flr->dir_x_right;
	flr->pos_y_right = player->pos_y + flr->dist * flr->dir_y_right;
}

static void	ft_get_tex_pos(t_floor *flr, t_img tex, int x)
{
	double	weight;
	double	cur_x;
	double	cur_y;

	weight = (double)x / (double)WIN_W;
	cur_x = (1.0 - weight) * flr->pos_x_left + weight * flr->pos_x_right;
	cur_y = (1.0 - weight) * flr->pos_y_left + weight * flr->pos_y_right;
	flr->tex_x = (int)((cur_x - (int)cur_x) * tex.w);
	flr->tex_y = (int)((cur_y - (int)cur_y) * tex.h);
	if (flr->tex_x < 0)
		flr->tex_x = 0;
	if (flr->tex_y < 0)
		flr->tex_y = 0;
}

void	ft_render_fc(t_data *data, t_floor  *flr, t_img *floor_tex, t_img *cieling_tex)
{
	(void)cieling_tex;
	int x;
	int y;

	int color_floor;
	int color_ceil;


	y = WIN_H / 2;
	while (y < WIN_H)
	{
		ft_get_floor_dist(flr, y);
		ft_get_floor_edge(&data->player, flr);
		x = 0;
		while (x < WIN_W)
		{
			ft_get_tex_pos(flr, *floor_tex, x);
			color_floor = get_pixel(floor_tex, flr->tex_x, flr->tex_y);
			color_ceil = get_pixel(cieling_tex, flr->tex_x, flr->tex_y);
			my_mlx_pixel_put(&data->screen, x, y, color_floor);
			my_mlx_pixel_put(&data->screen, x, WIN_H - y - 1, color_ceil);
			x++;
		}
		y++;
	}
}