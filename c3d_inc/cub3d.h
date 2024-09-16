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
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/lib_includes/libft.h"
# include "c3d_keys.h"

/*/////////////////////////////////////////////////////////////////////////////
		PLAYER GLOBALS
*//////////////////////////////////////////////////////////////////////////////

#define PLAYER_ROT_SPEED 10;
#define PLAYER_MOV_SPEED 10;

/*/////////////////////////////////////////////////////////////////////////////
		STRUCTURES TYPEDEFS
*//////////////////////////////////////////////////////////////////////////////

typedef struct player
{
	/*--Perm--*/
	short dir;
	float x;
	float y;

	/*--Tmp--*/
	int		vu_height;
	int		vu_width;
	char 	*vu_xpm[24]; //j'ai eu la flemme de mettre trop de frams et oui le sang ici c'est la rue
	void 	*vu[24];
}	t_player;

typedef struct s_data
{
	void    *mlx_ptr;
	void    *win;
	t_player	*player;
}	t_data;

/*Notes pour Nathans :
*	J'ai pas pense a d'autres structures donc a toi de voir si
*	si tu trouves quelque chose de pertinant mais je pense
*	qu'on va deja faire une base du jeu en 2d giga epure pour
*	pas se perdre. Mais ajoutes tout ce qui semble bien.
*/

/*/////////////////////////////////////////////////////////////////////////////
		FUNCTIONS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

void 	player_fram_init(t_data *data);
void 	display_player(t_data *data);
void	c3d_loop(t_data *data);

/*----utilis----*/
float deg_to_rad(float i_degrees);

#endif