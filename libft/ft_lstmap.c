/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:15:47 by abensett          #+#    #+#             */
/*   Updated: 2021/06/10 14:11:48 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	first = ft_lstnew(f(lst->content));
	if (!f || !lst || !first)
		return (NULL);
	new = first;
	lst = lst->next;
	while (lst)
	{
		new -> next = ft_lstnew(f(lst->content));
		if (!(new->next))
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		new = new ->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (first);
}
