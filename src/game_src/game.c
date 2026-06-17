#include "../../inc/cube_3d.h"

static void ft_game_update(t_data *data)
{
	update(data);
}

static void ft_game_engine(t_data *data)
{
	ft_memset(data->screen.addr, 0, data->win_size.y * data->win_size.x * 4);
	ft_raycaster(data, data->ray);
}

static void ft_game_draw(t_data *data)
{
	ft_render_draw(data->ray, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.img, 0, 0);
}

int	ft_game_loop(t_data *data)
{
	double	new_time;

	new_time = get_time(data->start);
	if (new_time - data->last_frame <= CAP)
		return (0);
	data->last_frame = get_time(data->start);
	double t0 = get_time(data->start);
	printf("\nupdate: %.3f ms\n", get_time(data->start) - t0);
	t0 = get_time(data->start);
	ft_game_engine(data);
	printf("\nengine: %.3f ms\n\n", get_time(data->start) - t0);
	t0 = get_time(data->start);
	ft_game_draw(data);
	printf("total draw: %.3f ms\n", get_time(data->start) - t0);
	ft_display_fps(data);
	ft_game_update(data);
	//gettimeofday(&data->last_frame, NULL);
	return (0);
}
