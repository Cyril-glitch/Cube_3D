/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichaud <nmichaud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:07:19 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/17 17:07:21 by nmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void fill_offsets(int nb, int (*tab)[2])
{
	int i;
	
	i = 0;
	while (i < nb)
	{
		tab[i][0] = i;
		tab[i][1] = -i;
		i++;
	}
	/*while (i < nb * 2)
	{
		tab[i][0] = -i;
		tab[i][1] = -i;
		i++;
	}
	while (i < nb * 3)
	{
		tab[i][0] = i + 1;
		tab[i][1] = i + 1;
		i++;
	}
	while (i < nb * 4)
	{
		tab[i][0] = -i + 1;
		tab[i][1] = -i + 1;
		i++;
	}*/
}

void init_offsets(t_data *data)
{
	int (*offsets)[2];
	int nb_monsters;

	nb_monsters = data->m_sprites->number;
	offsets = malloc(nb_monsters * sizeof(*offsets));
	if (!offsets)
		ft_game_exit(data, "init offsets");
	fill_offsets(nb_monsters, offsets);
	data->offsets = offsets;
}
