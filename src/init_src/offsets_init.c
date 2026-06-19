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

/*static void fill_offsets(int nb, int (*tab)[2])
{
    double angle;
    double step;
    int radius;
    int i;

    radius = 4;
    step = 2.0 * PI / nb;

    i = 0;
    while (i < nb)
    {
		angle = i * step;
        tab[i][0] = round(cos(angle) * radius);
        tab[i][1] = round(sin(angle) * radius);
        i++;
    }
}*/

static void fill_offsets(int nb, int (*tab)[2])
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		if (i % 2 == 0)
		{
			if (j % 2 == 0)
			{
				tab[i][0] = i;
				tab[i][1] = 0;
			}
			else
			{
				tab[i][0] = -i;
				tab[i][1] = 0;
			}
		}
		else
		{
			if (j % 2 == 0)
			{
				tab[i][0] = 0;
				tab[i][1] = i;
			}
			else
			{
				tab[i][0] = 0;
				tab[i][1] = -i;
			}
		}
		j++;
		i++;
	}
}

void init_offsets(t_data *data)
{
	int (*offsets)[2];
	//int nb_monsters;

	//nb_monsters = data->m_sprites->number;
	offsets = malloc(4 * sizeof(*offsets));
	if (!offsets)
		ft_game_exit(data, "init offsets");
	fill_offsets(4, offsets);
	data->offsets = offsets;
}
