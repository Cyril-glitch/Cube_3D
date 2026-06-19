#include "../../inc/cube_3d.h"


void	ft_red_filter(t_data *data, t_player *player, unsigned int *pixel)
{
	int	i;
	int	color;
	int	r;
	int	g;
	int	b;

	i = 0;
	if (!player->eated)
		return ;
	while (i < data->total_pixel)
	{
		color = pixel[i];
		r = getr1(color);
		g = getg1(color);
		b = getb1(color);
		g = (g * 3) / 4 ;
		b = (b * 3) / 4;
		r += 20;
		if (r > 255)
			r = 255;
		pixel[i] = (r << 16) | (g << 8) | b;
		i++;
	}
	player->eated = 0;
}

void	ft_green_filter(t_data *data, t_player *player, unsigned int *pixel)
{
	int	i;
	int	color;
	int	r;
	int	g;
	int	b;

	i = 0;
	if (!player->healed)
		return ;
	while (i < data->total_pixel)
	{
		color = pixel[i];
		r = getr1(color);
		g = getg1(color);
		b = getb1(color);
		r = (g * 3) / 4 ;
		b = (b * 3) / 4;
		g += 20;
		if (g > 255)
			g = 255;
		pixel[i] = (r << 16) | (g << 8) | b;
		i++;
	}
	player->healed = 0;
}

void	ft_render_ath(t_data *data)
{
	ft_draw_health(data);
}