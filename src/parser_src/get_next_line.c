#include "../inc/cube_3d.h"

static int str_append_mem(char **s1, char *s2, size_t size2)
{
  size_t size1 = ft_strlen(*s1);
  char *tmp = malloc(size2 + size1 + 1);
  if (!tmp)
    return 0;
  ft_memcpy(tmp, *s1, size1);
  ft_memcpy(tmp + size1, s2, size2);
  tmp[size1 + size2] = '\0';
  free(*s1);
  *s1 = tmp;
  return 1; 
}

static int str_append_str(char **s1, char *s2)
{
  return str_append_mem(s1, s2, ft_strlen(s2));
}


char *get_next_line(int fd)
{
  static char b[BUFFER_SIZE + 1] = "";
  char *ret = NULL;
  char *tmp = NULL;
  int	read_ret = 1;
  while(((tmp = ft_strchr(b, '\n')) == NULL) && read_ret)
  {
    if (!str_append_str(&ret, b))
      return (NULL);
    read_ret = read(fd, b, BUFFER_SIZE);
    if (read_ret == -1)
      return (NULL);
    b[read_ret] = 0;
  }
  if (!b[0])
  	return (free(ret), NULL);
  if (!str_append_mem(&ret, b, tmp - b + 1))
  {
    free(ret);
    return NULL;
  }
  ft_memmove(b, tmp + 1, ft_strlen(b));
  return ret;
}

/*
int	main()
{
	int fd = 0;
	char *line;

	if ((fd = open("./test.txt", O_RDONLY)) == -1)
	{
		return 1;
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
}
*/
