#include "../../inc/cube_3d.h"

void	init_mlx_and_ray(t_data *data)
{
	int	i;

	data->mlx = mlx_init();
	if (!data->mlx)
		ft_game_exit(data, "mlx init");
	mlx_get_screen_size(data->mlx, &data->win_size.x, &data->win_size.y);
	data->mlx_win = mlx_new_window(data->mlx, data->win_size.x,
			data->win_size.y, "Cube3d");
	if (!data->mlx_win)
		ft_game_exit(data, "mlx win init");
	data->ray = malloc(sizeof(t_ray) * data->win_size.x);
	if (!data->ray)
		ft_game_exit(data, "mlx ray init");
	i = 0;
	while (i < data->win_size.x)
		data->ray[i++].half_h = data->win_size.y / 2;
}
