/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:40:04 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/01/27 18:43:38 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ZOOM 30
# define ORIGINE_X 100
# define ORIGINE_Z 100

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
	int			x1;
	int			x2;
	int			y1;
	int			y2;
}				t_coord;


int				main(int ac, char **av);
int 			expose_hook(t_env *e);
int				key_hook(int keycode);
void    		read_file(int fd, t_env *e);
void    		get_coord(char **line1, char **line2, t_env *e);
void    		last_line(char **line1, t_env *e);

#endif
