#include "../c3d_inc/cub3d.h"  

static void set_incr(float *incX, float *incY, float dir)
{
    *incX = cosf(deg_to_rad(dir));
    *incY = -sinf(deg_to_rad(dir));
    if (fabsf(*incX) > fabsf(*incY))
        *incX = 1 * copysign(1.0, *incX);
    else if (fabsf(*incX) == fabsf(*incY))
    {
        *incX = 1 * copysign(1.0, *incX);
        *incY = 1 * copysign(1.0, *incY);
    }
    else
        *incY = 1 * copysign(1.0, *incY);
}

static void hitpoint(float *x, float *y, t_data *data, float incX, float incY)
{
    float posX = *x;
    float posY = *y;
    /* bonne maniere de faire mais pas jolie :
    *   posX += incX + (posX - (float)(int)posX);
    *   posY += incY + (posY - (float)(int)posY);
    */
    posX = (int)posX;
    posY = (int)posY;
    while (1)
    {
        if (data->map[(int)(posY+(incY/2))][(int)(posX+(incX/2))] == '1')
            break;
        posX += incX;
        posY += incY;
    }
    *x = posX;
    *y = posY;
}

static void draw_hitpoint(t_data *data, float x, float y)
{
    int w;

    w = 9;
    x *= data->size;
    y *= data->size;
    void *hitpoint_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "c3d_xpm/hitpoint.xpm", &w, &w);
    c3d_put_img_to_img(data->screen_img, hitpoint_ptr, x, y);
    mlx_destroy_image(data->mlx_ptr, hitpoint_ptr);
}

void    c3d_raycaster(t_data *data)
{
    float incX;
    float incY;
    float x = data->player->x;
    float y = data->player->y;

    set_incr(&incX, &incY, data->player->dir);
    hitpoint(&x, &y, data, incX, incY);
    draw_hitpoint(data, x, y);

    printf("hitpoint x : %f\n", x);
    printf("hitpoint y : %f\n", y);
    printf("-------------------\n");
    printf("direction = %d\n", c3d_get_player_dir(data->player->dir));
    printf("player x : %f\n", data->player->x);
    printf("player y : %f\n", data->player->y);
    printf("/////////////////////////////\n");
    printf("/////////////////////////////\n");
}