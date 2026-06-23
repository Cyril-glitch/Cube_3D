/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:25:42 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 16:32:55 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

void	ft_parse_map(t_data *data, t_map *map, char **line)
{
	ft_extract_map(data, map, line);
	ft_map_checker(data, &data->player, data->map.grid);
	ft_map_display(map->grid);
	printf("\n");
}
