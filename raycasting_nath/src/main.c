#include "raycasting.h"

int	main(void)
{
	t_var	var;
	int		i;

	init_null(&var);
	var.map = map_init();
	if (!var.map)
		return (ft_printf("error creating map\n"), 1);
	i = 0;
	var.map_height = 0;
	while (var.map[i])
	{
		ft_printf("%s\n", var.map[i++]);
		var.map_height++;
	}
	var.win_size.x = 640;
	var.win_size.y = 480;
	var.start = get_time(0);
	var.time = var.start;
	if (!init_mlx_and_ray(&var))
		return (safe_cleanup(&var), 1);
	if (!init_screen(&var))
		return (safe_cleanup(&var), 1);
	if (!init_textures(&var))
		return (safe_cleanup(&var), 1);
	init_player_pos(&var);
	init_keys(&var);
	init_hooks(&var);
	mlx_loop(var.mlx);
	safe_cleanup(&var);
	return (0);
}
