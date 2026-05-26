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

int     ft_isspace_line(char *line)
{
    while (*line)
    {
        if (ft_isspace(*line))
            line++;
        else
            return 0;
    }
    return 1;
}

void     ft_trim_newline(char *line)
{
    int len;

    len = ft_strlen(line);
    ft_bzero(line + (len - 1), 1);
}