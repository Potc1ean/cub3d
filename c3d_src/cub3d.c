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
    data->hero = malloc(sizeof(t_hero));
    data->hero->dir = 0;
    data->ptr = mlx_init();
    data->win = mlx_new_window(data->ptr, 800, 600, "Cub3d des gros BOOOOWGOS");
    hero_fram_init(data);
    c3d_loop(data);
    mlx_loop(data->ptr);
    return (0);
}
