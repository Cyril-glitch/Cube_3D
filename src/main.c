#include "../inc/cube_3d.h"


int	main(int ac, char **av)
{
    (void)av;
    t_data data;
	
    ft_display_logo();
    if (ac != 2)
		return (0);
	init_null(&data);
    ft_init_data(&data);
    ft_parser(&data, &data.map, av[1]);
	data.start = get_time(0);
	data.time = data.start;	
	ft_init(&data);	
    ft_bfs(&data, &data.bfs);
	mlx_loop(data.mlx);
	ft_free_data(&data);
	ft_memset(&data, 0, sizeof(t_data));
	return (0);
}
