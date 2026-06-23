/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:40:18 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/23 12:21:06 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube_3d.h"

void	init_global(t_data *data, char **av)
{
	init_null(data);
	ft_parser(data, &data->map, av[1]);
	init_map_size(data, data->map.grid);
	data->start = get_time(0);
	data->time = data->start;
	init_mlx_and_ray(data);
	init_screen(data);
	init_wall_tex(data);
	init_player_dir(data);
	init_keys(data);
	init_hooks(data);
}
