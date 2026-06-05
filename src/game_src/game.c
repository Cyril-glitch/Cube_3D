#include "../../inc/cube_3d.h"

static void ft_game_update(t_data *data)
{
    update(data);
}

static void ft_game_engine(t_data *data)
{
	ft_raycaster(data, data->ray);
}

static void ft_game_draw(t_data *data) 
{
	ft_memset(data->screen.addr, 0, data->win_size.y * data->win_size.x * 4);
    ft_render_draw(data->ray, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.img, 0, 0);
}

int	ft_game_loop(t_data *data)
{
    ft_game_update(data);
    ft_game_engine(data);
    ft_game_draw(data);
		return (0);
}
