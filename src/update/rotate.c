#include "../../inc/cube_3d.h"

void	ft_rot_left(t_data *data)
{
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &data->player;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-player->rot_speed) - player->dir_y
		* sin(-player->rot_speed);
	player->dir_y = old_dir_x * sin(-player->rot_speed) + player->dir_y
		* cos(-player->rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-player->rot_speed)
		- player->plane_y * sin(-player->rot_speed);
	player->plane_y = old_plane_x * sin(-player->rot_speed) + player->plane_y
		* cos(-player->rot_speed);
}

void	ft_rot_right(t_data *data)
{
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &data->player;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(player->rot_speed) - player->dir_y
		* sin(player->rot_speed);
	player->dir_y = old_dir_x * sin(player->rot_speed) + player->dir_y
		* cos(player->rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(player->rot_speed) - player->plane_y
		* sin(player->rot_speed);
	player->plane_y = old_plane_x * sin(player->rot_speed) + player->plane_y
		* cos(player->rot_speed);
}

static void	ft_rotate(t_data *data, double rotation)
{
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &data->player;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotation) - player->dir_y * sin(rotation);
	player->dir_y = old_dir_x * sin(rotation) + player->dir_y * cos(rotation);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotation) - player->plane_y
		* sin(rotation);
	player->plane_y = old_plane_x * sin(rotation) + player->plane_y * cos(rotation);
}

/*
int ft_mouse_rot(int mouse_x, int mouse_y, t_data *data)
{
    double  delta_x;
    double  angle_rotation;

    (void)mouse_y;
    if (mouse_x == WIN_W / 2)
        return (0);
    delta_x = mouse_x - (WIN_W / 2);
    angle_rotation = -delta_x * SENS;
    ft_rotate(data, angle_rotation);
    mlx_mouse_move(data->mlx, data->mlx_win, WIN_W / 2, WIN_H / 2);
    return (0);
}
*/

int ft_mouse_rot(int mouse_x, int mouse_y, t_data *data)
{
    double  delta_x;
    double  angle_rotation;
    (void)mouse_y; 
    int center_x = data->win_size.x / 2;
    int center_y = data->win_size.y / 2;

    if (mouse_x == center_x)
        return (0); 
    delta_x = mouse_x - center_x; 
    angle_rotation = delta_x * SENS;  
    ft_rotate(data, angle_rotation); 
    mlx_mouse_move(data->mlx, data->mlx_win, center_x, center_y);
    return (0);
}