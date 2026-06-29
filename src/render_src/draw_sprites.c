/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:22:53 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/26 11:58:13 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

int	draw_sprites(t_data *data, t_player *player)
{
	t_sprite_order	*order;
	int				i;
	int				count;

	count = data->tr_sprites->number + data->m_sprites->number
		+ data->p_sprites->number;
	order = sort_sprites(data, count);
	if (!order)
		return (0);
	i = 0;
	while (i < count)
	{
		draw_single_sprite(data, player, order[i].index, order[i].type);
		i++;
	}
	free(order);
	return (1);
}
