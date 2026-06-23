/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:20:11 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 16:20:40 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	ft_init_player_pos(t_data *data, t_player *player, int y, int x)
{
	player->pos_y = y;
	player->pos_x = x;
	player->dir = data->map.grid[y][x];
	init_player_dir(data);
	data->map.grid[y][x] = '0';
}

int	ft_player_is_set(t_player *player)
{
	if (player->pos_x || player->pos_y)
		return (1);
	return (0);
}

int	ft_is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	ft_display_map_error(char **grid, int err_y, int err_x)
{
	int	y;
	int	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == '1')
				printf(B_BLUE "1" RESET);
			else if (ft_is_player(grid[y][x]))
				printf(GOLD "%c" RESET, grid[y][x]);
			else if (y == err_y && x == err_x)
				printf(B_RED "%c" RESET, grid[y][x]);
			else
				printf("%c", grid[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
