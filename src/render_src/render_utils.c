#include "../../inc/cube_3d.h"

int	choose_color(int n)
{
	if (n == 1)
		return (0xf54242);
	if (n == 2)
		return (0x5df542);
	if (n == 3)
		return (0x4542f5);
	if (n == 4)
		return (0xf542d7);
	if (n == 5)
		return (0xf5d142);
	return (0x0d0d0d);
}

int    ft_set_color(t_ray ray, char **map)
{
	int color;

	color = choose_color(map[ray.map_y][ray.map_x] - 48);
	if (ray.side)
		color /= 2;
	return color;
}

void	ft_display_fps(t_data *data)
{
	char *fps;

	fps = ft_dtoa(1 / data->frame_time, 3);
	if (!fps)
		ft_game_exit(data, "memory allocation failed (fps)");
	mlx_string_put(data->mlx, data->mlx_win,data->win_size.x - 100, 40, 0xFFFF00, "fps: ");
	mlx_string_put(data->mlx, data->mlx_win,data->win_size.x - 60, 40, 0x00FF1A, fps);
	free(fps);
}