# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/13 14:22:28 by jbrozzu           #+#    #+#              #
#    Updated: 2014/12/13 15:50:46 by jbrozzu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C libft/ fclean
	make -C libft/
	gcc  -Wall -Wextra -Werror -I libft/includes/ -c get_next_line.c -g
	gcc  -Wall -Wextra -Werror -I libft/includes/ -c main3.c -g
	gcc -o test_gnl get_next_line.o main3.o -L libft/ -lft -g
