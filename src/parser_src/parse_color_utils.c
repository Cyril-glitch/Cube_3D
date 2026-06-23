/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:25:06 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 16:25:35 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

int	ft_color_overflow(char *nbr)
{
	int	n;

	n = ft_atoi(nbr);
	return (n < 0 || n > 255);
}

char	**ft_split_color(char *line)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab || ft_tablen(tab) != 3)
	{
		if (tab)
			ft_freedtab(tab);
		return (NULL);
	}
	return (tab);
}

int	ft_shift_color(char **tab)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(tab[0]);
	g = ft_atoi(tab[1]);
	b = ft_atoi(tab[2]);
	return (r << 16 | g << 8 | b);
}
