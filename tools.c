/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:12:42 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/03/13 19:37:26 by jbrozzu          ###   ########.fr       */
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

void	get_color(t_env *e, int i)
{
	if (i < -20)
		e->color = 0x03224C;
	else if (i >= -20 && i < 1)
		e->color = 0x0131B4;
	else if (i >= 1 && i <= 2)
		e->color = 0xF6DC12;
	else if (i > 2 && i <= 20)
		e->color = 0x3A9D23;
	else if (i > 20 && i <= 30)
		e->color = 0x88421D;
	else if (i > 30 && i <= 40)
		e->color = 0x79F8F8;
	else if (i > 40)
		e->color = 0xFFFFFF;
}

void	change_view(int keycode, t_env *e)
{
	if (keycode == 49 || keycode == 50 || keycode == 51)
	{
		e->zoom = 30;
		e->origine_x = 500;
		e->origine_y = 300;
		if (keycode == 50)
		{
			e->y = 20;
			e->z = 10;
		}
		if (keycode == 49)
		{
			e->y = 0;
			e->z = 0;
		}
		if (keycode == 51)
		{
			e->y = 30;
			e->z = 30;
		}
		e->h = 4;
		e->w = 1;
	}
	check_keycode2(keycode, e);
}
