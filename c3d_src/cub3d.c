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

    if (c3d_data_init(&data))
        return (0);
    c3d_keys_status_init(data);
    ft_putnbr_fd(data->keys_s->a, 1);
    player_fram_init(data); //fait avec le cul
    c3d_keys_status_init(data);
    c3d_keys_manager(data);
    mlx_loop_hook(data->mlx_ptr, c3d_loop, data);
    mlx_loop(data->mlx_ptr);
    return (0);
}
