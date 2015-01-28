/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:25:06 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/01/28 18:39:07 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

void	read_file(int fd, t_env *e)
{
	char *line;
	char **line1;
	int ret;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return;
	line1 = ft_strsplit(line, ' ');
	free(line);
	if (ret == 0)
		last_line(line1, e);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		get_coord(line1, ft_strsplit(line, ' '), e);
		free(line1);
		line1 = ft_strsplit(line, ' ');
		free(line);
	}
	last_line(line1, e);
}

void	get_coord(char **line1, char **line2, t_env *e)
{
	t_coord		point;
	static int	i;
	static int	j;

	i = 0;
	if (!j)
		j = 0;
	while (line1[i])
	{
		point.x1 = ORIGINE_X + (ZOOM * i) / 2 - (ZOOM * j) / 2;
		point.y1 = ORIGINE_Y + (ZOOM * i) / 2 + (ZOOM * j) / 2;
		point.y1 -= 2 * ft_atoi(line1[i]);
		trace_line(&point, e);
		i++;
	}	
	j++
	return;
}

void	last_line(char **line1, t_env *e)
{
	return;
}
