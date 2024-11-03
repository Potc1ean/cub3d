#include "../c3d_inc/cub3d.h"

static int	c3d_display_map(t_data *data)
{
	int	x = 0;
	int	y = 0;

	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				c3d_put_img_to_img(data->screen_img, data->wall_iptr, x* data->size, y* data->size);
            else
            	c3d_put_img_to_img(data->screen_img, data->bg_iptr, x* data->size, y* data->size);
			x++;
		}
		y++;
	}
	return (0);
}

static bool ph_approver(t_data *data)
{
    float x = data->player->x;
    float y = data->player->y;
    if (data->keys_s->a)
	{
		x += cosf(deg_to_rad(data->player->dir + 90)) * PLAYER_MOV_SPEED;
		y -= sinf(deg_to_rad(data->player->dir + 90)) * PLAYER_MOV_SPEED;
	}
	if (data->keys_s->s)
	{
		x -= cosf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
		y += sinf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
	}
	if (data->keys_s->d)
	{
		x += cosf(deg_to_rad(data->player->dir - 90)) * PLAYER_MOV_SPEED;
		y -= sinf(deg_to_rad(data->player->dir - 90)) * PLAYER_MOV_SPEED;
	}
	if (data->keys_s->w)
	{
		x += cosf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
		y -= sinf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
	}
    if (x > data->player->x)
        x += 1;
    if (y > data->player->y)
        y += 1;
    if (data->map[(int)y][(int)x] == '1')
        return (false);
    return (true);
}

static void c3d_player_move(t_data *data)
{
    if (data->keys_s->l)
		data->player->dir += PLAYER_ROT_SPEED;
	if (data->keys_s->r)
		data->player->dir -= PLAYER_ROT_SPEED;
    if (ph_approver(data)) 
    { 
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
    }
}

int c3d_loop(t_data *data)
{
    c3d_display_map(data);
    c3d_player_move(data);
	c3d_display_player(data);
    c3d_raycaster(data);
    mlx_clear_window(data->mlx_ptr, data->win);
    mlx_put_image_to_window(data->mlx_ptr, data->win, data->screen_img, 0, 0);
	return (0);
}
