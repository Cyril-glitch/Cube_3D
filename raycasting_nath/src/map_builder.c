#include "raycasting.h"

static int	get_line(int i, int fd, char **map)
{
	int	len;

	map[i] = get_next_line(fd, 0);
	if (!map[i])
		return (1);
	len = (int)ft_strlen(map[i]);
	if (len > 0 && map[i][len - 1] == '\n')
		len--;
	map[i][len] = 0;
	return (0);
}

char	**map_init(void)
{
	int		fd;
	char	**res;
	int		i;

	fd = open("map", O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	res = calloc((24 + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i < 24)
	{
		if (get_line(i, fd, res) == 1)
		{
			ft_free(&res);
			return (NULL);
		}
		i++;
	}
	res[i] = 0;
	get_next_line(fd, 1);
	close(fd);
	return (res);
}
