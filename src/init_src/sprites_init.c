/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichaud <nmichaud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:22:36 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/04 14:22:37 by nmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

int	count_sprites(t_map *map, int type)
{
	int	x;
	int	y;
	int	res;

	res = 0;
	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == type)
				res++;
			x++;
		}
		y++;
	}
	return (res);
}

void	ft_assign_m_sprites_textures(t_data *data)
{
	int	i;
	int	nb_sprites;

	nb_sprites = count_sprites(&data->map, SPRITE_M);
	if (nb_sprites == 0)
		ft_game_exit(data, "no monster in map");
	data->m_sprites = malloc(sizeof(t_sprite) * nb_sprites);
	if (!data->m_sprites)
		ft_game_exit(data, "monster allocation failed");
	i = 0;
	while (i < nb_sprites)
	{
		data->m_sprites[i].textures = data->m_textures;
		data->m_sprites[i].number = nb_sprites;
		data->m_sprites[i].type = SPRITE_M;
		i++;
	}
}

void	ft_assign_t_sprites_textures(t_data *data)
{
	int	i;
	int	nb_sprites;

	nb_sprites = count_sprites(&data->map, SPRITE_T);
	if (nb_sprites == 0)
		ft_game_exit(data, "no treasure in map");
	data->t_sprites = malloc(sizeof(t_sprite) * nb_sprites);
	if (!data->t_sprites)
		ft_game_exit(data, "treasures allocation failed");
	i = 0;
	while (i < nb_sprites)
	{
		data->t_sprites[i].textures = data->t_textures;
		data->t_sprites[i].number = nb_sprites;
		data->t_sprites[i].type = SPRITE_T;
		i++;
	}
}

void	ft_init_sprites(t_data *data)
{
	ft_assign_m_sprites_textures(data);
	ft_assign_t_sprites_textures(data);
	init_sprites_pos(data->m_sprites, &data->map, SPRITE_M);
	init_sprites_pos(data->t_sprites, &data->map, SPRITE_T);
	init_monsters(data);
}

void	ft_init_global_sprites_tab(t_data *data)
{
	int	i;
	int	j;

	ft_init_sprites(data);
	data->sprites = malloc(sizeof(t_sprite) * (data->t_sprites->number + data->m_sprites->number));
	if (!data->sprites)
		ft_game_exit(data, "sprites global init");
	i = 0;
	j = 0;
	while (i < data->t_sprites->number)
	{
		data->sprites[i] = data->t_sprites[j++];
		data->sprites[i].consumed = false;
		i++;
	}
	j = 0;
	while (j < data->m_sprites->number)
	{
		data->sprites[i] = data->m_sprites[j];
		data->monsters[j].sprite = &data->sprites[i];
		i++;
		j++;
	}
}

void	init_sprites_pos(t_sprite *sprites, t_map *map, int type)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == type)
			{
				sprites[i].x = (double)x + 0.5;
				sprites[i].y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void	ft_sort2(t_sprite_order *res, int count)
{
	int	i;
	int	j;
	t_sprite_order	tmp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - 1)
		{
			if (res[j].dist < res[j + 1].dist)
			{
				tmp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

t_sprite_order	*sort_sprites(t_data *data, int count)
{
	int					i;
	t_sprite_order		*res;

	res = malloc(sizeof(t_sprite_order) * count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count)
	{
		res[i].index = i;
		res[i].type = data->sprites[i].type;
		res[i].dist = (data->player.pos_x - data->sprites[i].x) * 
					(data->player.pos_x - data->sprites[i].x) +
					(data->player.pos_y - data->sprites[i].y) *
					(data->player.pos_y - data->sprites[i].y);
		i++;
	}
	ft_sort2(res, count);
	return (res);
}
