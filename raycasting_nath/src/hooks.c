#include "raycasting.h"

int	close_handler(void *param)
{
    t_var *var = (t_var *)param;

	ft_free(&var->map);
    mlx_destroy_window(var->mlx, var->mlx_win);
    mlx_destroy_display(var->mlx);
	free(var->mlx);
    free(var);
	exit(0);
	return (0);
}

int	key_handler(int keycode, void *param)
{
    t_var *var = (t_var *)param;

	if (keycode == 65307)
		close_handler(var);
	return (0);
}

void	init_hooks(t_var *var)
{
	mlx_key_hook(var->mlx_win, (int (*)())key_handler, var);
	mlx_hook(var->mlx_win, 17, 0, (int (*)())close_handler, var);
}
