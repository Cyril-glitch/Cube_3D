#include "../inc/cube_3d.h"

int	ft_is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	ft_is_surrounded(char **grid, int y, int x)
{
	if (ft_is_walkable(grid[y][x]))
	{
        if (ft_is_limit_component(grid, y, x))
            return (0);
        if (ft_is_offset(grid, y, x))
            return (0);
		if (ft_pit_fall(grid[y - 1][x]) || ft_pit_fall(grid[y + 1][x]))
			return (0);
		else if (ft_pit_fall(grid[y][x - 1]) || ft_pit_fall(grid[y][x + 1]))
			return (0);
	}
	return 1;
}

void ft_map_checker(t_data *data, t_player *player, char **grid)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{				
			if (!ft_is_map_content(grid[y][x]) || !ft_is_surrounded(grid, y, x))
			{
				printf("y = %d \nx = %d \ncomponent = %c\n", y, x, grid[y][x]);
				ft_game_exit(data, "invalid map components.");
			}
			if (ft_is_player(grid[y][x]))
			{
				if(player->pos_x || player->pos_y)
					ft_game_exit(data, "multiple players.");
				player->pos_x = x;
				player->pos_y = y;
			}
			x++;
		}
		y++;
	}
}