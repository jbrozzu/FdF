/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:40:04 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/11 18:41:09 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
//# define ZOOM 30
//# define ORIGINE_X 700
//# define ORIGINE_Y 300

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
	int			ZOOM;
	int			ORIGINE_X;
	int			ORIGINE_Y;
	double 		h;
	int			y;
	int			z;
	double			w;
}				t_env;

typedef struct	s_coord
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		h1;
	double		h2;
}				t_coord;

int 			expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				positive_valor(int res);
void			trace_line(t_coord *point, t_env *e);
void			draw_case_one(t_coord *point, t_env *e);
void			draw_case_two(t_coord *point, t_env *e);
void			draw_case_three(t_coord *point, t_env *e);
void			draw_case_four(t_coord *point, t_env *e);
void			read_file(t_env *e);
void			get_tab2(int fd, t_env *e);

#endif
