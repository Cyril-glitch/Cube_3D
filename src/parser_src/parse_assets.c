/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:13:47 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 16:13:59 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static void	ft_check_assets(t_data *data, t_map *map)
{
	if (!map->no_path || !map->so_path || !map->we_path || !map->ea_path)
		ft_game_exit(data, "texture setttings not found.");
	else if (!map->ceiling_color || !map->floor_color)
		ft_game_exit(data, "color settings not found.");
}

void	ft_parse_assets(t_data *data, t_map *map, char **line)
{
	while (1)
	{
		*line = ft_gnl_no_nl(data->fd);
		if (!(*line))
			break ;
		if (ft_skip_isspace_line(*line))
			continue ;
		else if (ft_parse_texture(data, map, *line))
			continue ;
		else if (ft_parse_color(data, map, *line))
			continue ;
		else
			break ;
	}
	ft_check_assets(data, map);
	ft_assets_display(map);
}
