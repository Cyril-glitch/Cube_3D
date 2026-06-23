/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:27:28 by cyril             #+#    #+#             */
/*   Updated: 2026/06/23 17:38:14 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube_3d.h"

char	*ft_gnl(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char		*ret;
	char		*tmp;
	int			read_ret;

	ret = NULL;
	tmp = NULL;
	read_ret = 1;
	while (!tmp && read_ret)
	{
		if (!ft_str_append_str(&ret, b))
			return (NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (free(ret), NULL);
		b[read_ret] = 0;
		tmp = ft_strchr(b, '\n');
	}
	if ((!b[0] && (!ret || !ret[0])) || (tmp && !ft_str_append_mem(&ret, b, tmp
				- b + 1)))
		return (free(ret), NULL);
	if (!tmp)
		return (ret);
	return (ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1), ret);
}
