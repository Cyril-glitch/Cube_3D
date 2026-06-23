/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:07:19 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/23 15:24:16 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

static void	fill_offsets(int nb, int (*tab)[2])
{
	int	i;

	i = 0;
	while (i < nb)
	{
		tab[i][0] = 0;
		tab[i][1] = 0;
		if (i % 4 == 0)
			tab[i][0] = i;
		else if (i % 4 == 1)
			tab[i][0] = -i;
		else if (i % 4 == 2)
			tab[i][1] = i;
		else if (i % 4 == 3)
			tab[i][1] = -i;
		i++;
	}
}

void	init_offsets(t_data *data)
{
	int	(*offsets)[2];

	offsets = malloc(4 * sizeof(*offsets));
	if (!offsets)
		ft_game_exit(data, "init offsets");
	fill_offsets(4, offsets);
	data->offsets = offsets;
}
