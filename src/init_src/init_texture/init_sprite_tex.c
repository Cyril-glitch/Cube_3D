/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:02:17 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 15:36:04 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

void	init_sprites_textures(t_data *data)
{
	init_treasure_textures(data);
	init_monster_textures(data);
	init_pack_textures(data);
}
