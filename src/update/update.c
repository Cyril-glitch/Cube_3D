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
	/*if (data->keys.r)
		close_or_open_door(data);*/
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

void	update(t_data *data)
{
	int	i;

	update_time(data);
	handle_movements(data);
	update_doors(data);
	handle_camera(data);
	i = 0;
	while (i < data->m_sprites->number)
	{
		ft_bot_move(data, i);
		i++;
	}
}