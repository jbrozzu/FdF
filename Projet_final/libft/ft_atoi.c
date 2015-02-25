/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:17:49 by jbrozzu           #+#    #+#             */
/*   Updated: 2015/02/25 17:10:15 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		total;
	int		is_neg;

	total = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if ((is_neg = *str == '-' ? -1 : 1) == -1 || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		total = (total * 10) + (*str++ - '0');
	return (total * is_neg);
}
