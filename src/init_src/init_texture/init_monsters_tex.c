#include "../../inc/cube_3d.h"

void	init_monster_textures(t_data *data)
{
	int		i;
	int		nb_frames;
	char	*s;

	nb_frames = SPRITE_M_TEXT_NB;
	data->m_textures = malloc(sizeof(t_img) * nb_frames);
	if (!data->t_textures)
		ft_game_exit(data, "monster textures init");
	i = 0;
	while (i < nb_frames)
		data->m_textures[i++].img = NULL;
	i = 0;
	while (i < nb_frames)
	{
		s = get_asset_path(i + 1, "assets/carboard/", "_carboard.xpm");
		if (!s)
			ft_game_exit(data, "monster textures init");
		data->m_textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
				&data->m_textures[i].w, &data->m_textures[i].h);
		free(s);
		if (!data->m_textures[i].img)
		{
			printf("test\n");
			ft_game_exit(data, "monster textures init");
		}
		data->m_textures[i].addr = mlx_get_data_addr(data->m_textures[i].img,
				&data->m_textures[i].bpp, &data->m_textures[i].line_length,
				&data->m_textures[i].endian);
		if (!data->m_textures[i].addr)
			ft_game_exit(data, "monster textures init");
		treat_transparency(&data->m_textures[i].img, 0, 10);
		i++;
	}
}