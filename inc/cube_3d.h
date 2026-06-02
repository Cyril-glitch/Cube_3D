#ifndef CUBE_3D_H
# define CUBE_3D_H

# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include "color.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

/* --- CONFIGURATION --- */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			rotate_left;
	int			rotate_right;
}				t_player;

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_map
{
	char		**grid;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			floor_color;
	int			ceiling_color;
	int			width;
	int			height;
}				t_map;

typedef struct s_data
{
	int			fd;
	char		*line;
	void		*mlx;
	void		*win;
	t_img		image;
	t_img		tex[4];
	t_map		map;
	t_player	player;
	t_ray		ray;
}				t_data;

// Initialisation
void			ft_init_data(t_data *data);

// Parsing
void			ft_parser(t_data *data, t_map *map, char *file_path);

// Parsing utils
void			ft_assets_display(t_map *map);
void			ft_map_display(char **grid);

// Parsing assets
void			ft_parse_assets(t_data *data, t_map *map, char **line);
char			*ft_gnl(int fd);
char			*ft_gnl_no_nl(int fd);

// parsing assets utils
int				ft_skip_isspace_line(char *line);
void			ft_skip_isspace(int start, char **line);
int				ft_open_file(t_data *data, char *file_path);

// parse texture
int				ft_parse_texture(t_data *data, t_map *map, char *line);

// parse color
int				ft_parse_color(t_data *data, t_map *map, char *line);

// parse color utils
char			**ft_split_color(char *line);
int				ft_color_overflow(char *nbr);
int				ft_shift_color(char **tab);

// parsing map
void			ft_parse_map(t_data *data, t_map *map, char **line);

// map checker
void			ft_map_checker(t_data *data, t_player *player, char **grid);

// map checker utils
int				ft_is_map_content(char c);
int				ft_is_walkable(char c);
int				ft_pit_fall(char c);
int				ft_is_offset(char **grid, int y, int x);
int				ft_is_limit_component(char **grid, int y, int x);
int				ft_is_player(char c);
void			ft_display_logo(void);
void			ft_init_player_pos(t_player *player, int y, int x);
int				ft_check_player(t_player *player);
int				ft_is_player(char c);
void 			ft_display_map_error(char **grid, int err_y, int err_x);

// Render

// Inputs

// Nettoyage
void			ft_game_exit(t_data *data, char *error);
void			ft_free_data(t_data *data);
void			ft_error_file(char *file_path);
void			ft_error_log(char *error);

#endif