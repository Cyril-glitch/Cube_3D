#include "../inc/cube_3d.h"

static int	ft_is_surrounded(char **grid, int y, int x)
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
	return (1);
}

static void	ft_check_map_content(t_data *data, char **grid, int y, int x)
{
	if (!ft_is_map_content(grid[y][x]) || !ft_is_surrounded(grid, y, x))
	{
		ft_display_map_error(grid, y, x);
		ft_game_exit(data, "invalid map components.");
	}
}

static void	ft_check_player(t_data *data, char **grid, int y, int x)
{
	if (ft_is_player(grid[y][x]))
	{
		if (ft_player_is_set(&data->player))
			ft_game_exit(data, "multiple players.");
		ft_init_player_pos(&data->player, y, x);
	}
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
			ft_check_map_content(data, grid, y, x);
			ft_check_player(data, grid, y , x);
			x++;
		}
		y++;
	}
	if (!ft_player_is_set(player))
		ft_game_exit(data, "no player.");
}