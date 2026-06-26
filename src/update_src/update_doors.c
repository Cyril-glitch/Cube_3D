/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_doors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:03:10 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 19:03:34 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	update_doors(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_doors)
	{
		if (data->doors[i].opening)
		{
			data->doors[i].open += data->frame_time * 1.5f;
			if (data->doors[i].open >= 1.0f)
			{
				data->doors[i].open = 1.0f;
				data->doors[i].opening = false;
			}
		}
		if (data->doors[i].closing)
		{
			data->doors[i].open -= data->frame_time * 1.5f;
			if (data->doors[i].open <= 0.0f)
			{
				data->doors[i].open = 0.0f;
				data->doors[i].closing = false;
			}
		}
		i++;
	}
}
