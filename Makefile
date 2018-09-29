# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschempe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/29 11:49:48 by mschempe          #+#    #+#              #
#    Updated: 2018/09/29 14:58:46 by mschempe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src/

INC_DIR = -I inc/

SRCS =	read_input.c \

SRC = $(addprefix $(SRC_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

$(NAME):
	make re -C libft/
	$(CC) $(INC_DIR) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -L libft/ -lft

all : $(NAME)

.PHONY: clean fclean re

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
