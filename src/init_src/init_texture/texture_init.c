/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:59:16 by cyril             #+#    #+#             */
/*   Updated: 2026/06/22 16:05:00 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	init_screen(t_data *data)
{
	data->screen.img = mlx_new_image(data->mlx, data->win_size.x,
			data->win_size.y);
	if (!data->screen.img)
		ft_game_exit(data, "screen init");
	;
	data->screen.addr = mlx_get_data_addr(data->screen.img, &data->screen.bpp,
			&data->screen.line_length, &data->screen.endian);
	if (!data->screen.addr)
		ft_game_exit(data, "screen init");
	data->screen.w = data->win_size.x;
	data->screen.h = data->win_size.y;
	data->screen.half_w = data->win_size.x / 2;
	data->screen.half_h = data->win_size.y / 2;
}
