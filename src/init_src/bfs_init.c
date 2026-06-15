#include "../../inc/cube_3d.h"

static void    ft_max_width(t_data *data, char **grid)
{
    int x;
    int y;
    int max;

    y = 0;
    max = 0;
    while(grid[y])
    {
        x = 0;
        while (grid[y][x])
            x++;
        if (x > max)
            max = x;
        y++;
    }
    data->bfs.max_w = max;
    data->bfs.max_h = y;
}



void    ft_init_bfs(t_data *data)
{
    int w;
    int h;

    ft_max_width(data, data->map.grid);
    w = data->bfs.max_w;
    h = data->bfs.max_h;
    data->bfs.queue = malloc(sizeof(t_point) * (w * h));
    if (!data->bfs.queue)
        ft_game_exit(data, "Memory allocation failed (queue).");
    data->bfs.came_from = malloc(sizeof(t_point) * (w * h));
    if (!data->bfs.came_from)
        ft_game_exit(data, "Memory allocation failed (came_from)."); 
}