# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 14:12:49 by lacruype          #+#    #+#              #
#    Updated: 2019/11/19 15:13:27 by lacruype         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
INC_FLAGS = -I

GNL = gnl.a
GNL_H = gnl.h


SRC_PATH = .
GNL_PATH = .
INC_PATH = .
OBJ_PATH = .

SRC_NAME =	get_next_line.c \
			get_next_line_utils.c \

INC_NAME = GNL.h
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	@$(CC) $(FLAGS) $(SRC) -c -I $(GNL_H)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME) 
	@printf "[Compiling GNL...]		"
	@printf "[OK]\n"


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@printf "[Cleaning GNL Objects...]		"
	@printf "[OK]\n"

fclean: clean
	@rm -rf ./obj $(NAME)
	@printf "[Cleaning GNL Executable...]"
	@printf "[OK]\n"

re: fclean all

.PHONY: all clean fclean re