#include "../inc/cube_3d.h"

static int    ft_color_overflow(char *nbr)
{
    int n;

    n = ft_atoi(nbr);
    return (n < 0 || n > 255);
}

static int    ft_check_color(char *line)
{
    int i;
    char **tab;

    tab = ft_split_color(line);
    if (!tab)
        return 0;
    i = 0;
    while (tab[i])
    {
        if (!ft_isfull_dig(tab[i]) || ft_color_overflow(tab[i]))
            return ft_freedtab(tab), 0;
        i++;
    }
    return ft_freedtab(tab), 1;
}

static  int    ft_is_color_component(char *line)
{
    if (ft_strncmp("F ", line, 2) && ft_strncmp("C ", line, 2))
        return 0;
    return 1;
}

int    ft_valid_color_line(t_data *data, char *line)
{
    char *tmp;

    tmp = line;
    if (!ft_is_color_component(line))
        return 0; 
    ft_skip_isspace(2, &tmp);
    if (!ft_check_color(tmp))
        ft_game_exit(data, "colors settings failed");
    return 1;
}