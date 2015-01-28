/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:02:17 by cdeniau           #+#    #+#             */
/*   Updated: 2014/12/13 17:04:24 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int			get_next_line(int const fd, char **line);
int			*fonction2(char *line);

int		main(int ac, char **av)
{
	int		fd;
	int 	i;
	char	*line;
	int		*stri;
	
	if (ac == 2)
	{
		i = 0;
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (-1);
		while ((i = get_next_line(fd, &line)) != 0)
		{
			stri = fonction2(line);
			fonction3(stri);
		
		}
	}
	return (0);
}

int		*fonction2(char *line)
{
	char 	**str;
	int 	i;
	int 	*stri;

	i = 0;
	str = ft_strsplit(line, ' ');
	stri = (int *)malloc(sizeof(int) * ft_strlen(*str));
	while (str[i])
	{
		stri[i] = ft_atoi(str[i]);
		i++;
	}
	return(stri);
}

int		fonction3(int *stri)
{
	int **tab;
	int i;
	static int j;

	i = 0;
	if (!j)
		j = 0;
	while(i < 3)
	{
		tab[j][i] =  stri[i];
		i++;
	}
	j++;
}
