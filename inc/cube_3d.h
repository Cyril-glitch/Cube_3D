/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:35:37 by cyril             #+#    #+#             */
/*   Updated: 2026/06/22 16:23:27 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define CUBE_3D_H

# include "../libft/inc/libft.h"
# include "../minilibx-linux/include/mlx.h"
# include "colors.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

/* --- CONFIGURATION --- */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WIN_W 1080
# define WIN_H 600
# define TEX_W 64
# define TEX_H 64
# define WALL_PADDING 0.3
# define INTERACT_DIST 1
# define PI 3.14159265358979323846
# define SENS 0.0005

# define MAP_H
# define MAP_W

# define CAP 16.6666666666666666666

# define DOOR_TEXT 4
# define SPRITE_M_TEXT_NB 63
# define SPRITE_P_TEXT_NB 1
# define SPRITE_T_TEXT_NB 8

# define HOR_DOOR 'H'
# define VER_DOOR 'V'
# define SPRITE_M 'M'
# define SPRITE_P 'P'
# define SPRITE_T 'T'

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
#  define K_R 114
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

typedef struct s_bfs
{
	int					max_h;
	int					max_w;
	int					count;
	int					waiters;
	t_point				start;
	t_point				target;
	t_point				*queue;
	t_point				*came_from;
}						t_bfs;

typedef struct s_keys
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					e;
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
	int					half_w;
	int					half_h;
}						t_img;

typedef struct s_sprite
{
	double				x;
	double				y;
	t_img				*textures;
	int					current_frame;
	int					number;
	int					type;
	bool				consumed;
}						t_sprite;

typedef struct s_sprite_order
{
	int					index;
	int					type;
	double				dist;
}						t_sprite_order;

typedef struct s_door
{
	int					tile_x;
	int					tile_y;
	float				open;
	bool				vertical;
	bool				opening;
	bool				closing;
}						t_door;

typedef struct s_sprite_type
{
	t_sprite			*sprites;
	int					sprite_id;
	int					type;
	int					color;
	double				x;
	double				y;
	double				inv_det;
	double				transform_x;
	double				transform_y;
	double				inv_transform_y;
	int					screen_x;
	int					w;
	int					h;
	double				inv_w;
	double				inv_h;
	int					half_w;
	int					half_h;
	int					draw_start_y;
	int					draw_start_x;
	int					draw_end_y;
	int					draw_end_x;
	int					current_frame;
	int					tex_x;
	int					tex_y;
}						t_sprite_type;

typedef struct s_hp
{
	int					pos_y;
	int					pos_x;
	int					h;
	int					w;
	int					color;
	int					thickness;
	int					health;
	double				last_hit;
}						t_hp;

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
	int					eated;
	int					healed;
	int					scored;
	t_point				next_step;
	t_sprite			*sprite;
	t_bfs				bfs;
	t_hp				hp;
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
	int					half_h;
	int					hit;
	t_door				*door;
	double				door_dist;
}						t_ray;

typedef struct s_rotation
{
	int		center;
	double	cos_a;
	double	sin_a;
	t_point	dst;
	t_point	src;
	t_point	d;
}			t_rotation;



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

typedef struct s_backgrd
{
	double				*dist;
	double				dir_x_left;
	double				dir_y_left;
	double				dir_x_right;
	double				dir_y_right;
	double				pos_x_left;
	double				pos_y_left;
	double				pos_x_right;
	double				pos_y_right;
	double				row_dist;
	int					tex_x;
	int					tex_y;
	t_img				floor;
	t_img				ceiling;
}						t_backgrd;

typedef struct s_data
{
	int					fd;
	char				*line;

	void				*mlx;
	void				*mlx_win;
	int					total_pixel;
	t_map				map;
	t_mini_map			mini_map;
	t_point				win_size;
	t_img				screen;
	t_img				over;
	t_img				congrats;
	t_img				*textures;
	t_img				*m_textures;
	t_img				*t_textures;
	t_img				*p_textures;
	t_sprite			*m_sprites;
	t_sprite			*t_sprites;
	t_sprite			*p_sprites;
	t_sprite			*sprites;
	t_door				*doors;
	int					nb_doors;
	t_backgrd			bgrd;

	t_player			player;
	t_player			*monsters;
	int					(*offsets)[2];
	t_ray				*ray;
	t_keys				keys;

	double				start;
	double				old_time;
	double				time;
	double				frame_time;
	double				last_frame;
}						t_data;

// --- INITIALISATION ---

void					ft_init_data(t_data *data);
void					init_null(t_data *data);
void					init_player_dir(t_data *data);
void					init_keys(t_data *data);
void					init_mlx_and_ray(t_data *data);
void					init_screen(t_data *data);
void					init_wall_tex(t_data *data);
int						init_arrow(t_data *data, t_mini_map *map);
void					init_sprites_textures(t_data *data);
void					ft_init_backgrd(t_data *data, t_backgrd *bgrd);
void					ft_init_sprites(t_data *data);
void					ft_init_global_sprites_tab(t_data *data);
void					init_monsters(t_data *data);
void					init_offsets(t_data *data);
void					init_global(t_data *data, char **av);
void					ft_init_bfs(t_data *data, t_player *monsters);
void					ft_init_stats(t_data *data, t_hp *hp);
void					ft_init_game_over(t_data *data, t_img *over);
void					ft_init_congrats(t_data *data, t_img *congrats);
void					init_map_size(t_data *data, char **grid);
void					init_monster_textures(t_data *data);
void					init_treasure_textures(t_data *data);
void					init_monster_textures(t_data *data);
void					init_pack_textures(t_data *data);
char					*get_asset_path(int i, char *path, char *asset_name);
void					fill_rotated_sprite(t_img *dest, t_img arrow, double angle);
void					treat_transparency(t_img *image, int ref_color, unsigned int tolerance);


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
void					ft_init_player_pos(t_data *data, t_player *player,
							int y, int x);
