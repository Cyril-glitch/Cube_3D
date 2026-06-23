/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:01:10 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 12:30:10 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

static char	*ft_get_dir_str(t_map *map, int i)
{
	if (i == 0)
		return (map->no_path);
	else if (i == 1)
		return (map->so_path);
	else if (i == 2)
		return (map->ea_path);
	else if (i == 3)
		return (map->we_path);
	else if (i == 4)
		return ("assets/bonus/doors.xpm");
	return (map->no_path);
}

void	init_wall_tex(t_data *data)
{
	int		i;
	char	*s;

	data->textures = malloc(sizeof(t_img) * 5);
	if (!data->textures)
		ft_game_exit(data, "textures init");
	i = 0;
	while (i < 5)
		data->textures[i++].img = NULL;
	i = 0;
	while (i < 5)
	{
		s = ft_get_dir_str(&data->map, i);
		data->textures[i].img = mlx_xpm_file_to_image(data->mlx, s,
				&data->textures[i].w, &data->textures[i].h);
		if (!data->textures[i].img)
			ft_game_exit(data, "textures init");
		data->textures[i].addr = mlx_get_data_addr(data->textures[i].img,
				&data->textures[i].bpp, &data->textures[i].line_length,
				&data->textures[i].endian);
		if (!data->textures[i].addr)
			ft_game_exit(data, "textures init");
		i++;
	}
}
