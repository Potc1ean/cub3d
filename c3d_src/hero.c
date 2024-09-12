#include "../c3d_inc/cub3d.h"

void display_hero(t_data *data)
{
    int i;
    
    i = data->hero->dir / 15;
    mlx_put_image_to_window(data->ptr, data->win, data->hero->vu[i], 384, 284);
}

void hero_fram_init(t_data *data)
{
    int i;

    i = 0;

    data->hero->vu_xpm[0] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/0.xpm") + 1);
    data->hero->vu_xpm[1] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/15.xpm") + 1);
    data->hero->vu_xpm[2] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/15.xpm") + 1);
    data->hero->vu_xpm[3] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/45.xpm") + 1);
    data->hero->vu_xpm[4] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/45.xpm") + 1);
    data->hero->vu_xpm[5] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/75.xpm") + 1);
    data->hero->vu_xpm[6] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/90.xpm") + 1);
    data->hero->vu_xpm[7] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/105.xpm") + 1);
    data->hero->vu_xpm[8] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/105.xpm") + 1);
    data->hero->vu_xpm[9] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/135.xpm") + 1);
    data->hero->vu_xpm[10] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/135.xpm") + 1);
    data->hero->vu_xpm[11] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/165.xpm") + 1);
    data->hero->vu_xpm[12] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/180.xpm") + 1);
    data->hero->vu_xpm[13] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/195.xpm") + 1);
    data->hero->vu_xpm[14] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/195.xpm") + 1);
    data->hero->vu_xpm[15] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/225.xpm") + 1);
    data->hero->vu_xpm[16] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/225.xpm") + 1);
    data->hero->vu_xpm[17] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/255.xpm") + 1);
    data->hero->vu_xpm[18] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/270.xpm") + 1);
    data->hero->vu_xpm[19] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/285.xpm") + 1);
    data->hero->vu_xpm[20] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/285.xpm") + 1);
    data->hero->vu_xpm[21] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/315.xpm") + 1);
    data->hero->vu_xpm[22] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/315.xpm") + 1);
    data->hero->vu_xpm[23] = malloc(sizeof(char)* ft_strlen("3d_xpm/hero_vus/345.xpm") + 1);

    data->hero->vu_xpm[0] = "c3d_xpm/hero_vus/0.xpm\0";
    data->hero->vu_xpm[1] = "c3d_xpm/hero_vus/15.xpm\0";
    data->hero->vu_xpm[2] = "c3d_xpm/hero_vus/15.xpm\0";
    data->hero->vu_xpm[3] = "c3d_xpm/hero_vus/45.xpm\0";
    data->hero->vu_xpm[4] = "c3d_xpm/hero_vus/45.xpm\0";
    data->hero->vu_xpm[5] = "c3d_xpm/hero_vus/75.xpm\0";
    data->hero->vu_xpm[6] = "c3d_xpm/hero_vus/90.xpm\0";
    data->hero->vu_xpm[7] = "c3d_xpm/hero_vus/105.xpm\0";
    data->hero->vu_xpm[8] = "c3d_xpm/hero_vus/105.xpm\0";
    data->hero->vu_xpm[9] = "c3d_xpm/hero_vus/135.xpm\0";
    data->hero->vu_xpm[10] = "c3d_xpm/hero_vus/135.xpm\0";
    data->hero->vu_xpm[11] = "c3d_xpm/hero_vus/165.xpm\0";
    data->hero->vu_xpm[12] = "c3d_xpm/hero_vus/180.xpm\0";
    data->hero->vu_xpm[13] = "c3d_xpm/hero_vus/195.xpm\0";
    data->hero->vu_xpm[14] = "c3d_xpm/hero_vus/195.xpm\0";
    data->hero->vu_xpm[15] = "c3d_xpm/hero_vus/225.xpm\0";
    data->hero->vu_xpm[16] = "c3d_xpm/hero_vus/225.xpm\0";
    data->hero->vu_xpm[17] = "c3d_xpm/hero_vus/255.xpm\0";
    data->hero->vu_xpm[18] = "c3d_xpm/hero_vus/270.xpm\0";
    data->hero->vu_xpm[19] = "c3d_xpm/hero_vus/285.xpm\0";
    data->hero->vu_xpm[20] = "c3d_xpm/hero_vus/285.xpm\0";
    data->hero->vu_xpm[21] = "c3d_xpm/hero_vus/315.xpm\0";
    data->hero->vu_xpm[22] = "c3d_xpm/hero_vus/315.xpm\0";
    data->hero->vu_xpm[23] = "c3d_xpm/hero_vus/345.xpm\0";

    data->hero->vu_height = 32;
    data->hero->vu_width = 32;

    while(i < 24)
    {
        data->hero->vu[i] = mlx_xpm_file_to_image(data->ptr, data->hero->vu_xpm[i], &data->hero->vu_height, &data->hero->vu_width);
        i++;
    }
}

