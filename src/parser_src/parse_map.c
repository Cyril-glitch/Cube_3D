#include "../inc/cube_3d.h"

static void ft_add_nl(char **ret, char *line)
{
    *ret = NULL;
     ft_str_append_str(ret, line); 
    ft_str_append_str(ret, "\n"); 
}

static void ft_load_map(t_data *data , t_map *map, char *ret)
{
    map->grid = ft_split(ret, '\n');
    free(ret);
    if (!map->grid)
        ft_game_exit(data, "cannot extract map.");
}

static void ft_extract_map(t_data *data ,t_map *map, char *line)
{
    char *ret;

    ft_add_nl(&ret, line);
    while (line)
    {
        line = ft_gnl(data->fd);
        if (line == NULL || ft_skip_isspace_line(line))
            break ; 
        ft_str_append_str(&ret, line); 
        free(line);
    }
    if (line)
        ft_game_exit(data, "empty lines in map settings.");
    ft_load_map(data, map, ret);    
}

void    ft_parse_map(t_data *data, t_map *map, char **line)
{
    ft_extract_map(data, map, *line);
    ft_map_checker(data, &data->player, data->map.grid);
    ft_map_display(map->grid);
}