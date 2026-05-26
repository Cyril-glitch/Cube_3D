#include    "../inc/cube_3d.h"

int main()
{
    char **tab;
    int i = 0;

    tab = ft_split("255,545,12", ',');
    while (i < 3)
    {
        printf("%s\n", tab[i]);
        i++;
    }
}