#include "../inc/cube_3d.h"

static int    ft_is_cardinal(char *line)
{

    if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3))
        return 1;
    if (!ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
        return 1;
    return 0;
}

int    ft_is_tex_line(t_data *data,char *line)
{
    int fd;
    char *tmp;
    
    tmp = line;
    if (!ft_is_cardinal(tmp))
        return 0;
    tmp += 3;
    while (ft_isspace(*tmp))
        tmp++;
    ft_trim_newline(tmp);
    fd = open(tmp, O_RDONLY);
    if (fd == -1)
    {
        ft_error_file(tmp);
        free(line);
        ft_game_exit(data, NULL);
    }
    close(fd);

    return 1;
}