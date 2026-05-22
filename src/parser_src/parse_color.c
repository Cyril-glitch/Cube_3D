#include "../inc/cube_3d.h"

static char    **ft_split_color(char *line)
{
    char    **tab;

    tab = ft_split(line, ',');
    if (!tab || ft_tablen(tab) != 3)
    {
        if (tab)
            free(tab);
        return NULL;
    } 
    return tab;
}

static int    ft_is_valid_color(char *line)
{
    int i;
    char **tab;

    tab = ft_split_color(line);
    if (!tab)
        return 0;
    i = 0;
    while (i < 3)
    {
        if (!ft_isfull_dig(tab[i]))
            i++;
    }
    return (i == 3);
}

void    ft_is_color_line(t_data *data, char *line)
{
    int i;

    if (ft_strncmp("F ", line, 2) && ft_strncmp("C ", line, 2))
        return ;
    line += 2;
    while (ft_isspace(*line))
        line++;        
    if (!ft_valid_color(line))
        ft_game_exit(data, "colors settings failed");
}