#include "../inc/cube_3d.h"

void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->image.img_ptr)
		mlx_destroy_image(data->mlx, data->image.img_ptr);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}