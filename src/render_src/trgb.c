/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:30:22 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/25 12:35:31 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

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
