/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:12:42 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/01/28 18:39:11 by jbrozzu          ###   ########.fr       */
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