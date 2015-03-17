/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keycode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:04:28 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/03/17 15:56:43 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	check_keycode1(int keycode, t_env *e)
{
	if (keycode == 65307 || keycode == 65363 || keycode == 65362 ||
			keycode == 65361 || keycode == 65364 || keycode == 113 ||
			keycode == 119 || keycode == 97 || keycode == 115 ||
			keycode == 65451 || keycode == 65453 || keycode == 122 ||
			keycode == 120 || keycode == 99 || keycode == 118 ||
			keycode == 49 || keycode == 50 || keycode == 51)
		mlx_clear_window(e->mlx, e->win);
}

void	check_keycode2(int keycode, t_env *e)
{
	if (keycode == 65307 || keycode == 65363 || keycode == 65362 ||
			keycode == 65361 || keycode == 65364 || keycode == 113 ||
			keycode == 119 || keycode == 97 || keycode == 115 ||
			keycode == 65451 || keycode == 65453 || keycode == 122 ||
			keycode == 120 || keycode == 99 || keycode == 118 ||
			keycode == 49 || keycode == 50 || keycode == 51)
		expose_hook(e);
}
