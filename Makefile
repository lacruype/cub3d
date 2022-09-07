# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 16:37:58 by lacruype          #+#    #+#              #
#    Updated: 2020/01/15 10:50:08 by lacruype         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

PATH = srcs/

SRCS =  $(PATH)main.c\
	$(PATH)ft_chara.c\
	$(PATH)ft_hook.c\
	$(PATH)ft_cub3d_utils.c\
	$(PATH)ft_move.c\
	$(PATH)ft_parsing_cub3d.c\
	$(PATH)ft_parsing_cub3d3.c\
	$(PATH)ft_parsing_cub3d4.c\
	$(PATH)ft_parsing_nsew.c\
	$(PATH)ft_raycasting.c\
	$(PATH)ft_rays.c\
	$(PATH)ft_rotate_cam.c\
	$(PATH)textures.c\
	$(PATH)ft_sprite.c\
	$(PATH)ft_draw.c\
	$(PATH)bmp.c\
	$(PATH)ft_error.c\
	$(PATH)ft_cub3d_utils2.c\

LIB = includes

OBJS = ${SRCS:.c:=.o}

FLAGS = -Wall -Werror -Wextra

all:${NAME}

${NAME}:	${OBJS}
			gcc ${FLAGS} ${OBJS} -o ${NAME} -I ${LIB} LIBFT/libft.a GNL/gnl.a -lmlx -framework OpenGL -framework AppKit

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all

.PHONY:all clean fclean