/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:56:12 by abensett          #+#    #+#             */
/*   Updated: 2021/06/10 11:48:50 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*temp2;

	temp = *lst;
	if (!del)
		return ;
	while (temp)
	{
		temp2 = temp->next;
		del((temp)->content);
		free(temp);
		temp = temp2;
	}
	*lst = NULL;
}
