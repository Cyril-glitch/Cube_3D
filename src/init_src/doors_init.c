/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichaud <nmichaud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:46:47 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/09 11:46:47 by nmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

int	ft_count_doors(char **grid)
{
	int	x;
	int	y;
	int	res;

	res = 0;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == '3' || grid[y][x] == '4')
				res++;
			x++;
		}
		y++;
	}
	return (res);
}

void	ft_parse_door(t_door *door, int x, int y, int orientation)
{
	door->tile_x = x;
	door->tile_y = y;
	if (orientation == '3')
		door->vertical = true;
	else if (orientation == '4')
		door->vertical = false;
	door->opening = false;
	door->closing = false;
	door->open = 0.0;
}

int	init_doors(t_data *data, char **grid)
{
	int	x;
	int	y;
	int	i;

	data->nb_doors = ft_count_doors(grid);
	data->doors = malloc(data->nb_doors * sizeof(t_door));
	if (!data->doors)
		return (0);
	i = 0;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == VER_DOOR || grid[y][x] == HOR_DOOR)
			{
				ft_parse_door(&data->doors[i], x, y, grid[y][x]);
				i++;
			}
			x++;
		}
		y++;
	}
	return (1);
}

t_door	*get_door(char **grid, t_door *door, int x, int y)
{
	int	i;
	int	count;

	count = ft_count_doors(grid);
	i = 0;
	while (i < count)
	{
		if (door[i].tile_x == x && door[i].tile_y == y)
			return (&door[i]);
		i++;
	}
	return (NULL);
}
