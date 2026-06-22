/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:17:30 by cyril             #+#    #+#             */
/*   Updated: 2026/06/22 15:05:15 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	init_global(t_data *data, char **av)
{
	ft_init_data(data);
	init_null(data);
	ft_parser(data, &data->map, av[1]);
	init_map_size(data, data->map.grid);
	data->start = get_time(0);
	data->time = data->start;
	init_mlx_and_ray(data);
	init_screen(data);
	init_wall_tex(data);
	init_sprites_textures(data);
	ft_init_backgrd(data, &data->bgrd);
	ft_init_global_sprites_tab(data);
	ft_init_stats(data, &data->player.hp);
	ft_init_game_over(data, &data->over);
	ft_init_congrats(data, &data->congrats);
	init_offsets(data);
	init_mini_map(data, &data->mini_map);
	init_doors(data, data->map.grid);
	ft_init_bfs(data, data->monsters);
	init_keys(data);
	init_hooks(data);
}
