/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   healing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:40:07 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/26 18:40:31 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static int	ft_is_pack(t_player *player, t_sprite *cur_pack)
{
	return ((int)cur_pack->x == (int)(player->pos_x)
		&& (int)cur_pack->y == (int)player->pos_y);
}

static void	ft_win(t_player *player, t_sprite *cur_pack)
{
	if (cur_pack->consumed)
		return ;
	player->healed = 1;
	player->hp.health += 20;
	if (player->hp.health > 100)
		player->hp.health = 100;
	cur_pack->consumed = 1;
}

void	ft_healing(t_player *player, t_sprite *hpack, int nb_pack)
{
	int	i;

	i = 0;
	while (i < nb_pack)
	{
		if (ft_is_pack(player, &hpack[i]))
			ft_win(player, &hpack[i]);
		i++;
	}
}
