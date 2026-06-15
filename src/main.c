#include "../inc/cube_3d.h"


int	main(int ac, char **av)
{
    (void)av;
    t_data data;
	
    ft_display_logo();
    if (ac != 2)
		return (0);
	init_global(&data, av);
	mlx_loop(data.mlx);
	ft_free_data(&data);
	ft_memset(&data, 0, sizeof(t_data));
	return (0);
}
