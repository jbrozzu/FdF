/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:18:04 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/04 16:08:09 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		expose_hook(t_env *e)
{
/*	int fd;

	fd = open(e->argv, O_RDONLY);
	if (fd == -1)
	{
		perror(e->argv);
		exit(0);
	}
	read_file(fd, e);*/
	e->argv = "coucou";
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;
	int		fd;
	
	if (argc == 2)
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 1500, 1200, "42");
		mlx_key_hook(e.win, key_hook, &e);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(argv[1]);
			exit(0);
		}
		get_tab(fd);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		write(1, "usage : ./fdf file_name\n", 24);
	return (0);
}
