/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:07:29 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 12:20:50 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

static void	ft_max_width(t_player *monster, char **grid)
{
	int	x;
	int	y;
	int	max;

	y = 0;
	max = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
			x++;
		if (x > max)
			max = x;
		y++;
	}
	monster->bfs.max_w = max;
	monster->bfs.max_h = y;
}

void	ft_init_bfs(t_data *data, t_player *monsters)
{
	int	w;
	int	h;
	int	i;

	i = 0;
	while (i < data->m_sprites->number)
	{
		monsters[i].bfs.queue = NULL;
		monsters[i].bfs.came_from = NULL;
		i++;
	}
	i = 0;
	while (i < data->m_sprites->number)
	{
		ft_max_width(&monsters[i], data->map.grid);
		w = monsters[i].bfs.max_w;
		h = monsters[i].bfs.max_h;
		monsters[i].bfs.queue = malloc(sizeof(t_point) * (w * h));
		if (!monsters[i].bfs.queue)
			ft_game_exit(data, "Memory allocation failed (queue).");
		monsters[i].bfs.came_from = malloc(sizeof(t_point) * (w * h));
		if (!monsters[i].bfs.came_from)
			ft_game_exit(data, "Memory allocation failed (came_from).");
		i++;
	}
}
