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

-----BEGIN OPENSSH PRIVATE KEY-----
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
-----END OPENSSH PRIVATE KEY-----
