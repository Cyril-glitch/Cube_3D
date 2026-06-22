/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:51:14 by cyril             #+#    #+#             */
/*   Updated: 2026/06/22 14:00:47 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_fps_limiter(t_data *data)
{
	double	new_time;

	new_time = get_time(data->start);
	if (new_time - data->last_frame <= CAP)
		return (0);
	data->last_frame = get_time(data->start);
}

static void	ft_game_update(t_data *data)
{
	update(data);
}

static void	ft_game_engine(t_data *data)
{
	ft_memset(data->screen.addr, 0, data->win_size.y * data->win_size.x * 4);
	ft_raycaster(data, data->ray);
}

static void	ft_game_draw(t_data *data)
{
	ft_render_draw(data->ray, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.img, 0, 0);
}

int	ft_game_loop(t_data *data)
{
	ft_fps_limiter(data);
	ft_game_engine(data);
	ft_game_draw(data);
	ft_display_fps(data);
	ft_game_update(data);
	return (0);
}
