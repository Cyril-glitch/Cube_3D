/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:28:42 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/29 16:46:09 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static int	ft_eating(t_player *player, t_player *cur_monster)
{
	return (cur_monster->pos_x > (player->pos_x - 1)
		&& cur_monster->pos_x < (player->pos_x + 1)
		&& cur_monster->pos_y > (player->pos_y - 1)
		&& cur_monster->pos_y < (player->pos_y + 1));
}

static void	ft_dpersec(t_data *data, t_hp *hp)
{
	double	hit;

	data->player.eated = 1;
	hit = get_time(data->start);
	if (hit - hp->last_hit < 1000)
		return ;
	else if (hp->health)
	{
		hp->last_hit = get_time(data->start);
		hp->health -= 5;
	}
}

void	ft_damage(t_data *data, t_player *player, t_player *monsters,
		int nb_monsters)
{
	int	i;

	i = 0;
	while (i < nb_monsters)
	{
		if (ft_eating(player, &monsters[i]))
			ft_dpersec(data, &player->hp);
		i++;
	}
}
