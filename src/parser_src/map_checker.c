#include "../inc/cube_3d.h"

static int	ft_is_surrounded(char **grid, int y, int x)
{
	if (ft_is_walkable(grid[y][x]))
	{
		if (ft_is_limit_component(grid, y, x))
			return ft_display_map_error(grid, y, x),0;
		if (ft_is_offset(grid, y, x))
			return ft_display_map_error(grid, y, x),0;
		if (ft_pit_fall(grid[y - 1][x]) || ft_pit_fall(grid[y + 1][x]))
			return ft_display_map_error(grid, y, x),0;
		else if (ft_pit_fall(grid[y][x - 1]) || ft_pit_fall(grid[y][x + 1]))
			return ft_display_map_error(grid, y, x),0;
	}
	return (1);
}

void	ft_map_checker(t_data *data, t_player *player, char **grid)
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
				ft_game_exit(data, "invalid map components.");
			if (ft_is_player(grid[y][x]))
			{
				if (ft_check_player(player))
					ft_game_exit(data, "multiple players.");
				ft_init_player_pos(player, y, x);
			}
			x++;
		}
		y++;
	}
	if (!ft_check_player(player))
		ft_game_exit(data, "no player.");	
}