/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:02:04 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 13:02:08 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static int	ft_unvisited(t_point parent)
{
	return (parent.x == -1 && parent.y == -1);
}

static int	ft_staystill(t_point start, t_point target, t_point parent)
{
	if (start.x == target.x && start.y == target.y)
		return (1);
	else if (ft_unvisited(parent))
		return (1);
	return (0);
}

t_point	ft_get_next_step(t_bfs *bfs, t_point start, t_point target)
{
	t_point	cur;
	t_point	parent;

	cur = target;
	parent = bfs->came_from[ft_get_index(target, *bfs)];
	if (ft_staystill(start, target, parent))
		return (start);
	while (!(parent.x == start.x && parent.y == start.y))
	{
		if (ft_unvisited(parent))
			return (start);
		cur = parent;
		parent = bfs->came_from[ft_get_index(cur, *bfs)];
	}
	return (cur);
}
