/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:15:15 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/03/17 16:47:31 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

int		ft_strlen_tab(char **s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	check_tab(t_env *e)
{
	int i;

	i = 0;
	while (e->tab[i] != NULL)
	{
		if (e->tab[i + 1])
		{
			if ((ft_strlen_tab(e->tab[i + 1]) >
					(ft_strlen_tab(e->tab[i]) + 1)) ||
					(ft_strlen_tab(e->tab[i + 1]) <
					(ft_strlen_tab(e->tab[i]) - 1)))
			{
				write(1, "error : the map is invalid - try with a ", 40);
				write(1, "square map.\n", 12);
				exit (0);
			}
		}
		i++;
	}
}

void	get_tab(int fd, t_env *e)
{
	char	**line;
	int		ret;
	int		i;
	int		j;

	ret = 1;
	i = 0;
	line = malloc(sizeof(char*) * 1024);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line[i]);
		if (ret > 0)
			i++;
		if (ret == -1)
			exit(0);
	}
	j = 0;
	e->tab = malloc(sizeof(char **) * (i + 1));
	while (i)
	{
		e->tab[j] = ft_strsplit(line[j], ' ');
		i--;
		j++;
	}
	e->tab[j] = NULL;
	check_tab(e);
}
