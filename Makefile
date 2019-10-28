# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 10:33:45 by wkorande          #+#    #+#              #
#    Updated: 2019/10/28 15:53:10 by wkorande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIBFTDIR = ../libft

SRC = 	ft_printf.c\
		ft_handle_str.c\
		ft_handle_nbr.c

SRCDIR = src

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(SRC:.c=.o)

INCLDIR = include

all: $(NAME)

$(NAME):
	make -C $(LIBFTDIR)
	gcc -Wall -Wextra -Werror -I $(INCLDIR) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
