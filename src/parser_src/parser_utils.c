#include    "../inc/cube_3d.h"

int ft_open_file(t_data *data, char *file_path)
{
    int fd;

	fd = open(file_path, O_RDONLY);
    if (fd == -1)
        ft_game_exit(data, "can't open file.");
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