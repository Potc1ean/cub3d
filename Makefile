# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 04:13:09 by ichpakov          #+#    #+#              #
#    Updated: 2024/05/15 16:27:59 by ichpakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re make norm

NAME = cub3d
LIBFT = libft/libft.a
LIBMLX = -Lmlx/

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS =	c3d_src/main.c			c3d_src/player.c	c3d_src/c3d_init.c	\
		c3d_src/keys_manager.c	c3d_src/c3d_loop.c	c3d_src/c3d_utils.c	\
		c3d_src/c3d_raycaster.c

HEAD =	c3d_inc/cub3d.h		c3d_inc/c3d_keys.h

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

CC = gcc
CF = -fsanitize=address -static-libasan -g #-Wall -Werror -Wextra
SL = -lmlx_linux -lXext -lX11 -lm -lz
CI = -I ./c3d_inc/


AR = ar rcs
RM = rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all: ${NAME}

# Binary creation

${NAME}: ${SRCS} ${HEAD} ${LIBFT} ${LIBMLX}
	${CC} ${CF} ${CI} ${SRCS} ${LIBFT} ${LIBMLX} ${SL} -o ${NAME}

${LIBFT}:
	make -C libft/

${LIBMLX}:
	make -C mlx/

# Mandatory rules

clean:
	${RM}

fclean: clean
	${RM} ${NAME}
	make fclean -C libft/
	make clean -C mlx/

re: fclean all