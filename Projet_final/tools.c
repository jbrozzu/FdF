/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:12:42 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/25 16:06:44 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

int		positive_valor(int res)
{
	if (res < 0)
		res *= (-1);
	return (res);
}

void	swap(long *x1, long *x2, long *y1, long *y2)
{
	long	temp;

	temp = *x1;
	*x1 = *x2;
	*x2 = temp;
	temp = *y1;
	*y1 = *y2;
	*y2 = *y1;
}

void	set_variables(t_env *e)
{
	e->zoom = 30;
	e->origine_x = 500;
	e->origine_y = 300;
	e->y = 20;
	e->z = 10;
	e->h = 4;
	e->w = 1;
}
