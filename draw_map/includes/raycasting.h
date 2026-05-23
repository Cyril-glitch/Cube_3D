#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <sys/time.h>
# include <math.h>
# include <X11/keysym.h>

# define WALL_PADDING 0.2
# define PI 3.14159265358979323846

typedef struct timeval	t_timeval;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
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
	int		tex_num;
	int		tex_x;
	double	tex_pos;
	double	step;
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

typedef struct s_map
{
	t_img	image;
	t_img	arrow;
	t_img	rotation[64];
	int		exist;
	int		size;
	int		tile_size;
	int		radius;
	int		player_radius;
	int		center;
	t_point	map_tile;
	t_point	screen;
}	t_map;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_var
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		map_width;
	int		map_height;
	t_map	mini_map;
	t_img	screen;
	t_img	*textures;
	t_point	map_size;
	t_point	player_pos;
	t_point	win_size;
	double	start;
	double	old_time;
	double	time;
	double	frame_time;
	t_keys		keys;
	t_player	player;
	t_ray		*ray;
}	t_var;

// map_builder
char	**map_init(void);

// utils
void	ft_free(char ***s);
double	get_time(double start);

// init
void	init_null(t_var *var);
void	init_player_pos(t_var *var);
void	init_keys(t_var *var);
int		init_mlx_and_ray(t_var *var);
int		init_screen(t_var *var);
int		init_textures(t_var *var);

// hooks
void	safe_cleanup(t_var *var);
void	init_hooks(t_var *var);

// pixel management
void	        my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int    get_pixel(t_img *img, int x, int y);
int	            is_close_color(int ref_color, int color);
int	            is_transparent_color(int color);
void        	put_img(t_img *dst, t_img *src, int pos_x, int pos_y);
void        	put_tr(t_img *dst, t_img *src, int pos_x, int pos_y);
void        	put_tr2(t_img *dst, t_img *src, int pos_x, int pos_y);

// trgb
unsigned int	gett1(int trgb);
unsigned int	getr1(int trgb);
unsigned int	getg1(int trgb);
unsigned int	getb1(int trgb);
unsigned int	ft_abs(int n);
double	ft_abs2(double n);

// raycasting
void	ft_raycaster(t_var *var, t_ray *ray);

// render draw
void    ft_render_draw(t_ray *ray, t_var *var);

// draw_map
int		get_map_tile(t_var *var, int x, int y);
int		init_mini_map(t_var *var, t_map *map);
void	draw_map_img(t_var *var, t_map *map, t_player player);

// move
void	move_up(t_var *var);
void	move_down(t_var *var);
void	move_right(t_var *var);
void	move_left(t_var *var);

// update
int	update(t_var *var);

#endif 
