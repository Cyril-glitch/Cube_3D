#include "../inc/cube_3d.h"

static void ft_extract_map(t_data *data ,t_map *map,int fd, char *line)
{
    char *ret;

    ret = NULL;
    ft_str_append_str(&ret, line); 
    ft_str_append_str(&ret, "\n"); 
    while (line)
    {
        line = ft_gnl(fd);
        if (line == NULL || ft_skip_isspace_line(line))
            break ; 
        ft_str_append_str(&ret, line); 
        free(line);
    }
    close(fd);
    map->grid = ft_split(ret, '\n');
    if (!map->grid || line != NULL)
    {
        free(ret);
        ft_game_exit(data, "cannot extract map.");
    }
    free(ret);
}

void    ft_parse_map(t_data *data, t_map *map, char **line)
{
    ft_extract_map(data, map, data->fd, *line);
    ft_map_display(map->grid);
    ft_map_checker(data, &data->player, data->map.grid);
}