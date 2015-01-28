/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:16:41 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/01/21 17:27:46 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

int		read_begin(int fd, **line, ***line1, ***line2)
{
	int ret;

	ret = get_next_line(fd, line);
	if (ret >= 0)
	{
		*line1 = ft_strsplit(*line, ' ');
		free(*line);
	}
	if (ret > 0)
	{
		ret = get_next_line(fd, line);
		*line2 = ft_strsplit(*line, ' ');
		free(*line);
	}
	return (ret);
}

int		reader(int fd, t_env *e)
{
	int		ret;
	char	*line;
	char	**line1;
	char	**line2
	int		i;

	i = 0;
	ret = read_begin(fd, &line, &line1, &line2);
	if (line1 == NULL)
		return(0)
	if (ret > 0)
		get_coord(line1, line2, i++, e);
	else
		get_last_coord(line1, i++, e);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if(!ret)
			break;
		get_coord(line2, ft_strsplit(line, ' '), i++, e);
		free(line2);
		line2 = ft_strsplit(line, ' ');
		free(line);
	}
	get_last_coord(line2, i, e);
	return(0);
}
