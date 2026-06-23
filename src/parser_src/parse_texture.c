/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:15:08 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 16:15:22 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static int	ft_tex_dup(t_data *data, char *file_path)
{
	if (file_path)
		ft_game_exit(data, "duplicate settings detected in file.");
	return (0);
}

static void	ft_check_path(t_data *data, char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_error_file(file_path);
		ft_game_exit(data, NULL);
	}
	close(fd);
}

static int	ft_is_tex_component(char *line)
{
	if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3))
		return (1);
	if (!ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
		return (1);
	return (0);
}

static void	ft_load_texture(t_data *data, t_map *map, char *tmp, char *line)
{
	if (*line == 'N' && !ft_tex_dup(data, map->no_path))
		map->no_path = ft_strdup(tmp);
	else if (*line == 'S' && !ft_tex_dup(data, map->so_path))
		map->so_path = ft_strdup(tmp);
	else if (*line == 'W' && !ft_tex_dup(data, map->we_path))
		map->we_path = ft_strdup(tmp);
	else if (*line == 'E' && !ft_tex_dup(data, map->ea_path))
		map->ea_path = ft_strdup(tmp);
}

int	ft_parse_texture(t_data *data, t_map *map, char *line)
{
	char	*tmp;

	tmp = line;
	if (!ft_is_tex_component(tmp))
		return (0);
	ft_skip_isspace(3, &tmp);
	ft_check_path(data, tmp);
	ft_load_texture(data, map, tmp, line);
	free(line);
	return (1);
}
