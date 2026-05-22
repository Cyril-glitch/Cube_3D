#include "../inc/cube_3d.h"

int    ft_is_cardinal(char *line)
{

    if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3))
        return 1;
    if (!ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
        return 1;
    return 0;
}

void    ft_is_tex_line(t_data *data,char *line)
{ 
    if (ft_is_cardinal(line))
        line += 3;
    while (ft_isspace(*line))
        line++;
    ft_open_file(data, line);
}