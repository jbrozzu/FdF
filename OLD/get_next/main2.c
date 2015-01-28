/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:12:24 by cdeniau           #+#    #+#             */
/*   Updated: 2014/12/10 14:15:37 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			get_next_line(int const fd, char **line);

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	i = 0;
	while (i < 10)
	{
		printf("%i", get_next_line(fd, &line));
		i++;
	}
	return (0);
}
