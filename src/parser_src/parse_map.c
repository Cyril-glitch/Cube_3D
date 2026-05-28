#include "../inc/cube_3d.h"

static ft_is_map_content(char c, int index)
{
    if ()

}

static int ft_valid_line(char *line, int *start, int *end)
{
    int i;

    i = 0;
    while(ft_isspace(line[i]) || line[i] == '1' && i < start)
        i++;
    if (i < start)
        return 0;
    while(ft_is_map_content(line[i], ) && i < end)
        i++;
    if (i < end)
        return 0;
    while(ft_isspace(line[i]) || line[i] == '1')
        i++;
    if (line[i])
        return 0;
    return 1;
}

static int ft_first_wall(char *line, int *start, int *end)
{
    char *line;
    int i;

    i = 0;
    while(ft_isspace(line[i]))
        i++;
    if (line[i] != '1')
        return 0;
    while (line[i] == '1')
        i++;
    if (line[i] != 0 && !ft_isspace(line[i]))
        return 0;
    *end = i;
    *start = i;
    while (line[i] && ft_isspace(line[i]))
        i++;
    if (line[i])
        return 0;
    return 1;
}

void    ft_parse_map(t_data *data, t_map *map, char **line)
{
    (void)map;
    //int nl;
    int start;
    int end;

    //nl = 0;
    start = 0;
    end = 0;
    if (ft_first_wall(*line, &start, &end))
        printf("%s\n", *line);
    else 
        ft_game_exit(data, "wrong map settings.");
    while (*line)
    {
        if (ft_valid_line(*line, &start, &end))
        {
            printf("%s\n", *line);
            free(line);
            *line = ft_get_next_line(data->fd);
        }
        else 
            ft_game_exit(data, "invalid map.");
    }
}