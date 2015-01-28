/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <jbrozzu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:36:42 by jbrozzu           #+#    #+#             */
/*   Updated: 2014/11/14 16:41:56 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (needle[i] == '\0' || needle == NULL)
		return ((char *)haystack);
	while (haystack[i] && i < n)
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
