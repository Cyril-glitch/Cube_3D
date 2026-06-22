/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_treasure_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:27:40 by cyril             #+#    #+#             */
/*   Updated: 2026/06/22 15:31:24 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	init_treasure_textures(t_data *data)
{
	int		i;
	int		nb_frames;
	char	*s;

	nb_frames = SPRITE_T_TEXT_NB;
	data->t_textures = malloc(sizeof(t_img) * nb_frames);
	if (!data->t_textures)
		ft_game_exit(data, "treasure textures init");
	i = 0;
	while (i < nb_frames)
		data->t_textures[i++].img = NULL;
	i = 0;
	while (i < nb_frames)
	{
		s = get_asset_path(i + 1, "assets/torches/", "_Torch Animated.xpm");
		if (!s)
			ft_game_exit(data, "sprites init");
		data->t_textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
				&data->t_textures[i].w, &data->t_textures[i].h);
		free(s);
		if (!data->t_textures[i].img)
			ft_game_exit(data, "treasure textures init");
		data->t_textures[i].addr = mlx_get_data_addr(data->t_textures[i].img,
				&data->t_textures[i].bpp, &data->t_textures[i].line_length,
				&data->t_textures[i].endian);
		if (!data->t_textures[i].addr)
			ft_game_exit(data, "treasure textures init");
		treat_transparency(&data->t_textures[i].img, 0, 10);
		i++;
	}
}