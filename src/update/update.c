#include "../../inc/cube_3d.h"

void	update_time(t_data *data)
{
	data->old_time = data->time;
	data->time = get_time(data->start);
	data->frame_time = (data->time - data->old_time) / 1000.0;
	data->player.rot_speed = data->frame_time * 2.5;
	data->player.move_speed = data->frame_time * 3.0;
}

void	handle_movements(t_data *data)
{
	if (data->keys.w)
		move_up(data);
	if (data->keys.a)
		move_left(data);
	if (data->keys.s)
		move_down(data);	
	if (data->keys.d)
		move_right(data);
}

void	handle_camera(t_data *data)
{
	if (data->keys.left)
		ft_rot_left(data);
	if (data->keys.right)
		ft_rot_right(data);
}

void	update_doors(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_doors)
	{
		if (data->doors[i].opening)
		{
			data->doors[i].open += data->frame_time * 1.5f;
			if (data->doors[i].open >= 1.0f)
			{
				data->doors[i].open = 1.0f;
				data->doors[i].opening = false;
			}
		}
		if (data->doors[i].closing)
		{
			data->doors[i].open -= data->frame_time * 1.5f;
			if (data->doors[i].open <= 0.0f)
			{
				data->doors[i].open = 0.0f;
				data->doors[i].closing = false;
			}
		}
		i++;
	}
}

t_sprite	*get_treasure_sprite(t_sprite *sprites, int count, int x, int y)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if ((int)sprites[i].x == x && (int)sprites[i].y == y)
			return (&sprites[i]);
		i++;
	}
	return (NULL);
}

void	update_treasures(t_data *data)
{
	t_sprite	*sprite;

	sprite = NULL;
	if (get_map_tile(data->map.grid, data->map.height, (int)data->player.pos_x, (int)data->player.pos_y) == SPRITE_T - '0')
		sprite = get_treasure_sprite(data->sprites, data->t_sprites->number, (int)data->player.pos_x, (int)data->player.pos_y);
	if (sprite)
	{
		/*if (sprite->consumed = false)
			data->health += 10;*/
		sprite->consumed = true;
	}
}

void	update_monsters(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->m_sprites->number)
	{
		if (ft_monster_arrived(&data->monsters[i]))
			ft_update_monster_path(data, &data->monsters[i], i);
		ft_bot_move(data, i);
		i++;
	}
}

void	update(t_data *data)
{
	update_time(data);
	handle_movements(data);
	update_doors(data);
	update_treasures(data);
	handle_camera(data);
	update_monsters(data);
}
