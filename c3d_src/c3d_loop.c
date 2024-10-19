#include "../c3d_inc/cub3d.h"

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
        void *bg_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "c3d_xpm/background.xpm",&(data->size), &(data->size)); 
        c3d_put_img_to_img(data->screen_img, bg_ptr, (int)(data->player->x*32), (int)(data->player->y*32));
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
        mlx_destroy_image(data->mlx_ptr, bg_ptr);
    }
}

int c3d_loop(t_data *data)
{
    c3d_player_move(data);
	c3d_display_player(data);
    mlx_clear_window(data->mlx_ptr, data->win);
    mlx_put_image_to_window(data->mlx_ptr, data->win, data->screen_img, 0, 0);
	return (0);
}
