#include "../inc/libft.h"

int ft_str_append_str(char **s1, char *s2)
{
  return ft_str_append_mem(s1, s2, ft_strlen(s2));
}