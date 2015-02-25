/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:25:06 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/25 18:42:12 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

void	read_file(t_env *e)
{
	t_coord p;

	p.i = 0;
	p.j = 0;
	p.k = 0;
	p.x = 0;
	while (e->tab[p.j] != NULL)
	{
		p.i = 0;
		while (e->tab[p.j][p.i])
		{
			set_coord(e, &p);
			p.i++;
			p.k += e->z;
		}
		p.j++;
		p.k = 0;
		p.x += e->y;
	}
}

void	set_coord(t_env *e, t_coord *p)
{
	p->x1 = (e->origine_x + (e->zoom * p->i) - p->x) / e->w;
	p->y1 = (e->origine_y + (e->zoom * p->j) + p->k) / e->w;
	p->y1 -= e->h * ft_atoi(e->tab[p->j][p->i]);
	if (e->tab[p->j][p->i + 1] != NULL)
	{
		p->x2 = (e->origine_x + (e->zoom * (p->i + 1)) - p->x) / e->w;
		p->y2 = (e->origine_y + (e->zoom * p->j) + (p->k + e->z)) / e->w;
		p->y2 -= e->h * ft_atoi(e->tab[p->j][p->i + 1]);
		trace_line(p, e, ft_atoi(e->tab[p->j][p->i + 1]));
	}
	if (e->tab[p->j + 1] != NULL)
	{
		if (e->tab[p->j + 1][p->i])
		{
			p->x2 = (e->origine_x + (e->zoom * p->i) - (p->x + e->y)) / e->w;
			p->y2 = (e->origine_y + (e->zoom * (p->j + 1)) + p->k) / e->w;
			p->y2 -= e->h * ft_atoi(e->tab[p->j + 1][p->i]);
			trace_line(p, e, ft_atoi(e->tab[p->j + 1][p->i]));
		}
	}
}
