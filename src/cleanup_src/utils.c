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

double	get_time(double start)
{
	t_timeval	tv;
	double		current;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	current = (double)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (current - start);
}
