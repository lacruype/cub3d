# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 11:44:06 by lacruype          #+#    #+#              #
#    Updated: 2019/11/19 16:43:05 by lacruype         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror 
INC_FLAGS = -I

LIBFT = libft.a
LIBFT_H = libft.h


SRC_PATH = .
LIBFT_PATH = .
INC_PATH = .
OBJ_PATH = .

SRC_NAME =	ft_atoi.c			ft_bzero.c				ft_isalnum.c			ft_strlcat.c	\
		ft_isalpha.c		ft_isascii.c			ft_isdigit.c			ft_isprint.c	\
		ft_itoa.c			ft_putstr_fd.c 			ft_putnbr_fd.c 			ft_putendl_fd.c	\
		ft_memcmp.c			ft_memcpy.c				ft_strtrim.c			ft_memset.c		\
		ft_split.c			ft_strchr.c				ft_strdup.c								\
		ft_strjoin.c		ft_strlcpy.c 			ft_putchar_fd.c 		ft_memchr.c		\
		ft_strlen.c			ft_strmapi.c			ft_strncmp.c			ft_strnstr.c	\
		ft_strrchr.c		ft_substr.c				ft_tolower.c 							\
		ft_toupper.c		ft_calloc.c				ft_memccpy.c 			ft_memmove.c	\

INC_NAME = libft.h
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	@$(CC) $(FLAGS) $(SRC) -c -I $(LIBFT_H)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME) 
	@printf "[Compiling LIBFT...]		"
	@printf "[OK]\n"


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@printf "[Cleaning LIBFT Objects...]		"
	@printf "[OK]\n"

fclean: clean
	@rm -rf ./obj $(NAME)
	@printf "[Cleaning LIBFT Executable...]"
	@printf "[OK]\n"

re: fclean all

.PHONY: all clean fclean re