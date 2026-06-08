#include "../../inc/cube_3d.h"

void	move_up(t_data *data)
{
	t_player	*player = &data->player;
	double		new_pos_x;
	double		new_pos_y;

	new_pos_y = player->pos_y + player->dir_y * (player->move_speed + WALL_PADDING);
	new_pos_x = player->pos_x + player->dir_x * (player->move_speed + WALL_PADDING);
	if (data->map.grid[(int)new_pos_y][(int)player->pos_x] == '0')
		player->pos_y += player->dir_y * player->move_speed;
	if (data->map.grid[(int)(player->pos_y)][(int)new_pos_x] == '0')
		player->pos_x += player->dir_x * player->move_speed;
}

void	move_down(t_data *data)
{
	t_player	*player = &data->player;

	double		new_pos_x;
	double		new_pos_y;

	new_pos_y = player->pos_y - player->dir_y * (player->move_speed + WALL_PADDING);
	new_pos_x = player->pos_x - player->dir_x * (player->move_speed + WALL_PADDING);	
	if (data->map.grid[(int)new_pos_y][(int)player->pos_x] == '0')
		player->pos_y -= player->dir_y * player->move_speed;
	if (data->map.grid[(int)(player->pos_y)][(int)new_pos_x] == '0')
		player->pos_x -= player->dir_x * player->move_speed;
}

void	move_left(t_data *data)
{
	t_player	*player = &data->player;
	double		new_pos_x;
	double		new_pos_y;

	new_pos_y = player->pos_y + -player->dir_x * (player->move_speed + WALL_PADDING);
	new_pos_x = player->pos_x + player->dir_y  * (player->move_speed + WALL_PADDING);
	if (data->map.grid[(int)new_pos_y][(int)player->pos_x] == '0')
		player->pos_y += -player->dir_x * player->move_speed;
	if (data->map.grid[(int)(player->pos_y)][(int)new_pos_x] == '0')
		player->pos_x += player->dir_y * player->move_speed;
}

void	move_right(t_data *data)
{
	t_player	*player = &data->player;
	double		new_pos_x;
	double		new_pos_y;

	new_pos_y = player->pos_y +  player->dir_x * (player->move_speed + WALL_PADDING);
	new_pos_x = player->pos_x + -player->dir_y * (player->move_speed + WALL_PADDING);
	if (data->map.grid[(int)new_pos_y][(int)player->pos_x] == '0')
		player->pos_y += player->dir_x * player->move_speed;
	if (data->map.grid[(int)(player->pos_y)][(int)new_pos_x] == '0')
		player->pos_x += -player->dir_y * player->move_speed;
}

