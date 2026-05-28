#include "../inc/cube_3d.h"

static void	ft_free_mlx(t_data *data)
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

static void ft_free_texture()
{

}

static void ft_free_map(t_map *map)
{
    if (!map)
        return ;
    if (map->grid)
        ft_freedtab(map->grid);
    if (map->no_path)
        free(map->no_path);
    if (map->so_path)
        free(map->so_path);
    if (map->ea_path)
        free(map->ea_path);
    if (map->we_path)
        free(map->we_path);
}


void	ft_free_data(t_data *data)
{
    if (!data)
        return;
    if (data->fd)
        close(data->fd);
    if (data->line)
        free(data->line);
    ft_free_mlx(data->mlx);
    ft_free_texture();
    ft_free_map(&data->map);
}