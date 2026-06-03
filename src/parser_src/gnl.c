#include "../../inc/cube_3d.h"

char	*ft_gnl(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char		*ret = NULL;
	char		*tmp = NULL;
	int			r = 1;

	while (((tmp = ft_strchr(b, '\n')) == NULL) && r)
	{
		if (!ft_str_append_str(&ret, b))
			return (NULL);
		r = read(fd, b, BUFFER_SIZE);
		if (r == -1)
			return (NULL);
		b[r] = 0;
	}
	if (!tmp)
	{
		if (ret && !ret[0])
			return (free(ret), NULL);
		return (ret);
	}
	if (!ft_str_append_mem(&ret, b, tmp - b + 1))
		return (free(ret), NULL);
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	return (ret);
} 