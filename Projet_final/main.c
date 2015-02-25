/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:18:04 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/25 16:54:44 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int		fdf_hook(t_env *e)
{
	expose_hook(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	read_file(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	printf("key = %d\n", keycode);
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 65307)
		exit(0);
	if (keycode == 65363)
		e->origine_x += 50;
	if (keycode == 65361)
		e->origine_x -= 50;
	if (keycode == 65362)
		e->origine_y -= 50;
	if (keycode == 65364)
		e->origine_y += 50;
	if (keycode == 113)
		e->y -= 1;
	if (keycode == 119)
		e->y += 1;
	if (keycode == 97)
		e->z -= 1;
	if (keycode == 115)
		e->z += 1;
	key_hook_2(keycode, e);
	return (0);
}

int		key_hook_2(int keycode, t_env *e)
{
	if (keycode == 65451)
	{
		if (e->w > 0.2)
			e->w -= 0.2;
	}
	if (keycode == 65453)
		e->w += 0.2;
	if (keycode == 122)
		e->h -= 0.5;
	if (keycode == 120)
		e->h += 0.5;
	if (keycode == 65293)
	{
		e->zoom = 30;
		e->origine_x = 500;
		e->origine_y = 300;
		e->y = 20;
		e->z = 10;
		e->h = 4;
		e->w = 1;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;
	int		fd;

	set_variables(&e);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(argv[1]);
			exit(0);
		}
		get_tab(fd, &e);
		e.mlx = mlx_init();
		if (e.mlx == NULL)
			exit(0);
		e.win = mlx_new_window(e.mlx, 1500, 1200, "42");
		mlx_key_hook(e.win, key_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop_hook(e.mlx, fdf_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		write(1, "usage : ./fdf file_name\n", 24);
	return (0);
}
