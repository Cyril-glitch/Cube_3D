#include "raycasting.h"

void	update_time(t_var *var)
{
	var->old_time = var->time;
	var->time = get_time(var->start);
	var->frame_time = (var->time - var->old_time) / 1000.0;
	var->player.rot_speed = var->frame_time * 5.0;
	var->player.move_speed = var->frame_time * 3.0;
}

void	handle_movements(t_var *var)
{
	if (var->keys.w)
		move_up(var);
	if (var->keys.s)
		move_down(var);
	if (var->keys.a)
		move_left(var);
	if (var->keys.d)
		move_right(var);
}

int	update(t_var *var)
{
	update_time(var);
	handle_movements(var);
	ft_memset(var->screen.addr, 0, var->win_size.y * var->win_size.x * 4);
	ft_raycaster(var, var->ray);
	ft_render_draw(var->ray, var);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->screen.img, 0, 0);
	return (0);
}
