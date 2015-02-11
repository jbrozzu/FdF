/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:25:06 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/11 18:41:17 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

void	read_file(t_env *e)
{
	t_coord p;
	int i;
	int j;
	int k;
	int x;

	i = 0;
	j = 0;
	k = 0;
	x = 0;
	while (e->tab[j] != NULL)
	{
		i = 0;
		while(e->tab[j][i])
		{
			p.x1 = (e->ORIGINE_X + (e->ZOOM * i) - x) / e->w;
			p.y1 = (e->ORIGINE_Y + (e->ZOOM * j) + k) / e->w;
			p.y1 -= e->h * ft_atoi(e->tab[j][i]);
			if (e->tab[j][i + 1] != NULL)
			{
				p.x2 = (e->ORIGINE_X + (e->ZOOM * (i + 1)) - x) / e->w;
				p.y2 = (e->ORIGINE_Y + (e->ZOOM * j) + (k + e->z)) / e->w;
				p.y2 -= e->h * ft_atoi(e->tab[j][i + 1]);
				trace_line(&p, e);
			}
			if (e->tab[j + 1] != NULL)
			{
				if (e->tab[j + 1][i])
				{
					p.x2 = (e->ORIGINE_X + (e->ZOOM * i) - (x + e->y)) / e->w;
					p.y2 = (e->ORIGINE_Y + (e->ZOOM * (j + 1)) + k) / e->w;
					p.y2 -= e->h * ft_atoi(e->tab[j + 1][i]);
					trace_line(&p, e);
				}
			}
			i++;
			k += e->z;
		}
		j++;
		k = 0;
		x += e->y;
	}
}






































/*
   void	get_coord(char **line1, char **line2, t_env *e, int k)
   {
   t_coord	point;
   int		i;

   i = 0;
   while (line1[i])
   {
   point.x1 = ((EYE_Z * ((ORIGINE_X + (i * ZOOM)) - EYE_X)) / (EYE_Z + ft_atoi(line1[i]))) + EYE_X;
   point.y1 = ((EYE_Z * ((ORIGINE_Y + (k * ZOOM)) - EYE_Y)) / (EYE_Z + ft_atoi(line1[i]))) + EYE_Y;
   if (line2[i] != '\0')
   {
   get_next_point1(&point, line2, i, k + 1);
   trace_line(&point, e);
   }
   if (line1[i + 1])
   {
   get_next_point2(&point, line1, i + 1, k);
   trace_line(&point, e);
   }
   i++;
   }	
   }

   void	get_next_point1(t_coord *point, char **line, int i, int k)
   {
   point->x2 = ((EYE_Z * ((ORIGINE_X + (i * ZOOM)) - EYE_X)) / (EYE_Z + ft_atoi(line[i]))) + EYE_X;
   point->y2 = ((EYE_Z * ((ORIGINE_Y + (k * ZOOM)) - EYE_Y)) / (EYE_Z + ft_atoi(line[i]))) + EYE_Y;
   }

   void	get_next_point2(t_coord *point, char **line, int i, int k)
   {
   point->x2 = ((EYE_Z * ((ORIGINE_X + (i * ZOOM)) - EYE_X)) / (EYE_Z + ft_atoi(line[i]))) + EYE_X;
   point->y2 = ((EYE_Z * ((ORIGINE_Y + (k * ZOOM)) - EYE_Y)) / (EYE_Z + ft_atoi(line[i]))) + EYE_Y;
   }


   void	last_line(char **line, t_env *e, int k)
   {
   int i;
   t_coord point;

   i = 0;
   point.x1 = ((EYE_Z * ((ORIGINE_X + (i * ZOOM)) - EYE_X)) / (EYE_Z + ft_atoi(line[i]))) + EYE_X;
   point.y1 = ((EYE_Z * ((ORIGINE_Y + (k * ZOOM)) - EYE_Y)) / (EYE_Z + ft_atoi(line[i]))) + EYE_Y;
   while (line[i] && line[i][0] != '\0')
   {
   if (line[i + 1])
   {
   point.x2 = ((EYE_Z * ((ORIGINE_X + ((i + 1) * ZOOM)) - EYE_X)) / (EYE_Z + ft_atoi(line[i + 1]))) + EYE_X;
   point.y2 = ((EYE_Z * ((ORIGINE_Y + (k * ZOOM)) - EYE_Y)) / (EYE_Z + ft_atoi(line[i + 1]))) + EYE_Y;
   trace_line(&point, e);
   point.x1 = point.x2;
   point.y1 = point.y2;
   }
   i++;
   }
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
}*/
