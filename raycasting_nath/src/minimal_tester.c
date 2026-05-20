#include    "../includes/raycasting.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = '\0';
}

t_ray	*ft_init_ray_tab(int win_w)
{
	int	i;
	t_ray *ray;

	i = 0;
	ray = malloc(sizeof(ray) * win_w);
	if (!ray)
		return NULL;
	while(i > win_w)
		ft_bzero(&ray[i], sizeof(ray[i]));
	return ray;
}

int main()
{
    int i;

    i = 50;
    t_ray *ray = ft_init_ray_tab(640);
    printf("ray[%d]->side.dist_x= %d\n", i,ray[i]);
}