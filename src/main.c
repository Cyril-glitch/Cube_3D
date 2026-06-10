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

	if (!init_mlx_and_ray(&data))
		ft_game_exit(&data, "mlx init");
	if (!init_screen(&data))
		ft_game_exit(&data, "screen init");
	if (!init_textures(&data))
		ft_game_exit(&data, "textures init");
	if (!ft_assign_sprites_textures(&data, SPRITE_1))
		ft_game_exit(&data, "sprites init");
	init_sprites_pos(data.sprites, &data.map, SPRITE_1);
	if (!init_mini_map(&data, &data.mini_map))
		ft_game_exit(&data, "mini map init");
	if (!init_doors(&data, data.map.grid))
		ft_game_exit(&data, "doors init");
	init_player_dir(&data);
	init_keys(&data);
	init_hooks(&data);
	ft_init_backgrd(&data, &data.bgrd);
	mlx_loop(data.mlx);
	ft_free_data(&data);
	ft_memset(&data, 0, sizeof(t_data));
	return (0);
}
