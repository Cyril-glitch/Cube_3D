#include "raycasting.h"


int	choose_color(int n)
{
	if (n == 1)
		return (0xf54242);
	if (n == 2)
		return (0x5df542);
	if (n == 3)
		return (0x4542f5);
	if (n == 4)
		return (0xf542d7);
	if (n == 5)
		return (0xf5d142);
	return (0x0d0d0d);
}

int    ft_set_color(t_ray ray, char **map)
{
    int color;

    color = choose_color(map[ray.map_y][ray.map_x] - 48);
    if (ray.side)
        color /= 2;
    return color;
}

void    ft_wall_draw(t_ray *ray, t_var *var, char **map, int w, int h)
{
    int x;
    int y;
    int color;

    x = 0;
    y = 0;
    while(x < w)
    {
        color = ft_set_color(ray[x], map);
        y = 0;
        while(y < h)
        {
            if (y >= ray[x].draw_start && y <= ray[x].draw_end)
                mlx_pixel_put(var->mlx, var->mlx_win, x, y, color);  
            y++;
        }
        x++;
    }
}

void    ft_render_draw(t_ray *ray, t_var *var)
{
    ft_wall_draw(ray, var, var->map, var->win_size.x, var->win_size.y);
}