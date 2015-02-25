/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:35:34 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/25 19:42:32 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

void	draw_case_one(t_coord *point, t_env *e)
{
	int	x;

	x = point->x1;
	while (x <= point->x2)
	{
		mlx_pixel_put(e->mlx, e->win, x, point->y1 + ((point->y2 - point->y1) *
					(x - point->x1)) / (point->x2 - point->x1), e->color);
		x++;
	}
}

void	draw_case_two(t_coord *point, t_env *e)
{
	int	x;

	x = point->x2;
	while (x <= point->x1)
	{
		mlx_pixel_put(e->mlx, e->win, x, point->y1 + ((point->y2 - point->y1) *
					(x - point->x1)) / (point->x2 - point->x1), e->color);
		x++;
	}
}

void	draw_case_three(t_coord *point, t_env *e)
{
	int	x;

	x = point->y1;
	while (x <= point->y2)
	{
		mlx_pixel_put(e->mlx, e->win, point->x1 + ((point->x2 - point->x1) *
					(x - point->y1)) / (point->y2 - point->y1), x, e->color);
		x++;
	}
}

void	draw_case_four(t_coord *point, t_env *e)
{
	int	x;

	x = point->y2;
	while (x <= point->y1)
	{
		mlx_pixel_put(e->mlx, e->win, point->x1 + ((point->x2 - point->x1) *
					(x - point->y1)) / (point->y2 - point->y1), x, e->color);
		x++;
	}
}

void	trace_line(t_coord *point, t_env *e, int i)
{
	get_color(e, i);
	if ((positive_valor(point->x2 - point->x1)) >=
			(positive_valor(point->y2 - point->y1)))
	{
		if (point->x1 < point->x2)
			draw_case_one(point, e);
		else
			draw_case_two(point, e);
	}
	else
	{
		if (point->y1 < point->y2)
			draw_case_three(point, e);
		else
			draw_case_four(point, e);
	}
}

void	get_color(t_env *e, int i)
{
	if (i < -20)
		e->color = 0x03224C;
	else if (i >= -20 && i < 0)
		e->color = 0x0131B4;
	else if (i >= 0 && i <= 2)
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





