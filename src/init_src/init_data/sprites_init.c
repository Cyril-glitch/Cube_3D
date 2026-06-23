/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:22:36 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/23 15:23:09 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

void	ft_init_sprites(t_data *data)
{
	ft_assign_p_sprites_textures(data);
	ft_assign_m_sprites_textures(data);
	ft_assign_t_sprites_textures(data);
	init_sprites_pos(data->p_sprites, &data->map, SPRITE_P);
	init_sprites_pos(data->m_sprites, &data->map, SPRITE_M);
	init_sprites_pos(data->t_sprites, &data->map, SPRITE_T);
	init_monsters(data);
}

static	void	ft_assign_sprite_tab(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->p_sprites->number)
	{
		data->sprites[i] = data->p_sprites[j];
		data->sprites[i].consumed = false;
		i++;
		j++;
	}
	j = 0;
	while (j < data->t_sprites->number)
		data->sprites[i++] = data->t_sprites[j++];
	j = 0;
	while (j < data->m_sprites->number)
	{
		data->sprites[i] = data->m_sprites[j];
		data->monsters[j++].sprite = &data->sprites[i++];
	}
}

void	ft_init_global_sprites_tab(t_data *data)
{
	ft_init_sprites(data);
	data->sprites = malloc(sizeof(t_sprite) * (data->t_sprites->number
				+ data->m_sprites->number + data->p_sprites->number));
	if (!data->sprites)
		ft_game_exit(data, "sprites global init");
	ft_assign_sprite_tab(data);
}
