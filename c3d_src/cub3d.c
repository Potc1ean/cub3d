/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keys.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:13:38 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/24 04:26:12 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../c3d_inc/cub3d.h"

int main(void)
{
    t_data  *data;

    data = malloc(sizeof(t_data));
    data->player = malloc(sizeof(t_player));
    data->player->dir = 0;
    data->player->x = 400;
    data->player->y = 300;
    data->mlx_ptr = mlx_init();
    data->win = mlx_new_window(data->mlx_ptr, 800, 600, "Cub3d des gros BOOOOWGOS");
    player_fram_init(data);
    c3d_loop(data);
    mlx_loop(data->mlx_ptr);
    return (0);
}
