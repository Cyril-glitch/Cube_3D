/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background_tex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:01:07 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 15:51:24 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

void	ft_init_backgrd(t_data *data, t_backgrd *b)
{
	int	i;

	b->floor.img = mlx_xpm_file_to_image(data->mlx, "./assets/bonus/sol.xpm",
			&b->floor.w, &b->floor.h);
	if (!b->floor.img)
		ft_game_exit(data, "background init");
	b->floor.addr = mlx_get_data_addr(b->floor.img, &b->floor.bpp,
			&b->floor.line_length, &b->floor.endian);
	if (!b->floor.addr)
		ft_game_exit(data, "background init");
	b->ceiling.img = mlx_xpm_file_to_image(data->mlx,
			"./assets/bonus/plafond.xpm", &b->ceiling.w, &b->ceiling.h);
	if (!b->ceiling.img)
		ft_game_exit(data, "background init");
	b->ceiling.addr = mlx_get_data_addr(b->ceiling.img, &b->ceiling.bpp,
			&b->ceiling.line_length, &b->ceiling.endian);
	if (!b->ceiling.addr)
		ft_game_exit(data, "background init");
	b->dist = malloc(sizeof(double) * data->win_size.y);
	if (!b->dist)
		ft_game_exit(data, "background init");
	i = 0;
	while (i < data->win_size.y)
	{
		b->dist[i] = (data->win_size.y / 2.0) / (i - data->win_size.y / 2.0);
		i++;
	}
}
