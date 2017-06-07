# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msassaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/19 11:59:17 by msassaro          #+#    #+#              #
#    Updated: 2016/04/20 15:32:13 by msassaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in

FLAG	= -Wall -Wextra -Werror -O3
INCL	= -I libft/includes/ -I ./
LIB		= libft/libft.a

SRC		= \
		check_line.c\
		check_room.c\
		check_tube.c\
		cost_matrix.c\
		double_room_check.c\
		ft_move.c\
		main.c\
		utils.c\
		utils2.c\
		utils3.c\
		utils4.c\
		pathlen.c\
		weight_degree.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAG) -c $(SRC) $(INCL)
	@gcc $(FLAG) -o $(NAME) $(FLAG) $(OBJ) $(LIB) $(INCL)

%.oL %.c: $(INCL)
	@gcc $(FLAG) -o $@ -c $^

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
