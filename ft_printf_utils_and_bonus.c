/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_and_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:40:06 by abensett          #+#    #+#             */
/*   Updated: 2021/10/07 15:22:23 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pad(t_flags *tab, int len, int bool_signed)
{
	if (tab->plus && bool_signed && !(tab->is_neg))
		tab->sign = '+';
	else if (tab->is_neg && bool_signed)
		tab->sign = '-';
	else if (tab->space && bool_signed)
		tab->sign = ' ';
	if (tab->zero && !tab->is_precised)
	{
		tab->precision = tab->width;
		if (tab->sign)
			tab->precision -= 1;
		if (tab->width == 1)
			return (0);
	}
	if (tab->precision > len)
		return (tab->precision - len);
	else
		return (0);
}

void	ft_width(t_flags *tab, int len, int pad)
{
	if (tab->width > (len + pad))
	{
		tab->width -= (len + pad);
		if (tab->width && tab->sign)
			tab->width -= 1;
	}
	else
		tab->width = 0;
}

int	ft_intlength_base(unsigned long long nb, int base)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb > 0)
	{
		nb /= base;
		len += 1;
	}
	return (len);
}

void	ft_printnbr_base(t_flags *tab, unsigned long nb, int b, const char *s)
{
	if (nb / b)
		ft_printnbr_base(tab, nb / b, b, s);
	tab->be_printed += write(1, &s[nb % b], 1);
}
