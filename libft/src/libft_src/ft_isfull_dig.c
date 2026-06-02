#include "libft.h"

int ft_isfull_dig(char *s)
{
    while (*s)
    {
        if (!ft_isdigit(*(s++)))
            return (0);
    }
    return (1);
}