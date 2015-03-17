# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/12 16:10:15 by jbrozzu           #+#    #+#              #
#    Updated: 2015/03/17 17:34:00 by jbrozzu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Werror  -Wextra
SRC = main.c trace_line.c tools.c get_tab.c read_file.c check_keycode.c ./libft/libft.a

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@gcc $(FLAGS) -o $(NAME) $(SRC) -L/usr/X11/lib -lmlx -lXext -lX11
	@echo "\n    L'executable fdf est cree !    \n"

clean:
		@make clean -C libft
		@echo "\n    les objets sont supprimes    \n"

fclean: clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft
		@echo "\n    les objets et l'executable sont supprimes    \n"


re: fclean all

.PHONY: all clean fclean re
