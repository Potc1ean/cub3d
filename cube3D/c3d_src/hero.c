#include "../c3d_inc/cub3d.h"

void hero_fram_init(t_hero *hero, t_data *data)
{
    int i;

    i = 0;
    hero->vu_xpm[0] = "c3d_xpm/hero_vus/0.xpm";
    hero->vu_xpm[1] = "c3d_xpm/hero_vus/15.xpm";
    hero->vu_xpm[2] = "c3d_xpm/hero_vus/45.xpm";
    hero->vu_xpm[3] = "c3d_xpm/hero_vus/75.xpm";
    hero->vu_xpm[4] = "c3d_xpm/hero_vus/90.xpm";
    hero->vu_xpm[5] = "c3d_xpm/hero_vus/105.xpm";
    hero->vu_xpm[6] = "c3d_xpm/hero_vus/135.xpm";
    hero->vu_xpm[7] = "c3d_xpm/hero_vus/165.xpm";
    hero->vu_xpm[8] = "c3d_xpm/hero_vus/180.xpm";
    hero->vu_xpm[9] = "c3d_xpm/hero_vus/195.xpm";
    hero->vu_xpm[10] = "c3d_xpm/hero_vus/225.xpm";
    hero->vu_xpm[11] = "c3d_xpm/hero_vus/255.xpm";
    hero->vu_xpm[12] = "c3d_xpm/hero_vus/270.xpm";
    hero->vu_xpm[13] = "c3d_xpm/hero_vus/285.xpm";
    hero->vu_xpm[14] = "c3d_xpm/hero_vus/315.xpm";
    hero->vu_xpm[15] = "c3d_xpm/hero_vus/345.xpm";

    hero->vu_height = 32;
    hero->vu_width = 32;

    while(i < 16)
    {
        hero->vu[i] = mlx_xpm_file_to_image(data->ptr, hero->vu_xpm[i], &hero->vu_height, &hero->vu_width);
        i++;
    }
}