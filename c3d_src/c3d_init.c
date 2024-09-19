#include "../c3d_inc/cub3d.h"

int c3d_data_init(t_data **data)
{
    (*data) = malloc(sizeof(t_data));
    (*data)->player = malloc(sizeof(t_player));
    (*data)->keys_s = malloc(sizeof(t_keys));
    (*data)->player->dir = 0;
    (*data)->player->x = 400;
    (*data)->player->y = 300;
    (*data)->mlx_ptr = mlx_init();
    (*data)->win = mlx_new_window((*data)->mlx_ptr, 800, 576, "Cub3d des gros BOOOOWGOS");

    (*data)->map = malloc(sizeof(char*)* 18);
    (*data)->map[0] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[1] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[2] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[3] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[4] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[5] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[6] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[7] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[8] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[9] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[10] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[11] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[12] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[13] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[14] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[15] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[16] = malloc(sizeof(char)* 25 + 1);
    (*data)->map[17] = malloc(sizeof(char)* 25 + 1);

    (*data)->map[0] = "#########################\0";
    (*data)->map[1] = "#.......................#\0";
    (*data)->map[2] = "#.......................#\0";
    (*data)->map[3] = "#......####.............#\0";
    (*data)->map[4] = "#......#..#.............#\0";
    (*data)->map[5] = "#......###..............#\0";
    (*data)->map[6] = "#......#................#\0";
    (*data)->map[7] = "#......#..####..........#\0";
    (*data)->map[8] = "#.........#.............#\0";
    (*data)->map[9] = "#.........##............#\0";
    (*data)->map[10] = "#........#..............#\0";
    (*data)->map[11] = "#........####...........#\0";
    (*data)->map[12] = "#.......................#\0";
    (*data)->map[13] = "#.......................#\0";
    (*data)->map[14] = "#.......................#\0";
    (*data)->map[15] = "#.......................#\0";
    (*data)->map[16] = "#.......................#\0";
    (*data)->map[17] = "#########################\0";
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