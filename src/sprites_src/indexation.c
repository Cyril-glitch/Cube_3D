/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichaud <nmichaud@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:22:27 by nmichaud          #+#    #+#             */
/*   Updated: 2026/06/04 14:22:28 by nmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

static int	*copy_tab(int *tab, int size)
{
	int	i;
	int	*res;

	res = malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = tab[i];
		i++;
	}
	return (res);
}

static int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (is_sorted(tab, size) == 1)
		return ;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] < tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	indexation(int *a, int size)
{
	int	*tab;
	int	*idx;
	int	i;
	int	j;

	tab = copy_tab(a, size);
	if (!tab)
		return (0);
	idx = malloc(sizeof(int) * size);
	if (!idx)
		return (0);
	sort_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (a[i] != tab[j])
			j++;
		idx[i] = j;
		i++;
	}
	i = 0;
	while (i < size)
	{
		a[i] = idx[i];
		i++;
	}
	free(tab);
	free(idx);
	return (1);
}
