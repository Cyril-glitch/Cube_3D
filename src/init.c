#include    "../inc/cube_3d.h"

void ft_init_data(t_data *data)
{
        ft_bzero(data, sizeof(*data));
}

void ft_init_mlx(t_data *data)
{
        data->mlx = mlx_init();
        if (!data->mlx)
        {
                ft_free_data(data);
                exit(0);
        }
        data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "Cube_3d");
        if (!data->win)
        {
                ft_free_data(data);
                exit(0);
        }
        data->image.img_ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
        if (!data->image.img_ptr)
        {
                ft_free_data(data);
                exit(0);
        }
        data->image.addr = mlx_get_data_addr(data->image.img_ptr, &data->image.bpp, &data->image.line_len,&data->image.endian);
}
