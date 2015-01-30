/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:25:06 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/01/30 19:48:35 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

void	read_file(int fd, t_env *e)
{
	char *line;
	char **line1;
	int ret;
	int j;

	j = 0;
	ret = get_next_line(fd, &line);
	if (ret == -1)
		return;
	line1 = ft_strsplit(line, ' ');
	free(line);
	if (ret == 0)
		last_line(line1, e, j);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		get_coord(line1, ft_strsplit(line, ' '), e);
		free(line1);
		line1 = ft_strsplit(line, ' ');
		free(line);
		j++;
	}
	last_line(line1, e, j);
}

void	get_coord(char **line1, char **line2, t_env *e)
{
	t_coord	point;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (line1[i])
	{
		while (*line1[i + 1] != '\n')
		{
			point.x1 = ((EYE_Z * ((ORIGINE_X + (i * ZOOM)) - EYE_X)) / (EYE_Z + ft_atoi(line1[i]))) + EYE_X;
			point.y1 = ((EYE_Z * ((ORIGINE_Y + (k * ZOOM)) - EYE_Y)) / (EYE_Z + ft_atoi(line1[i]))) + EYE_Y;
			if (line2[i] != '\0')
			{
				get_next_point(&point, line2, i, k + 1);
				trace_line(&point, e);
			}
			if (line1[i + 1])
			{
				get_next_point(&point, line1, i + 1, k);
				trace_line(&point, e);
			}
			i++;
		}
		k++;
	}	
}

void	get_next_point(t_coord *point, char **line, int i, int k)
{
	point->x2 = ((EYE_Z * ((ORIGINE_X + (i * ZOOM)) - EYE_X)) / (EYE_Z + ft_atoi(line[i]))) + EYE_X;
	point->y2 = ((EYE_Z * ((ORIGINE_Y + (k * ZOOM)) - EYE_Y)) / (EYE_Z + ft_atoi(line[i]))) + EYE_Y;
}

void	last_line(char **line, t_env *e, int k)
{
	int i;
	t_coord point;

	i = 0;
	while (line[i] && line[i][0] != '\n')
	{
		point.x1 = ((EYE_Z * ((ORIGINE_X + (i * ZOOM)) - EYE_X)) / (EYE_Z + ft_atoi(line[i]))) + EYE_X;
		point.y1 = ((EYE_Z * ((ORIGINE_Y + (k * ZOOM)) - EYE_Y)) / (EYE_Z + ft_atoi(line[i]))) + EYE_Y;
		if (line[i + 1])
		{
			point.x2 = ((EYE_Z * ((ORIGINE_X + ((i + 1) * ZOOM)) - EYE_X)) / (EYE_Z + ft_atoi(line[i + 1]))) + EYE_X;
			point.y2 = ((EYE_Z * ((ORIGINE_Y + (k * ZOOM)) - EYE_Y)) / (EYE_Z + ft_atoi(line[i + 1]))) + EYE_Y;
		}
		trace_line(&point, e);
		i++;
	}
}
