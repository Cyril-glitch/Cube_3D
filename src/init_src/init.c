#include "../../inc/cube_3d.h"

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
	init_player_dir(data);
	init_keys(data);
	init_hooks(data);
	ft_init_backgrd(data, &data->bgrd);
	ft_init_bot_tex(data);
	ft_init_bfs(data);
}