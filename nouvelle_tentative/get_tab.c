/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 15:51:17 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/04 18:04:32 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

int		**get_tab(int fd)
{
	char *line;
	char **tab;
	int ret;
	int *str;
	int	**tab_i;
	
	while(ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			exit(0);
		if (ret > 0)
		{
			tab = ft_strsplit(line, ' ');
			str = get_str_int(tab);
			tab_i = get_tab_int(str);
		}
	}
	return (tab_i);
}

int		*get_str_int(char **tab)
{
	int *str;
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (tab[j])
		j++;
	str = (int *)malloc(sizeof(int) * (j + 1));
	while(tab[i])
	{	
		str[i] = ft_atoi(tab[i]);
		i++;
	}
	str[i] = 1234567;
	return (str);
}

int		**get_tab_int(int *str)
{
	static int	i = 1;
	int			**tab_i;
	int			**temp;
	


	i++;
	return (tab_i);

}
