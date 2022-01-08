/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:27:27 by abensett          #+#    #+#             */
/*   Updated: 2021/06/10 11:55:49 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (!dest && !src)
		return (dest);
	if (dest < src)
	{	
		d = (unsigned char *)dest;
		s = (unsigned char *)src;
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d = dest + (n - 1);
		s = src + (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
