#include "../inc/cube_3d.h"

static void    ft_check_extension(t_data *data, char *path)
{
    int len;

    len = ft_strlen(path);
    if (len < 5 || ft_strcmp(path + (len - 4), ".cub"))
        ft_game_exit(data , "invalid file extension (expected .cub).");
}

void    ft_parser(t_data *data,t_map *map, char *file_path)
{
    ft_check_extension(data, file_path);
    data->fd = ft_open_file(data, file_path);
    ft_parse_assets(data, map, &data->line);
    ft_parse_map(data, map, &data->line);
}
