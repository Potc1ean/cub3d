#include "../c3d_inc/cub3d.h"

static int	hub_keypress(int key, t_data *data)
{
	if (key == K_LEFT || key == K_RIGHT)
	{
        if (key == K_LEFT)
			data->hero->dir -= 15;
		else if (key == K_RIGHT)
			data->hero->dir += 15;
		if (data->hero->dir < 0)
			data->hero->dir += 360;
        data->hero->dir %= 360;
		mlx_clear_window(data->ptr, data->win);
		display_hero(data);
	}
	if (key == K_ESC)
	{
		ft_putstr_fd("prout\n", 1);
		exit(1);
		// mlx_clear_window(data->ptr, data->win);
		// mlx_destroy_window(data->ptr, data->win);
	}
	return (0);
}

void	c3d_loop(t_data *data)
{
	display_hero(data);
	mlx_hook(data->win, 2, 1L<<0, hub_keypress, data);
}
