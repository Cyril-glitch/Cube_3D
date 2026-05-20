#include "raycasting.h"


void	ft_free(char ***s)
{
	int	i;

	i = 0;
	while ((*s)[i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
		i++;
	}
	free(*s);
	*s = NULL;
}

int	main(void)
{
	t_var	*var = malloc(sizeof(t_var));
	t_ray 	*ray;
	int		i;

	var->map = map_init();
	i = 0;
	if (!var->map)
		return (ft_printf("error creating map\n"), 1);
	while (var->map[i])
		ft_printf("%s\n", var->map[i++]);
	var->win_size.x = 640;
	var->win_size.y = 480;
	var->mlx = mlx_init();
	if (!var->mlx)
		printf("ok\n");
	var->mlx_win = mlx_new_window(var->mlx, var->win_size.x,
			var->win_size.y, "Raycaster");
	init_hooks(var);
	ray = ft_raycaster(var);
	ft_render_draw(ray, var);
	mlx_loop(var->mlx);
	ft_free(&var->map);
	free(var);
	return (0);
}
