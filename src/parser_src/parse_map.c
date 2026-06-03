#include "../../inc/cube_3d.h"

void	ft_parse_map(t_data *data, t_map *map, char **line)
{
	ft_extract_map(data, map, line);
	ft_map_checker(data, &data->player, data->map.grid);
	ft_map_display(map->grid);
}