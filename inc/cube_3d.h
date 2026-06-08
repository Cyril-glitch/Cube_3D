
#ifndef CUBE_3D_H
# define CUBE_3D_H

# include "../libft/inc/libft.h"
# include "../minilibx-linux/include/mlx.h"
# include "color.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

/* --- CONFIGURATION --- */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WIN_W 1024
# define WIN_H 768
# define TEX_W 64
# define TEX_H 64
# define WALL_PADDING 0.3
# define PI 3.14159265358979323846

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

/* --- STRUCTURES --- */

typedef struct timeval	t_timeval;

typedef struct s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct s_keys
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					left;
	int					right;
}						t_keys;

typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
	int					w;
	int					h;
}						t_img;

typedef struct s_sprite
{
	double	x;
	double	y;
	t_img	*texture;
}	t_sprite;


typedef struct s_player
{
	char				dir;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	int					move_up;
	int					move_down;
	int					move_left;
	int					move_right;
	int					rotate_left;
	int					rotate_right;
	double				move_speed;
	double				rot_speed;
}						t_player;

typedef struct s_ray
{
	double				camera_x;
	double				dir_x;
	double				dir_y;
	int					map_x;
	int					map_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					tex_num;
	int					tex_x;
	double				tex_pos;
	double				step;
}						t_ray;

typedef struct s_map
{
	char				**grid;
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	int					floor_color;
	int					ceiling_color;
	int					width;
	int					height;
}						t_map;

typedef struct s_mini_map
{
	t_img				image;
	t_img				arrow;
	t_img				rotation[64];
	int					exist;
	int					size;
	int					tile_size;
	int					radius;
	int					player_radius;
	int					center;
	t_point				map_tile;
	t_point				screen;
}						t_mini_map;

typedef struct s_data
{
	int					fd;
	char				*line;

	void				*mlx;
	void				*mlx_win;
	t_mini_map			mini_map;
	t_map				map;
	t_point				win_size;
	t_img				screen;
	t_img				*textures;
	t_sprite			*sprites;
	int					nb_sprites;

	t_player			player;
	t_ray				*ray;
	t_keys				keys;

	double				start;
	double				old_time;
	double				time;
	double				frame_time;
}						t_data;

// --- INITIALISATION ---

void					ft_init_data(t_data *data);
void					init_null(t_data *data);
void					init_player_dir(t_data *data);
void					init_keys(t_data *data);
int						init_mlx_and_ray(t_data *data);
int						init_screen(t_data *data);
int						init_textures(t_data *data);

// --- PARSING ---
void					ft_parser(t_data *data, t_map *map, char *file_path);
void					ft_parse_assets(t_data *data, t_map *map, char **line);
int						ft_parse_texture(t_data *data, t_map *map, char *line);
int						ft_parse_color(t_data *data, t_map *map, char *line);
void					ft_parse_map(t_data *data, t_map *map, char **line);

// --- PARSING UTILS ---
void					ft_assets_display(t_map *map);
void					ft_map_display(char **grid);
char					*ft_gnl(int fd);
char					*ft_gnl_no_nl(int fd);
int						ft_skip_isspace_line(char *line);
void					ft_skip_isspace(int start, char **line);
int						ft_open_file(t_data *data, char *file_path);
char					**ft_split_color(char *line);
int						ft_color_overflow(char *nbr);
int						ft_shift_color(char **tab);

// --- MAP CHECKER & UTILS ---
void					ft_extract_map(t_data *data, t_map *map, char **line);
void					ft_map_checker(t_data *data, t_player *player,
							char **grid);
int						ft_is_map_content(char c);
int						ft_is_walkable(char c);
int						ft_pit_fall(char c);
int						ft_is_offset(char **grid, int y, int x);
int						ft_is_limit_component(char **grid, int y, int x);
void					ft_init_player_pos(t_data *data, t_player *player, int y, int x);
int						ft_player_is_set(t_player *player);
int						ft_is_player(char c);
void					ft_display_map_error(char **grid, int err_y, int err_x);

// --- HOOKS & UPDATES ---
void					safe_cleanup(t_data *data);
void					init_hooks(t_data *data);
int						update(t_data *data);

// --- MOUVEMENTS ---
void					move_up(t_data *data);
void					move_down(t_data *data);
void					move_right(t_data *data);
void					move_left(t_data *data);

// --- GESTION DES PIXELS ET COULEURS ---
void					my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int			get_pixel(t_img *img, int x, int y);
int						is_close_color(int ref_color, int color);
int						is_transparent_color(int color);
void					put_img(t_img *dst, t_img *src, int pos_x, int pos_y);
void					put_tr(t_img *dst, t_img *src, int pos_x, int pos_y);
void					put_tr2(t_img *dst, t_img *src, int pos_x, int pos_y);
unsigned int			gett1(int trgb);
unsigned int			getr1(int trgb);
unsigned int			getg1(int trgb);
unsigned int			getb1(int trgb);

// --- RAYCASTING & RENDER ---
void					ft_raycaster(t_data *data, t_ray *ray);
void					ft_render_draw(t_ray *ray, t_data *data);

// --- MINIMAP ---
int						get_map_tile(t_data *data, int x, int y);
int						init_mini_map(t_data *data, t_mini_map *map);
void					draw_map_img(t_data *data, t_mini_map *map,
							t_player player);

// --- SPRITES ---
int						count_sprites(t_map *map, int type);
int						init_sprites_texture(t_data *data, int type);
void					init_sprites_pos(t_sprite *sprites, t_map *map, int type);
int						*sort_sprites(t_data *data, int count);
int						draw_sprites(t_data *data, t_player *player);

// --- UTILITAIRES ---
void					ft_display_logo(void);
void					ft_game_exit(t_data *data, char *error);
void					ft_free_data(t_data *data);
void					ft_error_file(char *file_path);
void					ft_error_log(char *error);
void					ft_free(char ***s);
double					get_time(double start);
unsigned int			ft_abs(int n);
double					ft_abs2(double n);

#endif