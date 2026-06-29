/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monsters_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:34:09 by cyril             #+#    #+#             */
/*   Updated: 2026/06/29 17:08:42 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

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

static void	ft_init_img_ptr(t_data *data, int nb_frames)
{
	int	i;

	i = 0;
	while (i < nb_frames)
		data->m_textures[i++].img = NULL;
}

static void	ft_load_texture(t_data *data, int nb_frames)
{
	int		i;
	char	*s;

	i = 0;
	ft_init_img_ptr(data, nb_frames);
	while (i < nb_frames)
	{
		s = get_asset_path(i + 1, "assets/carboard/", "_carboard.xpm");
		if (!s)
			ft_game_exit(data, "monster textures init");
		data->m_textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
				&data->m_textures[i].w, &data->m_textures[i].h);
		free(s);
		if (!data->m_textures[i].img)
			ft_game_exit(data, "monster textures init");
		data->m_textures[i].addr = mlx_get_data_addr(data->m_textures[i].img,
				&data->m_textures[i].bpp, &data->m_textures[i].line_length,
				&data->m_textures[i].endian);
		if (!data->m_textures[i].addr)
			ft_game_exit(data, "monster textures init");
		treat_transparency(&data->m_textures[i], 0, 10);
		i++;
	}
}

void	init_monster_textures(t_data *data)
{
	int	nb_frames;

	nb_frames = SPRITE_M_TEXT_NB;
	data->m_textures = malloc(sizeof(t_img) * nb_frames);
	if (!data->tr_textures)
		ft_game_exit(data, "monster textures init");
	ft_load_texture(data, nb_frames);
}
