/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:40:04 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/25 18:42:26 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	char		*argv;
	char		***tab;
	int			zoom;
	int			origine_x;
	int			origine_y;
	double		h;
	int			y;
	int			z;
	double		w;
	int			color;
}				t_env;

typedef struct	s_coord
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		h1;
	double		h2;
	int			i;
	int			j;
	int			k;
	int			x;
}				t_coord;

int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				key_hook_2(int keycode, t_env *e);
void			set_variables(t_env *e);
int				positive_valor(int res);
void			trace_line(t_coord *point, t_env *e, int i);
void			draw_case_one(t_coord *point, t_env *e);
void			draw_case_two(t_coord *point, t_env *e);
void			draw_case_three(t_coord *point, t_env *e);
void			draw_case_four(t_coord *point, t_env *e);
void			read_file(t_env *e);
void    		set_coord(t_env *e, t_coord *p);
void			get_tab(int fd, t_env *e);
void    		get_color(t_env *e, int i);

#endif
