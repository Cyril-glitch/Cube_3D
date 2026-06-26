#include "../../inc/cube_3d.h"

int	get_map_tile(char **grid, int h, int x, int y)
{
	int	res;
	int	len;

	if (y < 0 || y > h)
		return (-1);
	len = ft_strlen(grid[y]);
	if (x < 0 || x >= len)
		return (-1);
	res = grid[y][x] - '0';
	return (res);
}

double	get_time(double start)
{
	t_timeval	tv;
	double		current;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	current = (double)tv.tv_sec * 1000.0 + (double)tv.tv_usec / 1000.0;
	return (current - start);
}

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
	handle_camera(data);
	update_monsters(data);
	ft_player_stats(data);
}
