/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:40:04 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/04 18:04:44 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ZOOM 50
# define ORIGINE_X 100
# define ORIGINE_Y 400

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
int				key_hook(int keycode);
void			get_coord(char **line1, char **line2, t_env *e, int k);
int				positive_valor(int res);
void			swap(long *x1, long *x2, long *y1, long *y2);
void			trace_line(t_coord *point, t_env *e);
void			draw_case_one(t_coord *point, t_env *e);
void			draw_case_two(t_coord *point, t_env *e);
void			draw_case_three(t_coord *point, t_env *e);
void			draw_case_four(t_coord *point, t_env *e);
void    		get_next_point(t_coord *point, char **line, int i, int k);
void    		last_line(char **line, t_env *e, int k);
int				**get_tab(int fd);
int				*get_str_int(char **tab);
int     		**get_tab_int(int *str);

#endif
