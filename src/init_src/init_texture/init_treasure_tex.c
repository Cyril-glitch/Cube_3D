/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_treasure_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:27:40 by cyril             #+#    #+#             */
/*   Updated: 2026/06/29 17:07:55 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

void	ft_assign_t_sprites_textures(t_data *data)
{
	int	i;
	int	nb_sprites;

	nb_sprites = count_sprites(&data->map, SPRITE_T);
	if (nb_sprites == 0)
		ft_game_exit(data, "no treasure in map");
	data->tr_sprites = malloc(sizeof(t_sprite) * nb_sprites);
	if (!data->tr_sprites)
		ft_game_exit(data, "treasures allocation failed");
	i = 0;
	while (i < nb_sprites)
	{
		data->tr_sprites[i].textures = data->tr_textures;
		data->tr_sprites[i].number = nb_sprites;
		data->tr_sprites[i].type = SPRITE_T;
		i++;
	}
}

static void	ft_init_img_ptr(t_data *data, int nb_frames)
{
	int	i;

	i = 0;
	while (i < nb_frames)
		data->tr_textures[i++].img = NULL;
}

static void	ft_load_image(t_data *data, int nb_frames)
{
	int		i;
	char	*s;

	i = 0;
	ft_init_img_ptr(data, nb_frames);
	while (i < nb_frames)
	{
		s = get_asset_path(i + 1, "assets/torches/", "_Torch Animated.xpm");
		if (!s)
			ft_game_exit(data, "sprites init");
		data->tr_textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
				&data->tr_textures[i].w, &data->tr_textures[i].h);
		free(s);
		if (!data->tr_textures[i].img)
			ft_game_exit(data, "treasure textures init");
		data->tr_textures[i].addr = mlx_get_data_addr(data->tr_textures[i].img,
				&data->tr_textures[i].bpp, &data->tr_textures[i].line_length,
				&data->tr_textures[i].endian);
		if (!data->tr_textures[i].addr)
			ft_game_exit(data, "treasure textures init");
		treat_transparency(&data->tr_textures[i], 0, 10);
		i++;
	}
}

void	init_treasure_textures(t_data *data)
{
	int	nb_frames;

	nb_frames = SPRITE_T_TEXT_NB;
	data->tr_textures = malloc(sizeof(t_img) * nb_frames);
	if (!data->tr_textures)
		ft_game_exit(data, "treasure textures init");
	ft_load_image(data, nb_frames);
}
