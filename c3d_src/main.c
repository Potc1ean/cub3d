#include "../c3d_inc/cub3d.h"

int main(void)
{
    t_data  *data; 

    if (c3d_data_init(&data))
        return (0);
    c3d_keys_status_init(data);
    player_fram_init(data);
    c3d_keys_manager(data);
    mlx_loop_hook(data->mlx_ptr, c3d_loop, data);
    data->iloop = mlx_loop(data->mlx_ptr);
    return (0);
}
