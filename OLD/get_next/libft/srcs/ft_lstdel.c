/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu <jbrozzu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 18:34:32 by jbrozzu           #+#    #+#             */
/*   Updated: 2014/11/15 10:37:10 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*next_list;

	list = (*alst);
	while (list->next)
	{
		next_list = list->next;
		del(list->content, list->content_size);
		free(list);
		list = next_list;
	}
	(*alst) = NULL;
}
