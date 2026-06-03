#include "../../inc/cube_3d.h"

void	ft_error_log(char *error)
{
	if (!error)
		return ;
	ft_putstr_fd(B_L_RED "Error: ", 2);
	ft_putstr_fd(error , 2);
	ft_putstr_fd("\n" RESET , 2);
}

void	ft_error_file(char *file_path)
{
	if (!file_path)
		return ;
	ft_putstr_fd(B_L_RED "Error: cannot open ", 2);
	ft_putstr_fd(file_path , 2);
	ft_putstr_fd("\n" RESET , 2);


}

void	ft_game_exit(t_data *data, char *error)
{
	if (error)
		ft_error_log(error);
	ft_free_data(data);
	exit(1);
}