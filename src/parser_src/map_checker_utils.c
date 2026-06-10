#include "../../inc/cube_3d.h"

int	ft_is_map_content(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E' 
			|| c == VER_DOOR || c == HOR_DOOR || c == SPRITE_1 || c == '1' || c == '0'
		|| c == ' ');
}

int	ft_is_walkable(char c)
{
	return (ft_is_map_content(c) && !ft_pit_fall(c) && c != '1');
}

int	ft_pit_fall(char c)
{
	return (c == '\0' || ft_isspace(c));
}

int	ft_is_offset(char **grid, int y, int x)
{
	return ((size_t)(x - 1) > ft_strlen(grid[y - 1]) || (size_t)(x - 1) > ft_strlen(grid[y + 1]));
}

int  ft_is_limit_component(char **grid, int y, int x)
{
    return (x == 0 || y == 0 || !grid[y + 1]); 
}