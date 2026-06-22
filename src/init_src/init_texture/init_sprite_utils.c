#include "../../inc/cube_3d.h"

void	treat_transparency(t_img *image, int ref_color, unsigned int tolerance)
{
	int	x;
	int	y;
	int	*pixel;

	y = 0;
	while (y < image->h)
	{
		x = 0;
		while (x < image->w)
		{
			pixel = (int *)(image->addr + x * image->line_length + y
					* (image->bpp / 8));
			if (is_close_color(ref_color, *pixel, tolerance))
				*pixel = 0x00FF00;
			x++;
		}
		y++;
	}
}

char	*get_asset_path(int i, char *path, char *asset_name)
{
	char	*nb;
	char	*dir;
	char	*res;

	nb = ft_itoa(i);
	if (!nb)
		return (NULL);
	dir = ft_strjoin(path, nb);
	free(nb);
	if (!dir)
		return (NULL);
	res = ft_strjoin(dir, asset_name);
	free(dir);
	if (!res)
		return (NULL);
	return (res);
}