#include "../inc/cube_3d.h"

int main(int ac, char **av)
{
    (void)av;
    t_data data;
	
    ft_display_logo();
    if (ac != 2)
        return 0;     
    ft_init_data(&data);
    ft_parser(&data, &data.map, av[1]);
    ft_free_data(&data);
}

/*
int	main(void)
{
	t_data	data;
	int		i;

	ft_memset(&data, 0, sizeof(t_data));
	init_null(&data);
	data.map = map_init();
	if (!data.map)
		return (ft_printf("error creating map\n"), 1);
	i = 0;
	data.map_width = ft_strlen(data.map[0]);
	data.map_height = 0;
	while (data.map[i])
	{
		ft_printf("%s\n", data.map[i++]);
		data.map_height++;
	}
	data.start = get_time(0);
	data.time = data.start;
	if (!init_mlx_and_ray(&data))
		return (safe_cleanup(&data), 1);
	if (!init_screen(&data))
		return (safe_cleanup(&data), 1);
	if (!init_textures(&data))
		return (safe_cleanup(&data), 1);
	if (!init_mini_map(&data, &data.mini_map))
		return (safe_cleanup(&data), 1);
	init_player_pos(&data);
	init_keys(&data);
	init_hooks(&data);
	mlx_loop(data.mlx);
	safe_cleanup(&data);
	return (0);
}
*/