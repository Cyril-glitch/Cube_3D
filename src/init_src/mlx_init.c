#include "../../inc/cube_3d.h"

int	init_mlx_and_ray(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	mlx_get_screen_size(data->mlx, &data->win_size.x, &data->win_size.y);
	printf("win_size_x : %d, win_size_y : %d\n", data->win_size.x, data->win_size.y);
	data->mlx_win = mlx_new_window(data->mlx, data->win_size.x,
			data->win_size.y, "Raycaster");
	if (!data->mlx_win)
		return (0);
	data->ray = malloc(sizeof(t_ray) * data->win_size.x);
	if (!data->ray)
		return (0);
	return (1);
}
