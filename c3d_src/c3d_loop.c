#include "../c3d_inc/cub3d.h"

static int	c3d_display_map(t_data data)
{
	int	x = 0;
	int	y = 0;
	int size = 32;
	void *iptr = mlx_xpm_file_to_image(data.mlx_ptr, "c3d_xpm/wall_2d/c2d_wall.xpm", &size, &size);

	while (data.map[y])
	{
		x = 0;
		while (data.map[y][x])
		{
			if (data.map[y][x] == '#')
			{
				mlx_put_image_to_window(data.mlx_ptr, data.win, iptr, x* 32, y* 32);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void c3d_player_move(t_data *data)
{
	void *bg_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "c3d_xpm/background.xpm",&data->player->vu_height, &data->player->vu_width); 
	mlx_put_image_to_window(data->mlx_ptr, data->win, bg_ptr, data->player->x, data->player->y);
	if (data->keys_s->a)
	{
		data->player->x += cosf(deg_to_rad(data->player->dir + 90)) * PLAYER_MOV_SPEED;
		data->player->y -= sinf(deg_to_rad(data->player->dir + 90)) * PLAYER_MOV_SPEED;
	}
	if (data->keys_s->s)
	{
		data->player->x -= cosf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
		data->player->y += sinf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
	}
	if (data->keys_s->d)
	{
		data->player->x += cosf(deg_to_rad(data->player->dir - 90)) * PLAYER_MOV_SPEED;
		data->player->y -= sinf(deg_to_rad(data->player->dir - 90)) * PLAYER_MOV_SPEED;
	}
	if (data->keys_s->w)
	{
		data->player->x += cosf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
		data->player->y -= sinf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
	}
	if (data->keys_s->l)
		data->player->dir += PLAYER_ROT_SPEED;
	if (data->keys_s->r)
		data->player->dir -= PLAYER_ROT_SPEED;
	if (data->player->dir < 0)
		data->player->dir += 360;
	data->player->dir %= 360;
}

int c3d_loop(t_data *data)
{
	usleep(1000);
	c3d_player_move(data);
	c3d_display_player(data);
	return (0);
}