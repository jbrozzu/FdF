/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <jbrozzu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:38:22 by jbrozzu           #+#    #+#             */
/*   Updated: 2014/11/14 17:24:55 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (needle[i] == '\0' || needle == NULL)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[j])
			j++;
		else
			j = 0;
		if (!needle[j])
			return ((char *)haystack + (i - (j - 1)));
		i++;
	}
	return (NULL);
}
