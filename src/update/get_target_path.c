#include "../../inc/cube_3d.h"

static int ft_is_target(t_point cur, t_point target)
{
		return (cur.x == target.x && cur.y == target.y);
}

static void  ft_neighbor_dir(int *dir_x, int *dir_y)
{
	dir_x[0] = 0;
	dir_x[1] = 0;
	dir_x[2] = -1;
	dir_x[3] = 1;
	dir_y[0] = -1;
	dir_y[1] = 1;
	dir_y[2] = 0;
	dir_y[3] = 0;
}

static int	ft_check_neighbor(t_data *data, t_bfs *bfs, t_point nb)
{
	if (nb.y < 0 || nb.y >= bfs->max_h || nb.x < 0 || nb.x >= bfs->max_w)
		return (0);
	if (!data->map.grid[nb.y] || nb.x >= (int)ft_strlen(data->map.grid[nb.y]))
		return (0);
	if (data->map.grid[nb.y][nb.x] == '1' || data->map.grid[nb.y][nb.x] == ' ')
		return (0);
	if (bfs->came_from[ft_get_index(nb, *bfs)].x != -1)
		return (0);
	return (1);
}

static void ft_flood(t_data *data, t_bfs *bfs ,t_point cur)
{
	int     i;
	int		dir_x[4];
	int		dir_y[4];
	t_point neighbor;

	i = 0;
	ft_neighbor_dir(dir_x, dir_y);
	while (i < 4)
	{
		neighbor.x = cur.x + dir_x[i];
		neighbor.y = cur.y + dir_y[i];

		if (ft_check_neighbor(data, bfs, neighbor))
		{
			bfs->queue[bfs->waiters] = neighbor;
			bfs->waiters++;
			bfs->came_from[ft_get_index(neighbor, *bfs)] = cur;
		}
		i++;
	}
}

void  ft_get_target_path(t_data *data ,t_bfs *bfs, t_point *cur)
{
	while (bfs->count < bfs->waiters)
	{
		*cur = bfs->queue[bfs->count];
		bfs->count++;
		if (ft_is_target(*cur, bfs->target))
			break ;
		ft_flood(data, bfs, *cur);
	}
}

void	ft_update_monster_path(t_data *data, t_player *monster)
{
	monster->next_step = ft_bfs(data, &monster->bfs,
							(t_point){(int)monster->pos_x, (int)monster->pos_y},
							(t_point){(int)data->player.pos_x, (int)data->player.pos_y});
}

int	ft_monster_arrived(t_player *monster)
{
	double	tx;
	double	ty;

	tx = monster->next_step.x + 0.5;
	ty = monster->next_step.y + 0.5;
	return (fabs(monster->pos_x - tx) < 0.01 && fabs(monster->pos_y - ty) < 0.01);
}
