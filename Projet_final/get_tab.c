/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:15:15 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/25 16:54:07 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

void	get_tab(int fd, t_env *e)
{
	char	**line;
	int		ret;
	int		i;
	int		j;

	ret = 1;
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
}
