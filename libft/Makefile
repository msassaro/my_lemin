# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msassaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 18:12:18 by msassaro          #+#    #+#              #
#    Updated: 2015/12/29 18:21:09 by msassaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
FLAG	= -Wall -Wextra -Werror -O2

SRC		= \
		ft_alloc_tab.c\
		ft_atoi.c\
		ft_atoi_base.c\
		ft_atoi_startend.c\
		ft_binary_to_dec.c\
		ft_bzero.c\
		ft_factorial.c\
		ft_free_strsplit.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_itoa_base.c\
		ft_itoa_startend.c\
		ft_itobase.c\
		ft_long_atoi.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_nbrlen.c\
		ft_nbrlen_base.c\
		ft_power.c\
		ft_print_ptr.c\
		ft_printf.c\
		ft_printf_bracket.c\
		ft_printf_detect.c\
		ft_printf_flag.c\
		ft_printf_format_cdbpercent.c\
		ft_printf_format_oxup.c\
		ft_printf_format_parse.c\
		ft_printf_format_s.c\
		ft_printf_format_s_2.c\
		ft_printf_stringarg.c\
		ft_printf_wchar.c\
		ft_printf_wchar_2.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_base.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_sqrt.c\
		ft_str_malloc_plus.c\
		ft_str_malloc_rplus.c\
		ft_str_replace_char.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strrev.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_t_str_malloc_plus.c\
		ft_t_str_malloc_rplus.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_utoa.c\
		get_next_line.c\
		ft_str_digit.c\
		ft_str_alpha.c\
		ft_explode_count.c\
		ft_strcpy_startend.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@gcc $(FLAG) -c $(SRC) -I ./includes/
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
