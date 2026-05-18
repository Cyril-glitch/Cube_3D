#include "../inc/cube_3d.h"

int main(int ac, char **av)
{
    (void)av;
    t_data data;

    if (ac != 2)
        return 0;     
    ft_init_data(&data);
    ft_init_mlx(&data);
}