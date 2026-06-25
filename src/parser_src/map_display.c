/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:33:54 by cyril             #+#    #+#             */
/*   Updated: 2026/06/25 11:39:26 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_display(char **grid, int y, int x)
{
	if (grid[y][x] == '1')
		printf(B_BLUE "1" RESET);
	else if (ft_is_player(grid[y][x]))
		printf(GOLD "%c" RESET, grid[y][x]);
	else if (grid[y][x] == SPRITE_M)
		printf(B_PURPLE "%c" RESET, grid[y][x]);
	else if (grid[y][x] == SPRITE_T)
		printf(B_YELLOW "%c" RESET, grid[y][x]);
	else if (grid[y][x] == SPRITE_P)
		printf(MINT "%c" RESET, grid[y][x]);
	else if (grid[y][x] == HOR_DOOR || grid[y][x] == VER_DOOR)
		printf(RED "%c" RESET, grid[y][x]);
	else
		printf("%c", grid[y][x]);
}

void	ft_map_display(char **grid)
{
	int	y;
	int	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			ft_display(grid, y, x);
			x++;
		}
		printf("\n");
		y++;
	}
}
