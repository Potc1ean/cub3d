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
    void    *mlx_ptr;
    void    *win_ptr;

    data.s = "Kaca";
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Cub3d des gros BOOOOWGOS");
    mlx_string_put(mlx_ptr, win_ptr, 395, 295, 0xFFFFFFF, data.s);
    mlx_loop(mlx_ptr);
    return (0);
}
