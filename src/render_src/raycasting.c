#include "../../inc/cube_3d.h"

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

void	ft_perform_dda(t_data *data, t_ray *ray, char **map)
{
	int hit;

	(void)data;
	hit = 0;
	while (hit == 0)
	{
		//si l'axe le plus proche est horizontal
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;	//avance jusqu'au prochaine axe
			ray->map_x += ray->step_x;				//met a jour l'emplacement de la case traverse par le rayon 	
			ray->side = 0;							//met a jour l'orientation de la case traverse par le rayon
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		/*if (get_map_tile(data, ray->map_x, ray->map_y) == -1)
			hit = 1;*/
		if (map[ray->map_y][ray->map_x] == '1')
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

void    ft_get_tex_coordinates(t_data *data, t_ray *ray, t_player player)
{
	double  wall_x;

	ray->tex_num = get_map_tile(data, ray->map_x, ray->map_y) - 1;
	if (ray->tex_num < 0 || ray->tex_num > 1)
		return ;
	if (ray->side == 0)
	{
		if (ray->step_x == 1)
			ray->tex_num = 3;
		else
			ray->tex_num = 2;
	}
	else if (ray->side == 1)
	{
		if (ray->step_y == 1)
			ray->tex_num = 1;
		else
			ray->tex_num = 0;
	}
	if (ray->side == 0)
		wall_x = player.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = player.pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (double)data->textures[ray->tex_num].w);
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1 && ray->dir_y < 0))
		ray->tex_x = data->textures[ray->tex_num].w - ray->tex_x - 1;
	ray->step = 1.0 * data->textures[ray->tex_num].h / ray->line_height;
	ray->tex_pos = (ray->draw_start - data->win_size.y / 2 + ray->line_height / 2) * ray->step;
}

void	ft_raycaster(t_data *data, t_ray *ray)
{
	int	x;

	x = 0;
	while(x < data->win_size.x)
	{
		ft_get_ray_dir(data->player, &ray[x], x, data->win_size.x);
		ft_init_dda(&ray[x], data->player);
		ft_perform_dda(data, &ray[x], data->map.grid);
		ft_get_draw_data(&ray[x], data->win_size.y);
		ft_get_tex_coordinates(data, &ray[x], data->player);
		x++;
	}
	data->ray = ray;
}
