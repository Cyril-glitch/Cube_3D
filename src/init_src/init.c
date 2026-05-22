#include    "../inc/cube_3d.h"
 
void    ft_init_data(t_data *data)
{
        ft_bzero(data, sizeof(*data));
        if (!data)
                ft_game_exit(data, "memory allocation failed.\n");        
}