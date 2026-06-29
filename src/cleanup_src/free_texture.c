/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:10:11 by cyril             #+#    #+#             */
/*   Updated: 2026/06/22 13:04:13 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_free_wall_tex(t_data *data)
{
	int	i;

	i = 0;
	if (data->textures)
	{
		while (i < 5)
		{
			if (data->textures[i].img)
				mlx_destroy_image(data->mlx, data->textures[i].img);
			i++;
		}
		free(data->textures);
		data->textures = NULL;
	}
}

static void	ft_free_treasures_tex(t_data *data)
{
	int	i;

	i = 0;
	if (data->tr_textures)
	{
		while (i < SPRITE_T_TEXT_NB)
		{
			if (data->tr_textures[i].img)
				mlx_destroy_image(data->mlx, data->tr_textures[i].img);
			i++;
		}
		free(data->tr_textures);
	}
}

static void	ft_free_monsters_tex(t_data *data)
{
	int	i;

	i = 0;
	if (data->m_textures)
	{
		i = 0;
		while (i < SPRITE_M_TEXT_NB)
		{
			if (data->m_textures[i].img)
				mlx_destroy_image(data->mlx, data->m_textures[i].img);
			i++;
		}
		free(data->m_textures);
	}
}

static void	ft_free_pack_tex(t_data *data)
{
	int	i;

	i = 0;
	if (data->p_textures)
	{
		i = 0;
		while (i < SPRITE_P_TEXT_NB)
		{
			if (data->p_textures[i].img)
				mlx_destroy_image(data->mlx, data->p_textures[i].img);
			i++;
		}
		free(data->p_textures);
	}
}

void	ft_free_texture(t_data *data)
{
	if (!data)
		return ;
	ft_free_wall_tex(data);
	ft_free_treasures_tex(data);
	ft_free_monsters_tex(data);
	ft_free_pack_tex(data);
}
