/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:46:11 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/29 17:10:54 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

int	close_handler(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_game_exit(data, NULL);
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
		close_handler(data);
	if (keycode == XK_w)
		data->keys.w = 1;
	if (keycode == XK_a)
		data->keys.a = 1;
	if (keycode == XK_s)
		data->keys.s = 1;
	if (keycode == XK_d)
		data->keys.d = 1;
	if (keycode == K_LEFT)
		data->keys.left = 1;
	if (keycode == K_RIGHT)
		data->keys.right = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_w)
		data->keys.w = 0;
	if (keycode == XK_a)
		data->keys.a = 0;
	if (keycode == XK_s)
		data->keys.s = 0;
	if (keycode == XK_d)
		data->keys.d = 0;
	if (keycode == XK_e)
		close_or_open_door(data);
	if (keycode == K_LEFT)
		data->keys.left = 0;
	if (keycode == K_RIGHT)
		data->keys.right = 0;
	return (0);
}

void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, (void*)key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, (void*)key_release, data);
	mlx_hook(data->mlx_win, 17, 0, (void*)close_handler, data);
	mlx_mouse_hide(data->mlx, data->mlx_win);
	mlx_hook(data->mlx_win, 6, 1L << 6, (void*)ft_mouse_rot, data);
	mlx_loop_hook(data->mlx, (void*)ft_game_loop, data);
}
