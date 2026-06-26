/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_monsters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:58:17 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 19:08:00 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	update_monsters(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->m_sprites->number)
	{
		if (ft_monster_arrived(&data->monsters[i]))
			ft_update_monster_path(data, &data->monsters[i], i);
		ft_bot_move(data, i);
		i++;
	}
}
