# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchardat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 09:00:06 by tchardat          #+#    #+#              #
#    Updated: 2020/07/06 19:28:24 by tchardat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tchardat.filler

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC_PATH = srcs
SRC_NAME = main.c look_for_place.c ft_strategy.c map.c \
piece.c player1.c reset.c tools.c player2.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

$(NAME) :
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJ)
	make -C libft/ clean

fclean : clean
	make -C libft/ fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
