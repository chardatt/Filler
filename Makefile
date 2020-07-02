# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchardat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 09:00:06 by tchardat          #+#    #+#              #
#    Updated: 2020/07/02 15:12:50 by tchardat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = main.c look_for_place.c ft_strategy.c map.c \
piece.c player1.c reset.c tools.c player2.c

OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o filler

all : $(NAME)

clean :
	$(RM) $(OBJ)
	make -C libft/ clean

fclean : clean
	make -C libft/ fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
