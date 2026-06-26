/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:04:21 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 19:15:58 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

double	get_time(double start)
{
	t_timeval	tv;
	double		current;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	current = (double)tv.tv_sec * 1000.0 + (double)tv.tv_usec / 1000.0;
	return (current - start);
}

void	update_time(t_data *data)
{
	data->old_time = data->time;
	data->time = get_time(data->start);
	data->frame_time = (data->time - data->old_time) / 1000.0;
	data->player.rot_speed = data->frame_time * 2.5;
	data->player.move_speed = data->frame_time * 3.0;
}
