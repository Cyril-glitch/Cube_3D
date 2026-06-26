/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:28:24 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 19:16:10 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

int	ft_get_index(t_point p, t_bfs bfs)
{
	return (p.y * bfs.max_w + p.x);
}

unsigned int	ft_rand(unsigned int *state)
{
	*state ^= *state << 13;
	*state ^= *state >> 17;
	*state ^= *state << 5;
	return (*state);
}

int	ft_is_target(t_point cur, t_point target)
{
	return (cur.x == target.x && cur.y == target.y);
}

void	ft_neighbor_dir(int *dir_x, int *dir_y)
{
	dir_x[0] = 0;
	dir_x[1] = 0;
	dir_x[2] = -1;
	dir_x[3] = 1;
	dir_y[0] = -1;
	dir_y[1] = 1;
	dir_y[2] = 0;
	dir_y[3] = 0;
}

int	get_map_tile(char **grid, int h, int x, int y)
{
	int	res;
	int	len;

	if (y < 0 || y > h)
		return (-1);
	len = ft_strlen(grid[y]);
	if (x < 0 || x >= len)
		return (-1);
	res = grid[y][x] - '0';
	return (res);
}
