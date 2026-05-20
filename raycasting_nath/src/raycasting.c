#include "raycasting.h"

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

t_ray	*ft_init_ray_tab(int win_w)
{
	int	i;
	t_ray *ray;

	i = 0;
	ray = malloc(sizeof(t_ray) * win_w);
	if (!ray)
		return NULL;
	while(i > win_w)
	{
		ft_bzero(&ray[i], sizeof(ray[i]));
		i++;
	}
	return ray;
}

void    ft_get_player_vectors(t_player *player)
{
    //on commence par definir la position du joueur
    //c'est notre vecteur de position , le point de depart pour tracer notre vecteur de direction 
    player->pos_x = 22; 
    player->pos_y = 12;

    //on a donc la position de depart du vecteur 
    //on defini maintenant la direction de ce vecteur dans notre cas le joueur regarde a l'est 
    player->dir_x = -1;
    player->dir_y = 0; 
 
    //enfin on defini la direction et la largeur du plan 
    player->plane_x = 0;
    player->plane_y = 0.66;
	//le vecteur de position sera de plane sera l'extremite du vecteur de direction du player soit pos + dir 
}

void	ft_get_ray_dir(t_player player, t_ray *ray, int x, int w)
{
	//determine le bords de l'ecran sur une echelle -1 a 1;
	ray->camera_x = 2 * x / (double)w - 1; 

	//determine la direction que doit prendre un rayon partant de du player pour atteindre camerax
	ray->dir_x = player.dir_x + player.plane_x * ray->camera_x;
	ray->dir_y = player.dir_y + player.plane_y * ray->camera_x;
}

void	ft_get_map_pos(t_ray *ray, t_player player)
{
	ray->map_x = (int)player.pos_x;
	ray->map_y = (int)player.pos_y;
}

void	ft_get_delta(t_ray *ray)
{
	if (ray->dir_x == 0)  //la direction du rayon suit une ligne horizontal delta x est infini
		ray->delta_dist_x = 1e30;
	else 
		ray->delta_dist_x = ft_abs2(1 / ray->dir_x);

	if (ray->dir_y == 0)  //la direction du rayon suit une ligne verticale delta x est infini
		ray->delta_dist_y = 1e30;
	else 
		ray->delta_dist_y = ft_abs2(1 / ray->dir_y);
}

void	ft_get_sidedist(t_ray *ray , t_player player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player.pos_x - ray->map_x) * ray->delta_dist_x; 
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player.pos_x) * ray->delta_dist_x; 
	}

	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player.pos_y - ray->map_y) * ray->delta_dist_y; 
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player.pos_y) * ray->delta_dist_y; 
	}
}

void	ft_init_dda(t_ray *ray, t_player player)
{
	//on determine ou se trouve le joueur dans la grille
	ft_get_map_pos(ray, player);
	//on determine dans quel case se trouve le joueur
	//on determine la distance a parcourir pour traverser une case
	ft_get_delta(ray);

	//on determine la distance qui nous separe du 1er axe x et y 
	//on determine dans quel direction on doit aller pour atteindre cette axe
	ft_get_sidedist(ray, player);
}

void	ft_perform_dda(t_ray *ray, char **map)
{
	int hit;	

	hit = 0;
	while (hit == 0)
	{
		//si l'axe le plus proche est horizontal
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;		//avance jusqu'au prochaine axe
			ray->map_x += ray->step_x;					//met a jour l'emplacement de la case traverse par le rayon 	
			ray->side = 0;								//met a jour l'orientation de la case traverse par le rayon
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;	
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}

}

void	ft_get_draw_data(t_ray *ray, int h)
{
	//si on a touche le mur sur son axe horizontal
	//on determine la distance entre le plan de la camera et le mur 
	//et non pas entre la joueur et le mur pour eviter l'effet fish eye
	if (!ray->side)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);

	//on set la hauteur du mur
	ray->line_height =  (int)(h / ray->perp_wall_dist);

	//on set le depart du mur 
	ray->draw_start = -ray->line_height / 2 + h / 2;
	//on fait on sorte que le mur descende pas en dessous du cadre
	if (ray->draw_start < 0)
		ray->draw_start = 0;

	//on set la fin du mur 
	ray->draw_end = ray->line_height / 2 + h / 2;
	//on fait on sorte que le mur  ne depasse pas la hauteur du cadre
	if (ray->draw_end >= h)
		ray->draw_end = h - 1;
}

t_ray    *ft_raycaster(t_var *var)
{
    t_player player;
    t_ray *ray;    
	int	x;

	x = 0;
	ray = ft_init_ray_tab(var->win_size.x);
	ft_get_player_vectors(&player);
	while(x < var->win_size.x)
	{
			ft_get_ray_dir(player,&ray[x], x, var->win_size.x);
			ft_init_dda(&ray[x], player);
			ft_perform_dda(&ray[x], var->map);			
			ft_get_draw_data(&ray[x], var->win_size.y);
			x++;
	}
	return ray;
}