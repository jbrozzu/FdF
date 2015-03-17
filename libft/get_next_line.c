/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <jbrozzu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:55:50 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/26 16:58:01 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fonction_2(int const fd, t_static *toto)
{
	char	*buf;
	int		result;
	char	*tmp;

	buf = ft_strnew(BUF_SIZE);
	if (BUF_SIZE < 1)
		return (-1);
	if (!toto->str)
		toto->str = ft_strnew(0);
	while ((result = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[result] = '\0';
		tmp = ft_strjoin(toto->str, buf);
		free((char *)toto->str);
		toto->str = ft_strdup(tmp);
		free((char *)tmp);
		toto->text_size += result;
	}
	free(buf);
	if (result < 0)
		return (-1);
	return (0);
}

int		ft_fonction_3(t_static *toto, char **line)
{
	int j;

	j = 0;
	while (toto->copy[j] != '\n' && toto->copy[j] != '\0')
		j++;
	*line = ft_strsub(toto->copy, 0, j);
	toto->cmp_text_size += j + 1;
	toto->copy = &(toto->copy[j + 1]);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_static toto;

	*line = ft_strnew(0);
	free(*line);
	if (!toto.text_size && !toto.cmp_text_size)
	{
		toto.text_size = 0;
		toto.cmp_text_size = 0;
	}
	if (!toto.str)
		if (ft_fonction_2(fd, &toto) == -1)
			return (-1);
	toto.copy = (!toto.copy ? NULL : toto.copy);
	toto.copy = (toto.copy == NULL ? toto.str : toto.copy);
	if (toto.cmp_text_size >= toto.text_size)
	{
		free((void *)toto.str);
		toto.str = NULL;
		toto.copy = NULL;
		return (0);
	}
	ft_fonction_3(&toto, &(*line));
	return (1);
}
