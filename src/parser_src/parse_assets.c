#include "../inc/cube_3d.h"

static void ft_display(t_map *map)
{
    /*
    printf(MINT "NO " RESET LAVENDER "%s\n" RESET, map->no_path);
    printf(MINT "SO " RESET LAVENDER "%s\n" RESET, map->so_path);
    printf(MINT "WE " RESET LAVENDER "%s\n" RESET, map->we_path);
    printf(MINT "EA " RESET LAVENDER "%s\n" RESET, map->ea_path);
    printf(MINT "F "  LAVENDER "%d\n" RESET, map->floor_color);
    printf(MINT "C "  LAVENDER "%d\n" RESET, map->ceiling_color);
    */
    printf("NO %s\n", map->no_path);
    printf("SO %s\n", map->so_path);
    printf("WE %s\n", map->we_path);
    printf("EA %s\n", map->ea_path);
    printf("F %d\n" , map->floor_color);
    printf("C %d\n" , map->ceiling_color);

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

void    ft_parse_assets(t_data *data, t_map *map, char *file_path)
{
    (void)map;
    int fd;
    char *line;
    int is_valid_line;

    fd = ft_open_file(data, file_path);
    is_valid_line = 1;
    while (is_valid_line)
    {
        line = ft_get_next_line(fd);
        if (!line)
            break ; 
        if (ft_skip_isspace_line(line))
            continue ;
        else if (ft_is_tex_line(data, line))
           ft_load_texture(data, &data->map, line);  
        else if (ft_valid_color_line(data, line))
           ft_load_color(data, &data->map, line);  
        else 
            is_valid_line = 0; 
        free(line);
    }
    ft_display(&data->map);
}	