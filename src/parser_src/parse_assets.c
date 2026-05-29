#include "../inc/cube_3d.h"

static  void    ft_check_assets(t_data *data, t_map *map)
{
    if (!map->no_path || !map->so_path || !map->we_path || !map->ea_path)
        ft_game_exit(data, "texture setttings not found.");
    else if (!map->ceiling_color ||  !map->floor_color)
        ft_game_exit(data, "color settings not found.");
}


static int ft_shift_color(char **tab)
{
    int r;
    int g;
    int b;

    r = ft_atoi(tab[0]);
    g = ft_atoi(tab[1]);
    b = ft_atoi(tab[2]);

    return (r << 16 | g << 8 | b);
}

static void    ft_load_color(t_data *data,t_map *map, char *line)
{ 
    char **color;
    char *tmp;


    tmp = line;
    ft_skip_isspace(2, &tmp);
    color = ft_split_color(tmp);
    if (!color)
        ft_game_exit(data, "memory allocation failed.");
    if(*line == 'F')
        map->floor_color = ft_shift_color(color);
    else if (*line == 'C')
        map->ceiling_color = ft_shift_color(color); 
    ft_freedtab(color);
}

static void    ft_load_texture(t_data *data, t_map *map, char *line)
{
    if (*line == 'N')
    {
        ft_skip_isspace(3, &line);
        map->no_path = ft_strdup(line);
    }
    else if (*line == 'S')
    {
        ft_skip_isspace(3, &line);
        map->so_path = ft_strdup(line);
    }
    else if (*line == 'W')
    {
        ft_skip_isspace(3, &line);
        map->we_path = ft_strdup(line);
    }
    else if (*line == 'E')
    {
        ft_skip_isspace(3, &line);
        map->ea_path = ft_strdup(line);
    } 
    if (!map)
        ft_game_exit(data, "memory allocation failed.");
}

void    ft_parse_assets(t_data *data, t_map *map, char **line)
{
    while (1)
    {
        *line = ft_gnl_no_nl(data->fd);
        if (!(*line))
            break ; 
        if (ft_skip_isspace_line(*line))
            continue ;
        else if (ft_valid_tex_line(data, *line))
           ft_load_texture(data, map, *line);  
        else if (ft_valid_color_line(data, *line))
           ft_load_color(data, map, *line);  
        else
            break;
        free(*line);
    }
    ft_check_assets(data, map);
}	