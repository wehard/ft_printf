# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 10:33:45 by wkorande          #+#    #+#              #
#    Updated: 2019/10/28 16:36:45 by wkorande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIBFT = libft.a

LIBFTDIR = ../libft

FLAGS = #-Wall -Wextra -Werror

SRC = 	ft_printf.c\
		ft_handle_str.c\
		ft_handle_nbr.c

SRCDIR = src

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(SRC:.c=.o)

INCLDIR = 	include

all: $(NAME)

$(NAME):
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	gcc $(FLAGS) -I $(INCLDIR) -I $(LIBFTDIR)/includes -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

test:
	gcc -o test main.c -I include  -L. -lftprintf

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
