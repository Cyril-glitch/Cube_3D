#include "../../inc/cube_3d.h"

void	update_time(t_data *data)
{
	data->old_time = data->time;
	data->time = get_time(data->start);
	data->frame_time = (data->time - data->old_time) / 1000.0;
	/*if (data->frame_time > 0)
		printf("FPS : %f\n", 1 / data->frame_time);*/
	data->player.rot_speed = data->frame_time * 5.0;
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

void	update(t_data *data)
{
	update_time(data);
	handle_movements(data);
	handle_camera(data);
}