#include "../inc/cube_3d.h"

static void   ft_check_path(t_data *data,char *file_path)
{
    int fd;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        ft_error_file(file_path);
        ft_game_exit(data, NULL);
    }
    close(fd);
}

static int    ft_is_tex_component(char *line)
{

    if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3))
        return 1;
    if (!ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
        return 1;
    return 0;
}

int    ft_valid_tex_line(t_data *data,char *line)
{
    char *tmp;
    
    tmp = line;
    if (!ft_is_tex_component(tmp))
        return 0;
    ft_skip_isspace(3, &tmp);
    ft_check_path(data, tmp);
    return 1;
}