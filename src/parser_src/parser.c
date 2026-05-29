#include "../inc/cube_3d.h"

void    ft_parser(t_data *data,t_map *map, char *file_path)
{
    data->fd = ft_open_file(data, file_path);
    ft_parse_assets(data, map, &data->line);
    ft_assets_display(map);
    ft_parse_map(data, map, &data->line);
}
