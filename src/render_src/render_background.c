/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:18:55 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 16:20:04 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_get_fov_pos(t_data *data, t_backgrd *flr)
{
	flr->fov_x_left = data->player.dir_x - data->player.plane_x;
	flr->fov_y_left = data->player.dir_y - data->player.plane_y;
	flr->fov_x_right = data->player.dir_x + data->player.plane_x;
	flr->fov_y_right = data->player.dir_y + data->player.plane_y;
}

static void	ft_get_cur_floor_edge(t_data *data, t_player *player,
		t_backgrd *flr, int y)
{
	double	dist;

	dist = (data->win_size.y / 2.0) / (y - data->win_size.y / 2.0);
	flr->pos_x_left = player->pos_x + dist * flr->fov_x_left;
	flr->pos_y_left = player->pos_y + dist * flr->fov_y_left;
	flr->pos_x_right = player->pos_x + dist * flr->fov_x_right;
	flr->pos_y_right = player->pos_y + dist * flr->fov_y_right;
}

static void	ft_get_scanline_steps(t_data *data, t_backgrd *flr, double *step,
		double *cur)
{
	cur[0] = flr->pos_x_left;
	cur[1] = flr->pos_y_left;
	step[0] = (flr->pos_x_right - flr->pos_x_left) / data->win_size.x;
	step[1] = (flr->pos_y_right - flr->pos_y_left) / data->win_size.x;
}

static void	ft_draw_scanline(t_data *data, t_backgrd *flr, t_img **t, int y)
{
	double	step[2];
	double	map_pos[2];
	int		x;
	int		color[2];

	ft_get_scanline_steps(data, flr, step, map_pos);
	x = 0;
	while (x < data->win_size.x)
	{
		flr->tex_x = (int)((map_pos[0] - (int)map_pos[0]) * t[0]->w);
		flr->tex_y = (int)((map_pos[1] - (int)map_pos[1]) * t[0]->h);
		color[0] = get_pixel(t[0], flr->tex_x, flr->tex_y);
		color[1] = get_pixel(t[1], flr->tex_x, flr->tex_y);
		my_mlx_pixel_put(&data->screen, x, y, color[0]);
		my_mlx_pixel_put(&data->screen, x, data->win_size.y - y - 1, color[1]);
		map_pos[0] += step[0];
		map_pos[1] += step[1];
		x++;
	}
}

void	ft_render_fc(t_data *data, t_backgrd *flr, t_img *floor_t,
		t_img *ceil_t)
{
	int		y;
	t_img	*tex[2];

	tex[0] = floor_t;
	tex[1] = ceil_t;
	ft_get_fov_pos(data, flr);
	y = data->screen.half_h + 1;
	while (y < data->win_size.y)
	{
		ft_get_cur_floor_edge(data, &data->player, flr, y);
		ft_draw_scanline(data, flr, tex, y);
		y++;
	}
}
