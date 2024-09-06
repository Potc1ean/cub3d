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
    t_data  data;
    t_hero  hero;

    data.ptr = mlx_init();
    data.win = mlx_new_window(data.ptr, 800, 600, "Cub3d des gros BOOOOWGOS");
    hero_fram_init(&hero, &data);
    mlx_put_image_to_window(data.ptr, data.win, hero.vu[0], 384, 284);
    mlx_loop(data.ptr);
    return (0);
}
