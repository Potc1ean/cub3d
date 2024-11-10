#include "../c3d_inc/cub3d.h"

static int c3d_close_window(t_data *data)
{
	size_t	a;

	a = 0;
	mlx_clear_window(data->mlx_ptr, data->win);
	mlx_destroy_window(data->mlx_ptr, data->win);
	mlx_destroy_image(data->mlx_ptr, data->screen_img);
	mlx_destroy_image(data->mlx_ptr, data->wall_iptr);
	mlx_destroy_image(data->mlx_ptr, data->bg_iptr);
	while (a < 24)
	{
		mlx_destroy_image(data->mlx_ptr, data->player->vu[a]);
		a++;
	}
	free(data->map);
	free(data->keys_s);
	free(data->player->pos);
	free(data->player);
	data->mlx_ptr = NULL;
	data->win = NULL;
	exit(data->iloop);
	return (1);
}

static void move(int key, t_data *data)
{
    if (key == K_A)
	{
		data->keys_s->a = 1;
		data->keys_s->d = 0;
	}
	if (key == K_D)
	{
		data->keys_s->a = 0;
		data->keys_s->d = 1;
	}
	if (key == K_S)
	{
		data->keys_s->s = 1;
		data->keys_s->w = 0;
	}
	if (key == K_W)
    {
		data->keys_s->w = 1;
	}
}

static int hub_keyrelease(int key, t_data *data)
{
	if (key == K_LEFT)
		data->keys_s->l = 0;
	if (key == K_RIGHT)
		data->keys_s->r = 0;
	if (key == K_A)
		data->keys_s->a = 0;
	if (key == K_D)
		data->keys_s->d = 0;
	if (key == K_S)
		data->keys_s->s = 0;
	if (key == K_W)
		data->keys_s->w = 0;
	if (key == K_ESC)
		c3d_close_window(data);
	return (0);
}

static int	hub_keypress(int key, t_data *data)
{
	// c3d_raycaster(data);
	move(key, data);
    if (key == K_LEFT)
	{
		data->keys_s->l = 1;
		data->keys_s->r = 0;
	}
	if (key == K_RIGHT)
	{
		data->keys_s->l = 0;
		data->keys_s->r = 1;
	}
	return (0);
}

void c3d_keys_manager(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->screen_img, 0, 0);
	mlx_hook(data->win, 2, 1L<<0, hub_keypress, data);
	mlx_hook(data->win, 3, 1L<<1, hub_keyrelease, data);
}
