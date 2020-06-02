# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/20 10:35:23 by mcaptain          #+#    #+#              #
#    Updated: 2020/05/25 17:21:46 by mcaptain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = includes/printf.h
SRC = 	filler.c			\
		handler.c			\
		other_handler.c		\
		manage.c			\
		print.c				\
		ft_atoi.c			\
		ft_isdigit.c		\
		ft_ltoa_base.c		\
		ft_strlen.c			\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_strdup.c			\
		ft_tolower.c		\
		ft_tolower_str.c	\

CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
HDRS_PTH = includes
SRC_PTH = src/

all: $(NAME) 

$(NAME): $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: $(SRC_PTH)%.c $(HEADER)
	gcc $(CFLAGS) -I$(HDRS_PTH) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re