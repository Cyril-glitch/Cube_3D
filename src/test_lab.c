#include    "../inc/cube_3d.h"

void ft_init_data(t_data *data)
{
        ft_bzero(data, sizeof(*data));
}

int main()
{
    t_data  data;

    ft_init_data(&data);
    printf("plane x = %f\n", data.player.plane_x);
    return 0;
}