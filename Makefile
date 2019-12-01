# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 10:33:45 by wkorande          #+#    #+#              #
#    Updated: 2019/12/01 17:17:31 by wkorande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

BLACK=\033[30m
RED=\033[0;31m
BOLDRED=\033[1;31m
GREEN=\033[0;32m
BOLDGREEN=\033[1;32m
YELLOW=\033[0;33m
BOLDYELLOW=\033[1;33m
BLUE=\033[0;34m
BOLDBLUE=\033[1;34m
PINK=\033[0;35m
BOLDPINK=\033[1;35m
CYAN=\033[0;36m
BOLDCYAN=\033[1;36m
WHITE=\033[37m
NORMAL=\033[0m

LIBFT = libft.a

LIBFTDIR = libft

FLAGS = -Wall -Wextra -Werror

SRC = 	ft_printf.c\
		ft_handle_str.c\
		ft_handle_nbr.c\
		ft_handle_other.c\
		ft_output.c\
		ft_parse.c\
		ft_cast_helper.c\
		ft_flags.c

SRCDIR = src

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(SRC:.c=.o)

INCLDIR = include

all: $(NAME)

$(NAME):
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	@printf "$(BOLDYELLOW)%s\n$(NORMAL)" "Making $(NAME)"
	@gcc $(FLAGS) -I $(INCLDIR) -I $(LIBFTDIR)/includes -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(YELLOW)%s\n$(NORMAL)" "done"

clean:
	@make clean -C $(LIBFTDIR)
	@printf "$(BOLDBLUE)%s$(NORMAL)\n" "Removing $(OBJS)"
	@rm -f $(OBJS)
	@printf "$(BLUE)%s$(NORMAL)\n" "done"

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@printf "$(BOLDBLUE)%s$(NORMAL)\n" "Removing $(NAME)"
	@rm -f $(NAME)
	@printf "$(BLUE)%s$(NORMAL)\n" "done"

re: fclean all

.PHONY: all clean fclean re
