#include "../c3d_inc/cub3d.h"
#include <math.h>

float deg_to_rad(float i_degrees)
{
    return i_degrees * M_PI / 180.f;
}

void c3d_put_img_to_img(void *img_dst, void *img_src, int x, int y)
{
    int j;
    char *idst_addr;
    char *isrc_addr;
    int dst_bpp;
    int dst_size_line;
    int dst_endian;
    int src_bpp;
    int src_size_line;
    int src_endian;
    int src_height;

    j = 0;
    idst_addr = mlx_get_data_addr(img_dst, &dst_bpp, &dst_size_line, &dst_endian);
    isrc_addr = mlx_get_data_addr(img_src, &src_bpp, &src_size_line, &src_endian);
    src_height = (src_size_line * 8) / src_bpp;
    while (j < src_height)
    {
        ft_memcpy(idst_addr + ((y + j) * dst_size_line + x * (dst_bpp / 8)),
                isrc_addr + (j * src_size_line),
                src_size_line);
        j++;
    }
}

int c3d_get_player_dir(float dir)
{
    return((int)(dir) % 360);
}
