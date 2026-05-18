#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

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

int raycasting(t_var *var);

#endif 
