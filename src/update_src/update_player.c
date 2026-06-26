/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:58:52 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 19:17:16 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	handle_movements(t_data *data)
{
	if (data->keys.w)
		move_up(data);
	if (data->keys.a)
		move_left(data);
	if (data->keys.s)
		move_down(data);
	if (data->keys.d)
		move_right(data);
}

void	handle_camera(t_data *data)
{
	if (data->keys.left)
		ft_rot_left(data);
	if (data->keys.right)
		ft_rot_right(data);
}

void	update_player(t_data *data)
{
	handle_movements(data);
	handle_camera(data);
	ft_player_stats(data);
}
