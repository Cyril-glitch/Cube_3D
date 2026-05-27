#include    "../inc/cube_3d.h"

int ft_open_file(t_data *data, char *file_path)
{
    int fd;

	fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        ft_error_file(file_path);
        ft_game_exit(data, NULL);
    }
    return (fd); 
}


int     ft_skip_isspace_line(char *line)
{
    while (*line)
    {
        if (ft_isspace(*line))
            line++;
        else
            return (0);
    }
    return free(line), (1);
} 

void   ft_skip_isspace(int start, char **line)
{
    *line += start;
    while (ft_isspace(**line))
        (*line)++;
}

char    **ft_split_color(char *line)
{
    char    **tab;

    tab = ft_split(line, ',');
    if (!tab || ft_tablen(tab) != 3)
    {
        if (tab)
            ft_freedtab(tab);
        return NULL;
    } 
    return tab;
}