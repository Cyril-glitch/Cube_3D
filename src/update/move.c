#include "../inc/cube_3d.h"

void	move_up(t_data *data)
{
	t_player	*player = &data->player;
	double		new_pos_x;
	double		new_pos_y;

	new_pos_y = player->pos_y + player->dir_y * (player->move_speed + WALL_PADDING);
	new_pos_x = player->pos_x + player->dir_x * (player->move_speed + WALL_PADDING);
	if (get_map_tile(data, (int)new_pos_y, (int)player->pos_x) >= 0 &&
		data->map.grid[(int)new_pos_y][(int)player->pos_x] == '0')
		player->pos_y += player->dir_y * player->move_speed;
	if (get_map_tile(data, (int)player->pos_y, (int)new_pos_x) >= 0 &&
		data->map.grid[(int)(player->pos_y)][(int)new_pos_x] == '0')
		player->pos_x += player->dir_x * player->move_speed;
}

void	move_down(t_data *data)
{
	t_player	*player = &data->player;

	double		new_pos_x;
	double		new_pos_y;

	new_pos_y = player->pos_y + player->dir_y * (player->move_speed + WALL_PADDING);
	new_pos_x = player->pos_x + player->dir_x * (player->move_speed + WALL_PADDING);
	if (get_map_tile(data, (int)new_pos_y, (int)player->pos_x) >= 0 &&
		data->map.grid[(int)new_pos_y][(int)player->pos_x] == '0')
		player->pos_y -= player->dir_y * player->move_speed;
	if (get_map_tile(data, (int)player->pos_y, (int)new_pos_x) >= 0 &&
		data->map.grid[(int)(player->pos_y)][(int)new_pos_x] == '0')
		player->pos_x -= player->dir_x * player->move_speed;
}

void	move_left(t_data *data)
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

void	move_right(t_data *data)
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