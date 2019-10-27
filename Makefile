# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 10:33:45 by wkorande          #+#    #+#              #
#    Updated: 2019/10/27 10:34:53 by wkorande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIBFT = ./libft

SRC =

SRCDIR = srcs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OUT = $(SRC:.c=.o)

INCL = includes

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I $(INCL) -c $(SRCS)
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
