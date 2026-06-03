#include "../../inc/cube_3d.h"

void    ft_parser(t_data *data,t_map *map, char *file_path)
{

    ft_display_logo();
    data->fd = ft_open_file(data, file_path);
    ft_parse_assets(data, map, &data->line);
    ft_parse_map(data, map, &data->line);
}
