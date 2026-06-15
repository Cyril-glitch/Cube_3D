#include "../../inc/cube_3d.h"

static void ft_move_left(t_data *data, double target_x, double speed)
{
    if (data->monster.pos_x < target_x)
    {
        data->monster.pos_x += speed;
        if (data->monster.pos_x > target_x) // Évite de dépasser la cible
            data->monster.pos_x = target_x;
    }
}


static void ft_move_right(t_data *data, double target_x, double speed)
{
    if (data->monster.pos_x > target_x)
    {
        data->monster.pos_x -= speed;
        if (data->monster.pos_x < target_x)
            data->monster.pos_x = target_x;
    }

}

static void ft_move_down(t_data *data, double target_y, double speed)
{
    if (data->monster.pos_y > target_y)
    {
        data->monster.pos_y -= speed;
        if (data->monster.pos_y < target_y)
            data->monster.pos_y = target_y;
    }
}

static void ft_move_up(t_data *data, double target_y, double speed)
{
    if (data->monster.pos_y < target_y)
    {
        data->monster.pos_y += speed;
        if (data->monster.pos_y > target_y)
            data->monster.pos_y = target_y;
    }
}

void    ft_bot_move(t_data *data)
{
    double  speed = 0.03;
    double  target_x;
    double  target_y;

    target_x = data->monster.next_step.x + 0.5;
    target_y = data->monster.next_step.y + 0.5;
    ft_move_left(data, target_x, speed);
    ft_move_right(data, target_x, speed);
    ft_move_up(data, target_y, speed);
    ft_move_down(data, target_y, speed);
    if (data->monster.pos_x == target_x && data->monster.pos_y == target_y)
    {
        ft_bfs(data, &data->bfs);
    }
}