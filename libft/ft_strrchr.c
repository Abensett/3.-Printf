/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:28:38 by abensett          #+#    #+#             */
/*   Updated: 2021/06/10 11:52:19 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*i;

	i = ft_strchr(str, '\0');
	while (i >= str)
	{
		if (*i == (unsigned char)c)
			return ((char *)i);
		i--;
	}
	return (NULL);
}
