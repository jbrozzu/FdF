/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:35:34 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/01/30 19:33:03 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <mlx.h>


void		draw_case_one(t_coord *point, t_env *e)   // horizon gauche->droite ht/bas
{
	int	x;

	x = point->x1;
	while (x <= point->x2)
	{
		mlx_pixel_put(e->mlx, e->win, x, point->y1 + ((point->y2 - point->y1) * (x - point->x1)) / (point->x2 - point->x1), 0xFF0000);
		x++;
	}
}

void		draw_case_two(t_coord *point, t_env *e)  // horizon droite->gauche ht/bas
{
	int	x;

	x = point->x2;
	while (x <= point->x1)
	{
		mlx_pixel_put(e->mlx, e->win, x, point->y1 + ((point->y2 - point->y1) * (x - point->x1)) / (point->x2 - point->x1), 0xFF0000);
		x++;
	}
}

void		draw_case_three(t_coord *point, t_env *e)  // vertical dr/gch gch/dr bas
{
	int	x;

	x = point->y1;
	while (x <= point->y2)
	{
		mlx_pixel_put(e->mlx, e->win, point->x1 + ((point->x2 - point->x1) * (x - point->y1)) / (point->y2 - point->y1), x, 0xFF0000);
		x++;
	}
}

void	draw_case_four(t_coord *point, t_env *e)  // vertical dr/gch gch/dr haut
{
	int	x;

	x = point->y2;
	while (x <= point->y1)
	{
		mlx_pixel_put(e->mlx, e->win, point->x1 + ((point->x2 - point->x1) * (x - point->y1)) / (point->y2 - point->y1), x, 0xFF0000);
		x++;
	}
}

void	trace_line(t_coord *point, t_env *e)
{
	if ((positive_valor(point->x2 - point->x1)) > (positive_valor(point->y2 - point->y1)))
	{
		if(point->x1 < point->x2)
			draw_case_one(point, e);
		else
			draw_case_two(point, e);
	}
	else if ((positive_valor(point->x2 - point->x1)) < (positive_valor(point->y2 - point->y1)))
	{
		if(point->y1 < point->y2)
			draw_case_three(point, e);
		else
			draw_case_four(point, e);
	}
}
