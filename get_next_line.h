/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <jbrozzu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:56:26 by jbrozzu           #+#    #+#             */
/*   Updated: 2014/12/08 15:40:33 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUF_SIZE 8

typedef struct			s_static
{
	const char			*str;
	const char			*copy;
	unsigned int		text_size;
	unsigned int		cmp_text_size;
}						t_static;

int						get_next_line(int const fd, char **line);
int						ft_fonction_2(int const fd, t_static *toto);
int						ft_fonction_3(t_static *toto, char **line);

#endif
