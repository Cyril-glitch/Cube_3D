#include "../../inc/cube_3d.h"

void	ft_look_left(t_data *data)
{
	t_player	*player = &data->player;
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x *  cos(-player->rot_speed) - player->dir_y * sin(-player->rot_speed);
	player->dir_y = old_dir_x *  sin(-player->rot_speed) + player->dir_y * cos(-player->rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-player->rot_speed) - player->plane_y * sin(-player->rot_speed);
	player->plane_y = old_plane_x * sin(-player->rot_speed) + player->plane_y * cos(-player->rot_speed);
}

void	ft_look_right(t_data *data)
{
	t_player	*player = &data->player;
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x *  cos(player->rot_speed) - player->dir_y * sin(player->rot_speed);
	player->dir_y = old_dir_x *  sin(player->rot_speed) + player->dir_y * cos(player->rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(player->rot_speed) - player->plane_y * sin(player->rot_speed);
	player->plane_y = old_plane_x * sin(player->rot_speed) + player->plane_y * cos(player->rot_speed);
}