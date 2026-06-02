#include "../inc/cube_3d.h"

unsigned int	gett1(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

unsigned int	getr1(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

unsigned int	getg1(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

unsigned int	getb1(int trgb)
{
	return (trgb & 0xFF);
}

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(-n));
	return ((unsigned int)n);
}

double	ft_abs2(double n)
{
	if (n < 0)
		return ((-n));
	return (n);
}
