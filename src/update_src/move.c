/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:40:48 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 18:43:24 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

int	can_move(t_door *doors, t_map *map, int x, int y)
{
	t_door	*door;
	char	tile_value;

	tile_value = get_map_tile(map->grid, map->height, x, y);
	if (tile_value == 0 || tile_value == SPRITE_T - '0'
		|| tile_value == SPRITE_P - '0')
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
	t_player	*player;
	double		new_pos_x;
	double		new_pos_y;

	player = &data->player;
	new_pos_y = player->pos_y + player->dir_y * (player->move_speed
			+ WALL_PADDING);
	new_pos_x = player->pos_x + player->dir_x * (player->move_speed
			+ WALL_PADDING);
	if (can_move(data->doors, &data->map, (int)player->pos_x, (int)new_pos_y))
		player->pos_y += player->dir_y * player->move_speed;
	if (can_move(data->doors, &data->map, (int)new_pos_x, (int)player->pos_y))
		player->pos_x += player->dir_x * player->move_speed;
}

void	move_down(t_data *data)
{
	t_player	*player;
	double		new_pos_x;
	double		new_pos_y;

	player = &data->player;
	new_pos_y = player->pos_y - player->dir_y * (player->move_speed
			+ WALL_PADDING);
	new_pos_x = player->pos_x - player->dir_x * (player->move_speed
			+ WALL_PADDING);
	if (can_move(data->doors, &data->map, (int)player->pos_x, (int)new_pos_y))
		player->pos_y -= player->dir_y * player->move_speed;
	if (can_move(data->doors, &data->map, (int)new_pos_x, (int)player->pos_y))
		player->pos_x -= player->dir_x * player->move_speed;
}

void	move_left(t_data *data)
{
	t_player	*player;
	double		new_pos_x;
	double		new_pos_y;

	player = &data->player;
	new_pos_y = player->pos_y + -player->dir_x * (player->move_speed
			+ WALL_PADDING);
	new_pos_x = player->pos_x + player->dir_y * (player->move_speed
			+ WALL_PADDING);
	if (can_move(data->doors, &data->map, (int)player->pos_x, (int)new_pos_y))
		player->pos_y += -player->dir_x * player->move_speed;
	if (can_move(data->doors, &data->map, (int)new_pos_x, (int)player->pos_y))
		player->pos_x += player->dir_y * player->move_speed;
}

void	move_right(t_data *data)
{
	t_player	*player;
	double		new_pos_x;
	double		new_pos_y;

	player = &data->player;
	new_pos_y = player->pos_y + player->dir_x * (player->move_speed
			+ WALL_PADDING);
	new_pos_x = player->pos_x + -player->dir_y * (player->move_speed
			+ WALL_PADDING);
	if (can_move(data->doors, &data->map, (int)player->pos_x, (int)new_pos_y))
		player->pos_y += player->dir_x * player->move_speed;
	if (can_move(data->doors, &data->map, (int)new_pos_x, (int)player->pos_y))
		player->pos_x += -player->dir_y * player->move_speed;
}
