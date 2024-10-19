/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:24:01 by ichpakov          #+#    #+#             */
/*   Updated: 2024/05/15 17:09:59 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D__
# define __CUB3D__

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include "../mlx/mlx.h"
# include "../libft/lib_includes/libft.h"
# include "c3d_keys.h"

/*/////////////////////////////////////////////////////////////////////////////
		MACROS
*//////////////////////////////////////////////////////////////////////////////

#define PLAYER_ROT_SPEED 0.1f;
#define PLAYER_MOV_SPEED 0.01f;

/*/////////////////////////////////////////////////////////////////////////////
		STRUCTURES TYPEDEFS
*//////////////////////////////////////////////////////////////////////////////

typedef struct player
{
	/*--Perm--*/
	float dir;
	float x;
	float y;
	char 	*vu_xpm[24];
	void 	*vu[24];
}	t_player;

typedef struct s_keys
{
	bool a;
	bool s;
	bool d;
	bool w;
	bool l;
	bool r;
}	t_keys;

typedef struct s_data
{
	void    	*mlx_ptr;
	int			iloop; //pour avoir le retour de mlx_loop
	void    	*win;
	void		*screen_img;
	int			size; //pour la tailler des sprites
	void		*bg_ptr;
	void		*wall_ptr;
	int			win_width; 
	int			win_height;
	char		**map;
	t_keys		*keys_s;
	t_player	*player;
}	t_data;

/*/////////////////////////////////////////////////////////////////////////////
		FUNCTIONS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

void 	c3d_display_player(t_data *data);
void	c3d_keys_manager(t_data *data);
int		c3d_loop(t_data *data);

/*----init----*/
void 	player_fram_init(t_data *data);
int		c3d_data_init(t_data **data);
void	c3d_keys_status_init(t_data *data);

/*----utilis----*/
float deg_to_rad(float i_degrees);
void c3d_put_img_to_img(void *img_dst, void *img_src, int x, int y);

#endif