int						ft_player_is_set(t_player *player);
int						ft_is_player(char c);
void					ft_display_map_error(char **grid, int err_y, int err_x);

// --- GAME_LOOP ---
int						ft_game_loop(t_data *data);

// --- HOOKS & UPDATES ---
void					safe_cleanup(t_data *data);
void					init_hooks(t_data *data);
int						ft_mouse_rot(int mouse_x, int mouse_y, t_data *data);
t_point					ft_bfs(t_data *data, t_bfs *bfs, t_point start,
							t_point target);
void					ft_init_camefrom(t_bfs *bfs);
void					ft_init_research(t_point start, t_point target,
							t_bfs *bfs);
void					ft_get_target_path(t_data *data, t_bfs *bfs,
							t_point *cur);
t_point					ft_get_next_step(t_bfs *bfs, t_point start,
							t_point target);
void					ft_update_monster_path(t_data *data, t_player *monster,
							int i);
int						ft_monster_arrived(t_player *monster);
void					ft_bot_move(t_data *data, int i);
void					ft_player_win(t_player *player, t_sprite *treasure,
							int trs_index);
void					ft_player_stats(t_data *data);
int						ft_get_index(t_point p, t_bfs bfs);
void					update(t_data *data);
void					ft_damage(t_data *data, t_player *player,
							t_player *monsters, int nb_monsters);
void					ft_healing(t_player *player, t_sprite *hpack,
							int nb_pack);
double					get_time(double start);

// --- MOUVEMENTS ---
void					move_up(t_data *data);
void					move_down(t_data *data);
void					move_left(t_data *data);
void					move_right(t_data *data);
void					close_or_open_door(t_data *data);
void					ft_rot_left(t_data *data);
void					ft_rot_right(t_data *data);

// --- GESTION DES PIXELS ET COULEURS ---
void					my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int			get_pixel(t_img *img, int x, int y);
int						is_close_color(int ref_color, int color,
							unsigned int tolerance);
int						choose_color(int n);
int						ft_set_color(t_ray ray, char **map);
int						is_transparent_color(int color);
void					put_img(t_img *dst, t_img *src, int pos_x, int pos_y);
void					put_tr(t_img *dst, t_img *src, int pos_x, int pos_y);
void					put_tr2(t_img *dst, t_img *src, int pos_x, int pos_y);
unsigned int			gett1(int trgb);
unsigned int			getr1(int trgb);
unsigned int			getg1(int trgb);
unsigned int			getb1(int trgb);
int						ft_anti_aliasing(int color);
void					ft_green_filter(t_data *data, t_player *player,
							unsigned int *pixel);
void					ft_red_filter(t_data *data, t_player *player,
							unsigned int *pixel);

// --- RAYCASTING & RENDER ---
void					ft_raycaster(t_data *data, t_ray *ray);
void					ft_render_draw(t_ray *ray, t_data *data);
void					ft_render_fc(t_data *data, t_backgrd *flr, t_img *floor,
							t_img *cieling);
void					ft_render_ath(t_data *data);
void					ft_draw_bot(t_data *data, t_player *player);
void					ft_draw_health(t_data *data);
void					ft_display_fps(t_data *data);
void					ft_render_death(t_data *data, t_img over);
void					ft_render_win(t_data *data, t_img over);

// --- MINIMAP ---
int						get_map_tile(char **grid, int h, int x, int y);
void					init_mini_map(t_data *data, t_mini_map *map);
void					draw_map_img(t_data *data, t_mini_map *map,
							t_player player);

// --- SPRITES ---
int						count_sprites(t_map *map, int type);
void					ft_assign_sprites_textures(t_data *data, int type);
void					init_sprites_pos(t_sprite *sprites, t_map *map,
							int type);
t_sprite_order			*sort_sprites(t_data *data, int count);
int						draw_sprites(t_data *data, t_player *player);

// --- DOORS ---
t_door					*get_door(char **grid, t_door *door, int x, int y);
int						ft_count_doors(char **grid);
void					init_doors(t_data *data, char **grid);
void					compute_sprite_transformation(t_player *player,
							t_sprite_type *sprite);
void					compute_sprite_bounds(t_img *screen,
							t_sprite_type *sprite);
void					render_sprite(t_data *data, t_img *screen, double start,
							t_sprite_type *sprite);

// --- UTILITAIRES ---
void					ft_display_logo(void);
void					ft_game_exit(t_data *data, char *error);
void 					ft_free_texture(t_data *data);
void					ft_free_data(t_data *data);
void					ft_error_file(char *file_path);
void					ft_error_log(char *error);
double					get_time(double start);
unsigned int			ft_abs(int n);
double					ft_abs2(double n);

#endif