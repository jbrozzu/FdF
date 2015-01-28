/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:18:04 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/01/28 16:29:02 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_env
{
	void *mlx;
	void *win;
}				t_env;

void	draw(void *mlx, void *win)
{
	int	x;
	int x1 = 100;
	int x2 = 400;
	int y1 = 100;
	int y2 = 400;

	x = x1;
	while (x<=x2)
	{
		mlx_pixel_put(mlx, win, x, y1+((y2-y1)*(x-x1))/(x2-x1), 0xFF0000);
		x++;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		main(int ac, char **av)
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
