#include "../../inc/cube_3d.h"

char *ft_gnl(int fd)
{
  static char b[BUFFER_SIZE + 1] = "";
  char *ret = NULL;
  char *tmp = NULL;
  int	read_ret = 1;
  while(((tmp = ft_strchr(b, '\n')) == NULL) && read_ret)
  {
    if (!ft_str_append_str(&ret, b))
      return (NULL);
    read_ret = read(fd, b, BUFFER_SIZE);
    if (read_ret == -1)
      return (NULL);
    b[read_ret] = 0;
  }
  if (!b[0])
  	return (free(ret), NULL);
  if (!ft_str_append_mem(&ret, b, tmp - b + 1))
  {
    free(ret);
    return NULL;
  }
  ft_memmove(b, tmp + 1, ft_strlen(b));
  return ret;
}
