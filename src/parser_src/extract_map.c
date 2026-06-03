#include "../inc/cube_3d.h"

static void	ft_init_map_buf(char **ret, char **line)
{
	*ret = NULL;
	ft_str_append_str(ret, *line);
	ft_str_append_str(ret, "\n");
	free(*line);
}

static void	ft_is_cuted_map(t_data *data, char **line, char *ret)
{
    if (*line == NULL)
		return ;
	*line = ft_gnl(data->fd);
	while (*line)
	{
		if (!ft_skip_isspace_line(*line))
			break ;
        *line = ft_gnl(data->fd); 
	}
	if (*line)
	{
		free(ret);
		ft_game_exit(data, "empty lines in map settings.");
	}
}

static void	ft_load_map(t_data *data, t_map *map, char *ret)
{
	map->grid = ft_split(ret, '\n');
	free(ret);
	if (!map->grid)
		ft_game_exit(data, "cannot extract map.");
}

void	ft_extract_map(t_data *data, t_map *map, char **line)
{
	char	*ret;

	ft_init_map_buf(&ret, line);
	while (1)
	{
		*line = ft_gnl(data->fd);
		if (*line == NULL || ft_skip_isspace_line(*line))
			break ;
		ft_str_append_str(&ret, *line);
		free(*line);
	}
	ft_is_cuted_map(data, line, ret);
	ft_load_map(data, map, ret);
}