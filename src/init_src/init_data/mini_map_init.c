/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:49:10 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 12:30:10 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

static void	rotate_sprite_pixel(t_rotation rotation, t_img *dest, t_img arrow)
{
	int	color;

	rotation.d.x = rotation.dst.x - rotation.center;
	rotation.d.y = rotation.dst.y - rotation.center;
	rotation.src.x = rotation.d.x * rotation.cos_a + rotation.d.y
		* rotation.sin_a;
	rotation.src.y = -rotation.d.x * rotation.sin_a + rotation.d.y
		* rotation.cos_a;
	rotation.src.x += rotation.center;
	rotation.src.y += rotation.center;
	if (rotation.src.x >= 0 && rotation.src.x < arrow.w && rotation.src.y >= 0
		&& rotation.src.y < arrow.h)
	{
		color = get_pixel(&arrow, rotation.src.x, rotation.src.y);
		my_mlx_pixel_put(dest, rotation.dst.x, rotation.dst.y, color);
	}
}

void	fill_rotated_sprite(t_img *dest, t_img arrow, double angle)
{
	t_rotation	rotation;

	rotation.center = arrow.w / 2;
	rotation.cos_a = cos(angle);
	rotation.sin_a = sin(angle);
	rotation.dst.y = 0;
	while (rotation.dst.y < dest->h)
	{
		rotation.dst.x = 0;
		while (rotation.dst.x < dest->w)
		{
			rotate_sprite_pixel(rotation, dest, arrow);
			rotation.dst.x++;
		}
		rotation.dst.y++;
	}
}
