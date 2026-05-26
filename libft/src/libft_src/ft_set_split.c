/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:08:41 by cycolonn          #+#    #+#             */
/*   Updated: 2026/03/13 12:32:11 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_load(char **tab, char const *s, char *set, int index)
{
	size_t	len;

	len = 0;
	while (*s && ft_isset(*s, set))
		s++;
	if (!*s)
	{
		tab[index] = NULL;
		return (1);
	}
	while (s[len] && !ft_isset(*s, set))
		len++;
	tab[index] = malloc(sizeof(char) * (len + 1));
	if (!tab[index])
		return (0);
	ft_memcpy(tab[index], s, len);
	if (ft_load(tab, s + len, set, index + 1))
		return (1);
	free(tab[index]);
	return (0);
}

char	**ft_set_split(char const *s, char *set)
{
	char	**tab;
	int		len;

	if (!s)
		return (NULL);
	len = ft_set_countword(s, set);
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	if (ft_load(tab, s, set, 0) == 0)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}