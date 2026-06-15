/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monsters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichaud <nmichaud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:07:19 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/15 19:07:20 by nmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_check_monster(t_data *data, int *i , int y , int x)
{
	if (data->map.grid[y][x] == SPRITE_M)
	{
		data->monsters[*i].pos_y = y;
		data->monsters[*i].pos_x = x;
		data->monsters[*i].next_step.x = 0;
		data->monsters[*i].next_step.y = 0;
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
	int	i;

	data->monsters = malloc(sizeof(t_player) * data->m_sprites->number);
	if (!data->monsters)
		ft_game_exit(data, "allocation failed (monsters)");
	i = 0;
	init_monsters_pos(data, data->map.grid);
	while (i < data->m_sprites->number)
	{
		data->monsters[i].sprite = &data->m_sprites[i];
		i++;
	}
}
