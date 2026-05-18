#include "raycasting.h"

int	choose_color(int n)
{
	if (n == 1)
		return (0xf54242);
	if (n == 2)
		return (0x5df542);
	if (n == 3)
		return (0x4542f5);
	if (n == 4)
		return (0xf542d7);
	if (n == 5)
		return (0xf5d142);
	return (0x0d0d0d);
}

int raycasting(t_var *var)
{
	double	posX = 22;
	double	posY = 12;
	int		mapX;
	int		mapY;
	double	dirX = -1;
	double	dirY = 0;
	double	planeX = 0;
	double	planeY = 0.66;
	//double	time = 0;
	//double	oldTime = 0;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;

	int		hit;
	int		side;

	int		lineHeight;
	int		drawStart;
	int		drawEnd;

	int	x = 0;
	int	w = 640;
	while (x < w)
	{
		cameraX = 2 * x / (double)w - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;

		mapX = (int)posX;
		mapY = (int)posY;

		if (rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = ft_abs2(1 / rayDirX);
		if (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = ft_abs2(1 / rayDirY);

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		hit = 0;
		while (!hit)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (var->map[mapY][mapX] - 48 > 0)
				hit = 1;
		}
		printf("%d\n", var->map[16][1] - 48);
		if (side == 0)
			perpWallDist = sideDistX - deltaDistX;
		else if (side == 1)
			perpWallDist = sideDistY - deltaDistY;

		lineHeight = (int)(480 / perpWallDist);
		drawStart = -lineHeight / 2 + 480 / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + 480 / 2;
		if (drawEnd >= 480)
			drawEnd = 480 - 1;

		int	i = drawStart;
		int	color = choose_color(var->map[mapY][mapX] - 48);
		if (side == 1)
			color = color / 2;
		while (i < drawEnd)
		{
			mlx_pixel_put(var->mlx, var->mlx_win, x, i, color);
			i++;
		}
		x++;
	}
	return (0);
}
