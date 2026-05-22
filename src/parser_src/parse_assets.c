#include "../inc/cube_3d.h"


void    ft_parse_assets(t_data *data, t_map *map, char *file_path)
{
    int fd;
    char *line;

    fd = ft_open_file(data, file_path);
    line = ft_get_next_line(fd);
    while (ft_is_assets_line(line))
    {
        line = ft_get_next_line(fd);
    }
}
	