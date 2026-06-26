/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:14:28 by cyril             #+#    #+#             */
/*   Updated: 2026/06/26 19:20:57 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

int	ft_open_file(t_data *data, char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_error_file(file_path);
		ft_game_exit(data, NULL);
	}
	return (fd);
}

int	ft_skip_isspace_line(char *line)
{
	char	*tmp;

	tmp = line;
	while (*tmp)
	{
		if (ft_isspace(*tmp))
			tmp++;
		else
			return (0);
	}
	return (free(line), (1));
}

void	ft_skip_isspace(int start, char **line)
{
	*line += start;
	while (ft_isspace(**line))
		(*line)++;
}

void	ft_assets_display(t_map *map)
{
	printf(MINT "NO " RESET LAVENDER "%s\n" RESET, map->no_path);
	printf(MINT "SO " RESET LAVENDER "%s\n" RESET, map->so_path);
	printf(MINT "WE " RESET LAVENDER "%s\n" RESET, map->we_path);
	printf(MINT "EA " RESET LAVENDER "%s\n\n" RESET, map->ea_path);
	printf(MINT "F " LAVENDER "%X\n" RESET, map->floor_color);
	printf(MINT "C " LAVENDER "%X\n\n" RESET, map->ceiling_color);
}
