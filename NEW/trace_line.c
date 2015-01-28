/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:35:34 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/01/28 18:39:04 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"


int		draw_case_one(int x1, int x2, int y1, int y2, t_env *e)   // horizon gauche->droite ht/bas
{
	int	x;

	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(mlx, win, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), 0xFF0000);
		x++;
	}
}

int		draw_case_two(int x1, int x2, int y1, int y2, t_env *e)  // horizon droite->gauche ht/bas
{
	int	x;

	x = x2;
	while (x <= x1)
	{
		mlx_pixel_put(mlx, win, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), 0xFF0000);
		x++;
	}
}

int		draw_case_three(int x1, int x2, int y1, int y2, t_env *e)  // vertical dr/gch gch/dr bas
{
	int	x;

	x = y1;
	while (x <= y2)
	{
		mlx_pixel_put(mlx, win, x, x1 + ((x2 - x1) * (x - y1)) / (y2 - y1), 0xFF0000);
		x++;
	}
}

int		draw_case_four(int x1, int x2, int y1, int y2, t_env *e)  // vertical dr/gch gch/dr haut
{
	int	x;

	x = y2;
	while (x <= y1)
	{
		mlx_pixel_put(mlx, win, x1 + ((x2 - x1) * (x - y1)) / (y2 - y1), x, 0xFF0000);
		x++;
	}
}

void	trace_line(int x1, int x2, int y1, int y2, t_env *e)
{
	if ((x1 < x2) && ((x2 - x1) > (positive_valor(y2 - y1))))
		draw_case_one(x1, x2, y1, y2, e);
	if ((x1 > x2) && ((positive_valor(x2 - x1)) > (positive_valor(y2 - y1))))
		draw_case_two(x1, x2, y1, y2, e);
	if ((y1 < y2) && ((y2 - y1) > (positive_valor(x2 - x1))))
		draw_case_three(x1, x2, y1, y2, e);
	if ((y1 > y2) && ((positive_valor(y2 - y1)) > (positive_valor(x2 - x1))))
		draw_case_four(x1, x2, y1, y2, e);
}
