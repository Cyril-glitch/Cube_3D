/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pack_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:30:19 by cyril             #+#    #+#             */
/*   Updated: 2026/06/22 15:33:55 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	init_pack_textures(t_data *data)
{
	int		i;
	int		nb_frames;
	char	*s;

	nb_frames = SPRITE_P_TEXT_NB;
	data->p_textures = malloc(sizeof(t_img) * nb_frames);
	if (!data->p_textures)
		ft_game_exit(data, "pack textures init");
	i = 0;
	while (i < nb_frames)
		data->p_textures[i++].img = NULL;
	i = 0;
	while (i < nb_frames)
	{
		s = get_asset_path(i + 1, "assets/bonus/", "_medkit.xpm");
		if (!s)
			ft_game_exit(data, "sprites init");
		data->p_textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
				&data->p_textures[i].w, &data->p_textures[i].h);
		free(s);
		if (!data->p_textures[i].img)
			ft_game_exit(data, "treasure textures init");
		data->p_textures[i].addr = mlx_get_data_addr(data->p_textures[i].img,
				&data->p_textures[i].bpp, &data->p_textures[i].line_length,
				&data->p_textures[i].endian);
		if (!data->p_textures[i].addr)
			ft_game_exit(data, "pack textures init");
		treat_transparency(&data->p_textures[i].img, 0x00FF00, 10);
		i++;
	}
}