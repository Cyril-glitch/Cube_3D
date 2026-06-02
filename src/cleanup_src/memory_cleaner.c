#include "../inc/cube_3d.h"

static void	ft_free_mlx(t_data *data)
{
	if (!data)
		return ;
	if (data->screen.img)
		mlx_destroy_image(data->mlx, data->screen.img);
	if (data->mini_map.image.img)
		mlx_destroy_image(data->mlx, data->mini_map.image.img);
	if (data->mini_map.arrow.img)
		mlx_destroy_image(data->mlx, data->mini_map.arrow.img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

static void ft_free_texture(t_data *data)
{
	if (!data)
		return ;
	if (data->textures)
	{
		free(data->textures);
		data->textures = NULL;
	}
}

static void ft_free_maps_settings(t_data *data)
{
    if (data->fd)
		close(data->fd);
	if (data->line)
		free(data->line);
    if (data->map.no_path)
        free(data->map.no_path);
    if (data->map.so_path)
        free(data->map.so_path); 
    if (data->map.we_path)
        free(data->map.we_path);
    if (data->map.ea_path)
        free(data->map.ea_path);
    if (data->map.grid)
        ft_freedtab(data->map.grid);
}

void	ft_free_data(t_data *data)
{
	if (!data)
		return;
    ft_free_maps_settings(data);
	ft_free_mlx(data);
	ft_free_texture(data);
}
