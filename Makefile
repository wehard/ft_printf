# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 10:33:45 by wkorande          #+#    #+#              #
#    Updated: 2019/10/30 11:49:18 by wkorande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFTDIR = ../libft

FLAGS = #-Wall -Wextra -Werror

SRC = 	ft_printf.c\
		ft_handle_str.c\
		ft_handle_nbr.c\
		ft_handle_other.c\
		ft_putnbr_uintmax_t.c\
		ft_putnbr_base_uintmax_t.c\
		ft_itoa_base_uintmax_t.c\
		ft_ndigits_base_uintmax_t.c\
		ft_output.c\
		ft_format.c

SRCDIR = src

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(SRC:.c=.o)

INCLDIR = 	include

all: $(NAME)

$(NAME):
	@printf "\033[31m%s\n\033[34m" "Making $(LIBFT)"
	@make -C $(LIBFTDIR)
	@printf "\033[31m%s\n\033[34m" "Copying $(LIBFT) and renaming to $(NAME)"
	@cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	@printf "\033[31m%s\n\033[34m" "Creating objects from $(SRCS)"
	@gcc $(FLAGS) -I $(INCLDIR) -I $(LIBFTDIR)/includes -c $(SRCS)
	@printf "\033[31m%s\n\033[34m" "Creating final $(NAME)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

test: re
	@printf "\033[33m%s\n\033[34m" "Making test"
	@gcc -g -o test main.c -I $(INCLDIR) -I $(LIBFTDIR)/includes  -L. -lftprintf

clean:
	@printf "\033[1;30m"
	make clean -C $(LIBFTDIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
