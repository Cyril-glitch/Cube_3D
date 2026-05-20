#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;       
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_var
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_point	map_size;
	t_point	player_pos;
	t_point	win_size;
}	t_var;

char	**map_init(void);
void	ft_free(char ***s);
void	init_hooks(t_var *var);

// pixel management
void	        my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int    get_pixel(t_img *img, int x, int y);
int	            is_close_color(int color);
int	            is_transparent_color(int color);
void        	put_img(t_img *dst, t_img *src, int pos_x, int pos_y);
void        	put_tr(t_img *dst, t_img *src, int pos_x, int pos_y);
void        	put_tr2(t_img *dst, t_img *src, int pos_x, int pos_y);

unsigned int	gett1(int trgb);
unsigned int	getr1(int trgb);
unsigned int	getg1(int trgb);
unsigned int	getb1(int trgb);
unsigned int	ft_abs(int n);
double	ft_abs2(double n);

t_ray *ft_raycaster(t_var *var);
void    ft_render_draw(t_ray *ray, t_var *var);

#endif 
