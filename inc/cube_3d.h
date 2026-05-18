#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

/* --- CONFIGURATION --- */
# define WIN_W 1024
# define WIN_H 768
# define TEX_W 64
# define TEX_H 64

/* --- TOUCHES (MAC/LINUX) --- */
# ifdef __APPLE__
#  define K_W 13
#  define K_A 0
#  define K_S 1
#  define K_D 2
#  define K_ESC 53
#  define K_LEFT 123
#  define K_RIGHT 124
# else
#  define K_W 119
#  define K_A 97
#  define K_S 115
#  define K_D 100
#  define K_ESC 65307
#  define K_LEFT 65361
#  define K_RIGHT 65363
# endif

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

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
	int		side;       // 0 pour Nord/Sud, 1 pour Est/Ouest
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_map
{
	char	**grid;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_color;
	int		ceiling_color;
	int		width;
	int		height;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		image;     // L'image principale (le buffer)
	t_img		tex[4];     // Tes 4 textures de murs
	t_map		map;
	t_player	player;
	t_ray		ray;
}	t_data;

// Initialisation
int	ft_init_data(t_data *data);


// Parsing (Ton futur gros morceau)

// Engine (Raycasting & Rendu)

// Inputs

// Nettoyage

#endif