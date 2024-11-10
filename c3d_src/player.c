#include "../c3d_inc/cub3d.h"

void c3d_display_player(t_data *data)
{
    int i;
    int x;
    int y;

    x = (int)(data->player->pos->x * 32); 
    y = (int)(data->player->pos->y * 32);
    if (data->player->dir < 0)
		data->player->dir += 360;
    i = ((int)data->player->dir % 360) / 15;
    c3d_put_img_to_img(data->screen_img, data->player->vu[i], x, y);
}

void player_fram_init(t_data *data)
{
    int i;
    int x = 32;

    i = 0;
    data->player->vu_xpm[0] = "c3d_xpm/player_vus/0.xpm\0";
    data->player->vu_xpm[1] = "c3d_xpm/player_vus/15.xpm\0";
    data->player->vu_xpm[2] = "c3d_xpm/player_vus/15.xpm\0";
    data->player->vu_xpm[3] = "c3d_xpm/player_vus/45.xpm\0";
    data->player->vu_xpm[4] = "c3d_xpm/player_vus/45.xpm\0";
    data->player->vu_xpm[5] = "c3d_xpm/player_vus/75.xpm\0";
    data->player->vu_xpm[6] = "c3d_xpm/player_vus/90.xpm\0";
    data->player->vu_xpm[7] = "c3d_xpm/player_vus/105.xpm\0";
    data->player->vu_xpm[8] = "c3d_xpm/player_vus/105.xpm\0";
    data->player->vu_xpm[9] = "c3d_xpm/player_vus/135.xpm\0";
    data->player->vu_xpm[10] = "c3d_xpm/player_vus/135.xpm\0";
    data->player->vu_xpm[11] = "c3d_xpm/player_vus/165.xpm\0";
    data->player->vu_xpm[12] = "c3d_xpm/player_vus/180.xpm\0";
    data->player->vu_xpm[13] = "c3d_xpm/player_vus/195.xpm\0";
    data->player->vu_xpm[14] = "c3d_xpm/player_vus/195.xpm\0";
    data->player->vu_xpm[15] = "c3d_xpm/player_vus/225.xpm\0";
    data->player->vu_xpm[16] = "c3d_xpm/player_vus/225.xpm\0";
    data->player->vu_xpm[17] = "c3d_xpm/player_vus/255.xpm\0";
    data->player->vu_xpm[18] = "c3d_xpm/player_vus/270.xpm\0";
    data->player->vu_xpm[19] = "c3d_xpm/player_vus/285.xpm\0";
    data->player->vu_xpm[20] = "c3d_xpm/player_vus/285.xpm\0";
    data->player->vu_xpm[21] = "c3d_xpm/player_vus/315.xpm\0";
    data->player->vu_xpm[22] = "c3d_xpm/player_vus/315.xpm\0";
    data->player->vu_xpm[23] = "c3d_xpm/player_vus/345.xpm\0";

    while(i < 24)
    {
        data->player->vu[i] = mlx_xpm_file_to_image(data->mlx_ptr, data->player->vu_xpm[i], &x , &x);
        i++;
    }
}
