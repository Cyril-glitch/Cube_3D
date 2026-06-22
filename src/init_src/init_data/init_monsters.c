/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monsters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:07:19 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/22 14:16:43 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_check_monster(t_data *data, int *i, int y, int x)
{
	if (data->map.grid[y][x] == SPRITE_M)
	{
		data->monsters[*i].pos_y = y;
		data->monsters[*i].pos_x = x;
		data->monsters[*i].next_step.y = y;
		data->monsters[*i].next_step.x = x;
		data->map.grid[y][x] = '0';
		*i = *i + 1;
	}
}

void	init_monsters_pos(t_data *data, char **grid)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			ft_check_monster(data, &i, y, x);
			x++;
		}
		y++;
	}
}

void	init_monsters(t_data *data)
{
	data->monsters = malloc(sizeof(t_player) * data->m_sprites->number);
	if (!data->monsters)
		ft_game_exit(data, "allocation failed (monsters)");
	init_monsters_pos(data, data->map.grid);
}
