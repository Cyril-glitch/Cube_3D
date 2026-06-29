/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pack_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:30:19 by cyril             #+#    #+#             */
/*   Updated: 2026/06/29 17:08:32 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

void	ft_assign_p_sprites_textures(t_data *data)
{
	int	i;
	int	nb_sprites;

	nb_sprites = count_sprites(&data->map, SPRITE_P);
	if (nb_sprites == 0)
		ft_game_exit(data, "no pack in map");
	data->p_sprites = malloc(sizeof(t_sprite) * nb_sprites);
	if (!data->p_sprites)
		ft_game_exit(data, "pack allocation failed");
	i = 0;
	while (i < nb_sprites)
	{
		data->p_sprites[i].textures = data->p_textures;
		data->p_sprites[i].number = nb_sprites;
		data->p_sprites[i].type = SPRITE_P;
		i++;
	}
}

static void	ft_init_img_ptr(t_data *data, int nb_frames)
{
	int	i;

	i = 0;
	while (i < nb_frames)
		data->p_textures[i++].img = NULL;
}

static void	ft_load_texture(t_data *data, int nb_frames)
{
	int		i;
	char	*s;

	i = 0;
	ft_init_img_ptr(data, nb_frames);
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
		treat_transparency(&data->p_textures[i], 0x00FF00, 10);
		i++;
	}
}

void	init_pack_textures(t_data *data)
{
	int	nb_frames;

	nb_frames = SPRITE_P_TEXT_NB;
	data->p_textures = malloc(sizeof(t_img) * nb_frames);
	if (!data->p_textures)
		ft_game_exit(data, "pack textures init");
	ft_load_texture(data, nb_frames);
}
