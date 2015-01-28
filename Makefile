# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/12 16:10:15 by jbrozzu           #+#    #+#              #
#    Updated: 2015/01/21 16:09:48 by jbrozzu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Werror -Wextra
SRC = main.c ./libft/libft.a

all: $(NAME)

$(NAME): lib
	@gcc $(FLAGS) -o $(NAME) $(SRC) -L/usr/X11/lib -lmlx -lXext -lX11
	@echo "\n    C'est fait !    \n"

lib:
		@make -C libft

cleanlib:
		@make clean -C libft
		@echo "\n    C'est fait !    \n"

fcleanlib:
		@make fclean -C libft
		@echo "\n    C'est fait !    \n"

clean:
		@/bin/rm -f $(NAME)
		@make clean -C libft
		@echo "\n    C'est fait !    \n"

fclean: clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft

re: fclean all

