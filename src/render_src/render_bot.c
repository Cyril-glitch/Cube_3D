#include "../../inc/cube_3d.h"
#include "../../inc/cube_3d.h"

// 1. Adaptation du calcul de projection pour viser le Bot
static void	compute_bot_transformation(t_data *data, t_player *player, t_sprite_type *sprite)
{
	// On lit directement ton instance indépendante !
	sprite->x = data->monster.sprite.x - player->pos_x;
	sprite->y = data->monster.sprite.y - player->pos_y;
	sprite->inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y);
	sprite->transform_x = sprite->inv_det * (player->dir_y * sprite->x - player->dir_x * sprite->y);
	sprite->transform_y = sprite->inv_det * (-player->plane_y * sprite->x + player->plane_x * sprite->y);
}

// 2. Adaptation du dessin pour lire la texture de ton Bot
static void	render_bot_pixels(t_data *data, t_sprite_type *sprite)
{
	int	x;
	int	y;

	x = sprite->draw_start_x;
	while (x < sprite->draw_end_x)
	{
		int	tex_x = (int)(256 * (x - (- sprite->w / 2 + sprite->screen_x)) * data->monster.sprite.texture->w / sprite->w) / 256;
		if (sprite->transform_y > 0 && x > 0 && x < data->screen.w && sprite->transform_y < data->ray[x].perp_wall_dist)
		{
			y = sprite->draw_start_y;
			while (y < sprite->draw_end_y)
			{
				int d = y * 256 - data->screen.h * 128 + sprite->h * 128;
				int	tex_y = (d * data->monster.sprite.texture->h / sprite->h) / 256;
				
				if (tex_x < data->monster.sprite.texture->w && tex_x >= 0
					&& tex_y < data->monster.sprite.texture->h && tex_y >= 0)
				{
					sprite->color = get_pixel(data->monster.sprite.texture, tex_x, tex_y);
					if (sprite->color != 0x00FF00)
						my_mlx_pixel_put(&data->screen, x, y, sprite->color);
				}
				y++;
			}
		}
		x++;
	}
}

// 3. Ta fonction principale
void	ft_draw_bot(t_data *data, t_player *player)
{
	t_sprite_type	bot_render;

	data->monster.sprite.x = data->monster.pos_x;
	data->monster.sprite.y = data->monster.pos_y;
	compute_bot_transformation(data, player, &bot_render);

	if (bot_render.transform_y <= 0)
		return ;

	compute_sprite_bounds(data, &bot_render); //
	render_bot_pixels(data, &bot_render);
}