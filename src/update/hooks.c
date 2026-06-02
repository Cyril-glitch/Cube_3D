#include "../inc/cube_3d.h"

void	safe_cleanup(t_var *var)
{
	int	i;

	if (var->map)
		ft_free(&var->map);
	if (var->ray)
		free(var->ray);
	if (var->screen.img)
		mlx_destroy_image(var->mlx, var->screen.img);
	if (var->mini_map.image.img)
		mlx_destroy_image(var->mlx, var->mini_map.image.img);
	if (var->mini_map.arrow.img)
		mlx_destroy_image(var->mlx, var->mini_map.arrow.img);
	i = 0;
	while (i < 64)
	{
		if (var->mini_map.rotation[i].img)
			mlx_destroy_image(var->mlx, var->mini_map.rotation[i].img);
		i++;
	}
	if (var->textures)
	{
		i = 0;
		while (i < 4)
		{
			if (var->textures[i].img)
				mlx_destroy_image(var->mlx, var->textures[i].img);
			i++;
		}
		free(var->textures);
	}
	if (var->mlx_win)
		mlx_destroy_window(var->mlx, var->mlx_win);
	if (var->mlx)
	{
		mlx_destroy_display(var->mlx);
		free(var->mlx);
	}
}

int	close_handler(void *param)
{
    t_var *var = (t_var *)param;

	safe_cleanup(var);
	exit(0);
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_var	*var = (t_var *)param;

	if (keycode == 65307)
		close_handler(var);
	if (keycode == XK_w)
		var->keys.w = 1;
	if (keycode == XK_a)
		var->keys.a = 1;
	if (keycode == XK_s)
		var->keys.s = 1;
	if (keycode == XK_d)
		var->keys.d = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_var	*var = (t_var *)param;

	if (keycode == XK_w)
		var->keys.w = 0;
	if (keycode == XK_a)
		var->keys.a = 0;
	if (keycode == XK_s)
		var->keys.s = 0;
	if (keycode == XK_d)
		var->keys.d = 0;
	return (0);
}

void	init_hooks(t_var *var)
{
	mlx_hook(var->mlx_win, 2, 1L << 0, key_press, var);
	mlx_hook(var->mlx_win, 3, 1L << 1, key_release, var);
	mlx_hook(var->mlx_win, 17, 0, close_handler, var);
	mlx_loop_hook(var->mlx, update, var);
}
