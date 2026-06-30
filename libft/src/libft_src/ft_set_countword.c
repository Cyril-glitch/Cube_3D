/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_countword.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:34:40 by cycolonn          #+#    #+#             */
/*   Updated: 2026/06/30 12:39:29 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_set_countword(char const *s, char *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (ft_isset(s[i], set))
			i++;
		if (s[i])
			count++;
		while (s[i] && !ft_isset(s[i], set))
			i++;
	}
	return (count);
}
