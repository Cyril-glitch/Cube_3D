#include "raycasting.h"

void	init_null(t_var *var)
{
	var->mlx = NULL;
	var->mlx_win = NULL;
	var->map = NULL;
	var->screen.img = NULL;
	var->screen.addr = NULL;
	var->textures = NULL;
	var->ray = NULL;
}

void	init_player_pos(t_var *var)
{
	var->player.pos_x = 22;
	var->player.pos_y = 12;
	var->player.dir_x = -1;
	var->player.dir_y = -1;
	var->player.plane_x = 0;
	var->player.plane_y = 0.66;
}

void	init_keys(t_var *var)
{
	var->keys.w = 0;
	var->keys.a = 0;
	var->keys.s = 0;
	var->keys.d = 0;
	var->keys.right = 0;
	var->keys.left = 0;
}

int	init_mlx_and_ray(t_var *var)
{
	var->mlx = mlx_init();
	if (!var->mlx)
		return (0);
	var->mlx_win = mlx_new_window(var->mlx, var->win_size.x,
			var->win_size.y, "Raycaster");
	if (!var->mlx_win)
		return (0);
	var->ray = malloc(sizeof(t_ray) * var->win_size.x);
	if (!var->ray)
		return (0);
	return (1);
}

int	init_textures(t_var *var)
{
	int	i;

	var->textures = malloc(sizeof(t_img) * 4);
	if (!var->textures)
		return (0);
	i = 0;
	while (i < 4)
	{
		var->textures[i].img = NULL;
		var->textures[i].addr = NULL;
		i++;
	}

	var->textures[0].img = mlx_xpm_file_to_image(var->mlx, "wolftex2/eagle.xpm",
			&var->textures[0].w, &var->textures[0].h);
	if (!var->textures[0].img)
		return (0);
	var->textures[0].addr = mlx_get_data_addr(var->textures[0].img, &var->textures[0].bpp,
			&var->textures[0].line_length, &var->textures[0].endian);
	if (!var->textures[0].addr)
		return (0);

	var->textures[1].img = mlx_xpm_file_to_image(var->mlx, "wolftex2/redbrick.xpm",
			&var->textures[1].w, &var->textures[1].h);
	if (!var->textures[1].img)
		return (0);
	var->textures[1].addr = mlx_get_data_addr(var->textures[1].img, &var->textures[1].bpp,
			&var->textures[1].line_length, &var->textures[1].endian);
	if (!var->textures[1].addr)
		return (0);

	var->textures[2].img = mlx_xpm_file_to_image(var->mlx, "wolftex2/purplestone.xpm",
			&var->textures[2].w, &var->textures[2].h);
	if (!var->textures[2].img)
		return (0);
	var->textures[2].addr = mlx_get_data_addr(var->textures[2].img, &var->textures[2].bpp,
			&var->textures[2].line_length, &var->textures[2].endian);
	if (!var->textures[2].addr)
		return (0);

	var->textures[3].img = mlx_xpm_file_to_image(var->mlx, "wolftex2/greystone.xpm",
			&var->textures[3].w, &var->textures[3].h);
	if (!var->textures[3].img)
		return (0);
	var->textures[3].addr = mlx_get_data_addr(var->textures[3].img, &var->textures[3].bpp,
			&var->textures[3].line_length, &var->textures[3].endian);
	if (!var->textures[3].addr)
		return (0);
	
	return (1);
}

int	init_screen(t_var *var)
{
	var->screen.img = mlx_new_image(var->mlx, var->win_size.x, var->win_size.y);
	if (!var->screen.img)
		return (0);
	var->screen.addr = mlx_get_data_addr(var->screen.img, &var->screen.bpp,
			&var->screen.line_length, &var->screen.endian);
	if (!var->screen.img)
		return (0);
	return (1);
}
