#include "../inc/cube_3d.h"

static int   ft_color_dup(t_data *data, int asset, char **color)
{
    if (asset)
    {
        ft_freedtab(color);
        ft_game_exit(data, "duplicate settings detected in file.");
    }
    return 0;
}


static void ft_check_color(t_data *data, char **color)
{
    int i;

    i = 0;
    while (color[i])
    {
        if (!ft_isfull_dig(color[i]) || ft_color_overflow(color[i]))
        {
            ft_freedtab(color);
            ft_game_exit(data, "colors settings failed");
        }
        i++;
    }
}

static  int    ft_is_color_component(char *line)
{
    if (ft_strncmp("F ", line, 2) && ft_strncmp("C ", line, 2))
        return 0;
    return 1;
}

static void    ft_load_color(t_data *data, t_map *map, char *line, char **color)
{ 
    if(*line == 'F' && !ft_color_dup(data, map->floor_color, color))
        map->floor_color = ft_shift_color(color);
    else if (*line == 'C' && !ft_color_dup(data, map->ceiling_color, color))
        map->ceiling_color = ft_shift_color(color); 
}

int    ft_parse_color(t_data *data, t_map *map, char *line)
{
    char *tmp;
    char **color;

    tmp = line;
    if (!ft_is_color_component(line))
        return 0; 
    ft_skip_isspace(2, &tmp);
    color = ft_split_color(tmp);
    if (!color)
        ft_game_exit(data, "memory allocation failed");
    ft_check_color(data, color);
    ft_load_color(data, map, line, color);
    ft_freedtab(color);
    free(line);
    return 1;
}