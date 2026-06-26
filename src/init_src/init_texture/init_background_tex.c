/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background_tex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:01:07 by cyril             #+#    #+#             */
/*   Updated: 2026/06/26 15:53:01 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

void	ft_init_backgrd(t_data *data, t_backgrd *b)
{
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
}
