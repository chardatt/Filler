# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchardat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 15:52:41 by tchardat          #+#    #+#              #
#    Updated: 2020/07/14 13:59:18 by tchardat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tchardat.filler

SRC_PATH = srcs
SRC_NAME = main.c look_for_place.c ft_strategy.c map.c piece.c player1.c \
			reset.c tools.c player2.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

CPPFLAGS = -I includes

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@echo "Compilation of Filler:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Filler: Removing Objs"

fclean: clean
	@rm -f $(NAME)
	@echo "Filler: Removing tchardat.Filler"

re: fclean all

.PHONY: all, clean, fclean, re
