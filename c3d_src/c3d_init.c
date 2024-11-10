#include "../c3d_inc/cub3d.h"

static void player_init(t_data *data)
{
    int x = 0;
    int y = 0;
    data->player->dir = 83;

    data->player->pos = malloc(sizeof(t_data));
    while (data->map[y])
    {
        while (data->map[y][x])
        {
            if (data->map[y][x] == 'P')
            {
                // data->map[y][x] = '0';
                data->player->pos->x = x;
                data->player->pos->y = y;
                return;
            }
            x++;
        }
        x = 0;
        y++;
    }
}

int c3d_data_init(t_data **data)
{
    (*data) = malloc(sizeof(t_data));
    (*data)->player = malloc(sizeof(t_player));
    (*data)->keys_s = malloc(sizeof(t_keys));
    (*data)->mlx_ptr = mlx_init();
    (*data)->win_height = 576;
    (*data)->win_width = 800;
    (*data)->size = 32;
    (*data)->win = mlx_new_window((*data)->mlx_ptr, (*data)->win_width, (*data)->win_height, "Cub3d");
    (*data)->screen_img = mlx_new_image((*data)->mlx_ptr, (*data)->win_width, (*data)->win_height);
    (*data)->wall_iptr = mlx_xpm_file_to_image((*data)->mlx_ptr, "c3d_xpm/wall_2d/c2d_wall.xpm", &(*data)->size, &(*data)->size);
    (*data)->bg_iptr = mlx_xpm_file_to_image((*data)->mlx_ptr, "c3d_xpm/background.xpm", &(*data)->size, &(*data)->size);
    (*data)->map = malloc(sizeof(char*)* 19);
    (*data)->map[0] = "1111111111111111111111111\0";
    (*data)->map[1] = "1000000000000000000000001\0";
    (*data)->map[2] = "1000000000000000000000001\0";
    (*data)->map[3] = "1000000111100000000000001\0";
    (*data)->map[4] = "1000000100100000000000001\0";
    (*data)->map[5] = "1000000111000000000000001\0";
    (*data)->map[7] = "1000000100111100000000001\0";
    (*data)->map[6] = "1000000100000000000000001\0";
    (*data)->map[8] = "1000000000100000000000001\0";
    (*data)->map[9] = "100000000011000000P000001\0";
    (*data)->map[10] = "1000000001000000000000001\0";
    (*data)->map[11] = "1000000001111000000000001\0";
    (*data)->map[12] = "1000000000000000000000001\0";
    (*data)->map[13] = "1000000000000000000000001\0";
    (*data)->map[14] = "1000000000000000000000001\0";
    (*data)->map[15] = "1000000000000000000000001\0";
    (*data)->map[16] = "1000000000000000000000001\0";
    (*data)->map[17] = "1111111111111111111111111\0";
    (*data)->map[18] = NULL;
    player_init(*data);
    return (0);
}

void c3d_keys_status_init(t_data *data)
{
    data->keys_s->a = 0;
    data->keys_s->s = 0;
    data->keys_s->d = 0;
    data->keys_s->w = 0;
    data->keys_s->l = 0;
    data->keys_s->r = 0;
}