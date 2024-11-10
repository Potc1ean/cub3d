#include "../c3d_inc/cub3d.h"  

static t_point apply_incr(t_data *data, t_point *oldP, float dir)
{
    t_point Px;
    t_point Py;
    
    if ((dir == 90) || (dir == 270))
    {
        Py.x = 0;
        Py.y = (int)oldP->y - sinf(deg_to_rad(dir));
    }
    else
    {
        if ((0 < cosf(deg_to_rad(dir))) || (oldP->x == (int)oldP->x))
        Px.x = (int)(oldP->x + copysign(1.0, cosf(deg_to_rad(dir))));
        else
            Px.x = (int)oldP->x;
        Px.y = oldP->y - ((Px.x - oldP->x) * tanf(deg_to_rad(dir)));
        if ((0 < -sinf(deg_to_rad(dir))) || (oldP->y == (int)oldP->y))
            Py.y = (int)(oldP->y + copysign(1.0, -sinf(deg_to_rad(dir))));
        else
            Py.y = (int)oldP->y;
        Py.x = oldP->x + ((Py.y - oldP->y) * -tanf(deg_to_rad(90 + dir -(2*fmodf(dir, 90.f)))));
        if (c3d_distance(oldP, &Px) < c3d_distance(oldP, &Py))
            return Px;
    }
    return (Py);
}

static int touched_wall(char **map, t_point P, float dir)
{
    if (!(P.x == (int)P.x))
    {
        if ((map[(int)P.y][(int)P.x] == '1') || (map[(int)P.y - 1][(int)P.x] == '1'))
            return(1);
    }
    else if (!(P.y == (int)P.y))
    {
        if ((map[(int)P.y][(int)P.x] == '1') || (map[(int)P.y][(int)P.x - 1] == '1'))
            return(1);
    }
    else if ((P.y == (int)P.y) && (P.x == (int)P.x))
    {
        if ((map[(int)P.y][(int)P.x] == '1') || (map[(int)P.y - 1][(int)P.x] == '1') 
            || (map[(int)P.y - 1][(int)P.x - 1] == '1') || (map[(int)P.y][(int)P.x - 1] == '1'))
            return(1);
    }
    return (0);
}

static void draw_hitpoint(t_data *data, float x, float y)
{
    int w;

    w = 9;
    x *= data->size;
    y *= data->size;
    void *hitpoint_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
         "c3d_xpm/hitpoint.xpm", &w, &w);
    c3d_put_img_to_img(data->screen_img, hitpoint_ptr, x, y);
    mlx_destroy_image(data->mlx_ptr, hitpoint_ptr);
}

/*c3d_raycaster :
*   this function take data of the program,
*   and direction of the ray you want to made.
*   the return is a structur with coordinates of the first 
*   collision of this ray with wall.
*/
t_point    c3d_raycaster(t_data *data, float dir)
{
    t_point tmpP;
    t_point hit_point;

    hit_point.x = data->player->pos->x;
    hit_point.y = data->player->pos->y;
    while (!touched_wall(data->map, hit_point, dir))
    {
        draw_hitpoint(data, hit_point.x, hit_point.y);
        tmpP = apply_incr(data, &hit_point, dir);
        hit_point.x = tmpP.x;
        hit_point.y = tmpP.y;
    }
    draw_hitpoint(data, hit_point.x, hit_point.y);
    return (hit_point);
}
