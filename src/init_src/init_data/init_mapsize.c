/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:46:58 by cyril             #+#    #+#             */
/*   Updated: 2026/06/22 14:57:18 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	init_map_size(t_data *data, char **grid)
{
	int		x;
	int		y;
	int		max;

	max = 0;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
			x++;
		if (x > max)
			max = x;
		y++;
	}
	data->map.width = max;
	data->map.height = y;
}
