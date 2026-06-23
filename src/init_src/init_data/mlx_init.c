/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:58:52 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 12:30:10 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

void	init_mlx_and_ray(t_data *data)
{
	int	i;

	data->mlx = mlx_init();
	if (!data->mlx)
		ft_game_exit(data, "mlx init");
	data->mlx_win = mlx_new_window(data->mlx, WIN_W, WIN_H, "Cube3d");
	data->win_size.x = WIN_W;
	data->win_size.y = WIN_H;
	data->total_pixel = data->win_size.x * data->win_size.y;
	if (!data->mlx_win)
		ft_game_exit(data, "mlx win init");
	data->ray = malloc(sizeof(t_ray) * data->win_size.x);
	if (!data->ray)
		ft_game_exit(data, "mlx ray init");
	i = 0;
	while (i < data->win_size.x)
		data->ray[i++].half_h = data->win_size.y / 2;
}
