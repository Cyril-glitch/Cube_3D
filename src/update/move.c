#include "../../inc/cube_3d.h"

int	can_move(t_door *doors, t_map *map, int x, int y)
{
	t_door	*door;
	char	tile_value;

	//tile_value = data->map.grid[y][x];
	tile_value = get_map_tile(map->grid, map->height, x, y);
	if (tile_value == 0)
		return (1);
	if (tile_value == VER_DOOR - '0' || tile_value == HOR_DOOR - '0')
	{
		door = get_door(map->grid, doors, x, y);
		if (door->open == 1.0)
			return (1);
	}
	return (0);
}

void	move_up(t_data *data)
{
	t_player	*player = &data->player;
	double		new_pos_x;
	double		new_pos_y;

	new_pos_y = player->pos_y + player->dir_y * (player->move_speed + WALL_PADDING);
	new_pos_x = player->pos_x + player->dir_x * (player->move_speed + WALL_PADDING);
	if (can_move(data->doors, &data->map, (int)player->pos_x, (int)new_pos_y))
		player->pos_y += player->dir_y * player->move_speed;
	if (can_move(data->doors, &data->map, (int)new_pos_x, (int)player->pos_y))
		player->pos_x += player->dir_x * player->move_speed;
}

void	move_down(t_data *data)
{
	t_player	*player = &data->player;

	double		new_pos_x;
	double		new_pos_y;

	new_pos_y = player->pos_y - player->dir_y * (player->move_speed + WALL_PADDING);
	new_pos_x = player->pos_x - player->dir_x * (player->move_speed + WALL_PADDING);
	if (can_move(data->doors, &data->map, (int)player->pos_x, (int)new_pos_y))
		player->pos_y -= player->dir_y * player->move_speed;
	if (can_move(data->doors, &data->map, (int)new_pos_x, (int)player->pos_y))
		player->pos_x -= player->dir_x * player->move_speed;
}

void	move_left(t_data *data)
{
	t_player	*player = &data->player;
	double		new_pos_x;
	double		new_pos_y;

	new_pos_y = player->pos_y + -player->dir_x * (player->move_speed + WALL_PADDING);
	new_pos_x = player->pos_x + player->dir_y  * (player->move_speed + WALL_PADDING);
	if (can_move(data->doors, &data->map, (int)player->pos_x, (int)new_pos_y))
		player->pos_y += -player->dir_x * player->move_speed;
	if (can_move(data->doors, &data->map, (int)new_pos_x, (int)player->pos_y))
		player->pos_x += player->dir_y * player->move_speed;
}

void	move_right(t_data *data)
{
	t_player	*player = &data->player;
	double		new_pos_x;
	double		new_pos_y;

	new_pos_y = player->pos_y +  player->dir_x * (player->move_speed + WALL_PADDING);
	new_pos_x = player->pos_x + -player->dir_y * (player->move_speed + WALL_PADDING);
	if (can_move(data->doors, &data->map, (int)player->pos_x, (int)new_pos_y))
		player->pos_y += player->dir_x * player->move_speed;
	if (can_move(data->doors, &data->map, (int)new_pos_x, (int)player->pos_y))
		player->pos_x += -player->dir_y * player->move_speed;
}

void	close_or_open_door(t_data *data)
{
	t_player	*player = &data->player;
	t_door		*door;
	double		x;
	double		y;

	x = player->pos_x + player->dir_x * (player->move_speed + INTERACT_DIST);
	y = player->pos_y + player->dir_y  * (player->move_speed + INTERACT_DIST);
	door = get_door(data->map.grid, data->doors, (int)x, (int)y);
	if (!door)
		return ;
	if (!door->opening && door->open < 1.0)
	{
		door->opening = true;
		door->closing = false;
	}
	else if (!door->closing && door->open > 0.0)
	{
		door->opening = false;
		door->closing = true;
	}
}
