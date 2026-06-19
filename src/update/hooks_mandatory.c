/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichaud <nmichaud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:49:24 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/19 16:49:24 by nmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	safe_cleanup(t_data *data)
{
	int	i;

	if (data->map.grid)
		ft_free(&data->map.grid);
	if (data->ray)
		free(data->ray);
	if (data->screen.img)
		mlx_destroy_image(data->mlx, data->screen.img);
	if (data->mini_map.image.img)
		mlx_destroy_image(data->mlx, data->mini_map.image.img);
	if (data->mini_map.arrow.img)
		mlx_destroy_image(data->mlx, data->mini_map.arrow.img);
	i = 0;
	while (i < 64)
	{
		if (data->mini_map.rotation[i].img)
			mlx_destroy_image(data->mlx, data->mini_map.rotation[i].img);
		i++;
	}
	if (data->textures)
	{
		i = 0;
		while (i < 4)
		{
			if (data->textures[i].img)
				mlx_destroy_image(data->mlx, data->textures[i].img);
			i++;
		}
		free(data->textures);
	}
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	close_handler(void *param)
{
	t_data *data = (t_data *)param;

	ft_game_exit(data, NULL);
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_data	*data = (t_data *)param;

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
	t_data	*data = (t_data *)param;

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
	mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx_win, 17, 0, close_handler, data);
	mlx_loop_hook(data->mlx, ft_game_loop, data);
}
