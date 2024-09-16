#include "../c3d_inc/cub3d.h"

static void c3d_player_rotate(int key, t_data *data)
{
	if (key == K_LEFT)
	{
		data->player->dir += PLAYER_ROT_SPEED;
	}
	else if (key == K_RIGHT)
		data->player->dir -= PLAYER_ROT_SPEED;
	if (data->player->dir < 0)
		data->player->dir += 360;
	data->player->dir %= 360;
}

static void c3d_player_move(int key, t_data *data)
{
	if (key == K_A)
	{
		data->player->x += cosf(deg_to_rad(data->player->dir + 90)) * PLAYER_MOV_SPEED;
		data->player->y -= sinf(deg_to_rad(data->player->dir + 90)) * PLAYER_MOV_SPEED;
	}
	else if (key == K_S)
	{
		data->player->x -= cosf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
		data->player->y += sinf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
	}
	else if (key == K_D)
	{
		data->player->x += cosf(deg_to_rad(data->player->dir - 90)) * PLAYER_MOV_SPEED;
		data->player->y -= sinf(deg_to_rad(data->player->dir - 90)) * PLAYER_MOV_SPEED;
	}
	else if (key == K_W)
	{
		data->player->x += cosf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
		data->player->y -= sinf(deg_to_rad(data->player->dir)) * PLAYER_MOV_SPEED;
	}
}

static int	hub_keypress(int key, t_data *data)
{
	if (key == K_LEFT || key == K_RIGHT)
        c3d_player_rotate(key, data);
	if (key == K_W || key == K_A || key == K_S || key == K_D)
		c3d_player_move(key, data);
	if (key == K_ESC)
	{
		ft_putstr_fd("prout\n", 1);
		exit(1);
	}
	mlx_clear_window(data->mlx_ptr, data->win);
	display_player(data);
	return (0);
}

void	c3d_loop(t_data *data)
{
	display_player(data);
	mlx_hook(data->win, 3, 1L<<0, hub_keypress, data);
}
