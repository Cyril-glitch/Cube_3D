#include "../../inc/cube_3d.h"

typedef    struct s_square
{
    int pos_y;
    int pos_x;
    int h;
    int w;
    int color;
}   t_square;

static void ft_draw_square(t_data *data, t_square sqr)
{
    int y;
    int x;

    y = 0;
    while (y < sqr.h)
    {
        x = 0;
        while(x < sqr.w)
        {
            my_mlx_pixel_put(&data->screen, sqr.pos_x + x , sqr.pos_y + y, sqr.color);
            x++;
        }
        y++;
    }
}

static void ft_damage(t_square *in, int damage)
{
    in->w *= damage;
    in->w /= 100;
}

static void ft_set_bar(t_data *data, t_square *in, t_square *out, int health)
{
    int damage;

    damage = 100 - health;
    out->pos_x = data->win_size.x / 30;
    out->pos_y = data->win_size.y - (data->win_size.y / 10); 
    out->w = data->win_size.x / 5;
    out->h = data->win_size.y / 50;
    out->color = 0x33FFFF;
    in->pos_x = out->pos_x + (out->pos_x / 10);
    in->pos_y = out->pos_y + (out->pos_y / 170);
    in->w = out->w - out->w / 30;
    ft_damage(in , damage);
    in->h = out->h - out->h / 2;
    in->color = 0x0000FF;
}

void ft_draw_health(t_data *data, int health)
{
    t_square    out;
    t_square    in;

    ft_set_bar(data,&in, &out, health);
    ft_draw_square(data, out);
    ft_draw_square(data, in);
}
