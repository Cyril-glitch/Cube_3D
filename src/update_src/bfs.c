/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:00:11 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 13:01:31 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

t_point	ft_bfs(t_data *data, t_bfs *bfs, t_point start, t_point target)
{
	t_point	cur;

	ft_init_research(start, target, bfs);
	ft_get_target_path(data, bfs, &cur);
	return (ft_get_next_step(bfs, start, target));
}
