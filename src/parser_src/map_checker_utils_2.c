#include "../inc/cube_3d.h"

void	ft_init_player_pos(t_player *player, int y, int x)
{
	player->pos_y = y;
	player->pos_x = x;
}

int	ft_player_is_set(t_player *player)
{
	if (player->pos_x || player->pos_y)
        return 1;
    return 0;
}

int	ft_is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void ft_display_map_error(char **grid, int err_y, int err_x)
{
	int y;
    int x;

    y = 0;
    while(grid[y])
    {
        x = 0;
        while(grid[y][x])
        {
            if (grid[y][x] == '1')
                printf(B_BLUE "1" RESET);
            else if (ft_is_player(grid[y][x]))
                printf(GOLD "%c" RESET, grid[y][x]);
            else if (y == err_y && x == err_x)
                printf(B_RED "%c" RESET, grid[y][x]);
            else 
                printf("%c", grid[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
}