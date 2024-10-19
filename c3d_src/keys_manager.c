#include "../c3d_inc/cub3d.h"

static int c3d_close_window(t_data *data)
{
	size_t	a;

	a = 0;
	mlx_clear_window(data->mlx_ptr, data->win);
	mlx_destroy_window(data->mlx_ptr, data->win);
	mlx_destroy_image(data->mlx_ptr, data->screen_img);
	while (a < 24)
	{
		mlx_destroy_image(data->mlx_ptr, data->player->vu[a]);
		a++;
	}
	free(data->map);
	free(data->keys_s);
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

static int	c3d_display_map(t_data *data)
{
	int	x = 0;
	int	y = 0;
	void *iptr = mlx_xpm_file_to_image(data->mlx_ptr, "c3d_xpm/wall_2d/c2d_wall.xpm", &data->size, &data->size);

	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
			{
				c3d_put_img_to_img(data->screen_img, iptr, x* data->size, y* data->size);
			}
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx_ptr, iptr);
	return (0);
}

static int	hub_keypress(int key, t_data *data)
{
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
	c3d_display_map(data);
    c3d_display_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->screen_img, 0, 0);
	mlx_hook(data->win, 2, 1L<<0, hub_keypress, data);
	mlx_hook(data->win, 3, 1L<<1, hub_keyrelease, data);
}
