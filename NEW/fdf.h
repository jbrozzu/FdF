/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:40:04 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/01/30 19:48:39 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ZOOM 10
# define ORIGINE_X 400
# define ORIGINE_Y 400
# define EYE_X 20
# define EYE_Y 20
# define EYE_Z 20

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
}				t_coord;

int 			expose_hook(t_env *e);
int				key_hook(int keycode);
void			read_file(int fd, t_env *e);
void			get_coord(char **line1, char **line2, t_env *e);
int				positive_valor(int res);
void			swap(long *x1, long *x2, long *y1, long *y2);
void			trace_line(t_coord *point, t_env *e);
void			draw_case_one(t_coord *point, t_env *e);
void			draw_case_two(t_coord *point, t_env *e);
void			draw_case_three(t_coord *point, t_env *e);
void			draw_case_four(t_coord *point, t_env *e);
void    		get_next_point(t_coord *point, char **line, int i, int k);
void    		last_line(char **line, t_env *e, int k);

#endif
