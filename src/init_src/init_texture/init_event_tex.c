/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:04:38 by cyril             #+#    #+#             */
/*   Updated: 2026/06/22 16:04:41 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	ft_init_game_over(t_data *data, t_img *over)
{
	over->img = mlx_xpm_file_to_image(data->mlx, "./assets/bonus/game_over.xpm",
			&over->w, &over->h);
	if (!over->img)
		ft_game_exit(data, "memory allocation failed (over)");
	over->addr = mlx_get_data_addr(over->img, &over->bpp, &over->line_length,
			&over->endian);
	if (!over->addr)
		ft_game_exit(data, "memory allocation failed (over)");
}

void	ft_init_congrats(t_data *data, t_img *congrats)
{
	congrats->img = mlx_xpm_file_to_image(data->mlx,
			"./assets/bonus/congrats.xpm", &congrats->w, &congrats->h);
	if (!congrats->img)
		ft_game_exit(data, "memory allocation failed (congrats)");
	congrats->addr = mlx_get_data_addr(congrats->img, &congrats->bpp,
			&congrats->line_length, &congrats->endian);
	if (!congrats->addr)
		ft_game_exit(data, "memory allocation failed (congrats)");
}