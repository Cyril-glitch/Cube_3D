#include "../../inc/cube_3d.h"

int	init_global(t_data *data, char **av)
{
	init_null(data);
	ft_parser(data, &data->map, av[1]);
	data->start = get_time(0);
	data->time = data->start;
	if (!init_mlx_and_ray(data))
		ft_game_exit(data, "mlx init");
	if (!init_screen(data))
		ft_game_exit(data, "screen init");
	if (!init_textures(data))
		ft_game_exit(data, "textures init");
	if (!ft_init_backgrd(data, &data->bgrd))
		ft_game_exit(data, "background init");
	if (!ft_assign_sprites_textures(data, SPRITE_1))
		ft_game_exit(data, "sprites init");
	init_sprites_pos(data->sprites, &data->map, SPRITE_1);
	if (!init_mini_map(data, &data->mini_map))
		ft_game_exit(data, "mini map init");
	if (!init_doors(data, data->map.grid))
		ft_game_exit(data, "doors init");
	init_player_dir(data);
	init_keys(data);
	init_hooks(data);
	return (1);
}

void ft_init(t_data *data)
{
	if (!init_mlx_and_ray(data))
		ft_game_exit(data, "mlx init");
	if (!init_screen(data))
		ft_game_exit(data, "screen init");
	if (!init_textures(data))
		ft_game_exit(data, "textures init");
	if (!init_sprites_texture(data, 2))
		ft_game_exit(data, "sprites init");
	init_sprites_pos(data->sprites, &data->map, 2);
	if (!init_mini_map(data, &data->mini_map))
		ft_game_exit(data, "mini map init");	
	ft_init_stats(data);
	init_player_dir(data);
	init_keys(data);
	init_hooks(data);
	ft_init_backgrd(data, &data->bgrd);
	ft_init_bot_tex(data);
	ft_init_bfs(data);
}