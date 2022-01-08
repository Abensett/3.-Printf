/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:32:53 by abensett          #+#    #+#             */
/*   Updated: 2021/10/07 15:22:43 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(t_flags *tab, int chr)
{
	tab->precision = 1;
	if (tab->width > tab->precision)
		tab->width -= tab->precision;
	else
		tab->width = 0;
	while (!tab->minus && tab->width--)
		tab->be_printed += write(1, " ", 1);
	tab->be_printed += write(1, &chr, tab->precision);
	while (tab->minus && tab->width--)
		tab->be_printed += write(1, " ", 1);
}

void	ft_s(t_flags *tab, char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (!tab->dot || (tab->dot && tab->precision > len))
		tab->precision = len;
	if (tab->width > tab->precision)
		tab->width -= tab->precision;
	else
		tab->width = 0;
	while (!tab->minus && tab->width--)
		tab->be_printed += write(1, " ", 1);
	tab->be_printed += write(1, str, tab->precision);
	while (tab->minus && tab->width--)
		tab->be_printed += write(1, " ", 1);
}

void	ft_p(t_flags *tab, unsigned long nb, const char *str)
{
	int	len;
	int	base;
	int	pad;

	base = ft_strlen(str);
	len = ft_intlength_base(nb, base) + 2;
	pad = ft_pad(tab, len - 2, 0);
	ft_width(tab, len, pad);
	while (!tab->minus && tab->width--)
		tab->be_printed += write(1, " ", 1);
	tab->be_printed += write(1, "0x", 2);
	while (pad--)
		tab->be_printed += write(1, "0", 1);
	if (len)
		ft_printnbr_base(tab, nb, base, str);
	while (tab->minus && tab->width--)
		tab->be_printed += write(1, " ", 1);
}

void	ft_di(t_flags *tab, int nb, const char *str)
{
	long long	nbr;
	int			len;
	int			pad;
	int			base;

	base = ft_strlen(str);
	nbr = ft_abs(nb);
	if (nb < 0)
		tab->is_neg = 1;
	if (tab->dot && !nbr)
		len = 0;
	else
		len = ft_intlength_base(nbr, base);
	pad = ft_pad(tab, len, 1);
	ft_width(tab, len, pad);
	while (!tab->minus && tab->width--)
		tab->be_printed += write(1, " ", 1);
	if (tab->sign)
		tab->be_printed += write(1, &tab->sign, 1);
	while (pad--)
		tab->be_printed += write(1, "0", 1);
	if (len)
		ft_printnbr_base(tab, nbr, base, str);
	while (tab->minus && tab->width--)
		tab->be_printed += write(1, " ", 1);
}

void	ft_ux(t_flags *tab, unsigned int nb, const char *str, char *prefix)
{
	int	len;
	int	pad;
	int	base;

	base = ft_strlen(str);
	if (tab->dot && !nb)
		len = 0;
	else
		len = ft_intlength_base(nb, base);
	if (nb && tab->hashtag)
		len += ft_strlen(prefix);
	pad = ft_pad(tab, len, 0);
	ft_width(tab, len, pad);
	while (!tab->minus && tab->width--)
		tab->be_printed += write(1, " ", 1);
	while (pad--)
		tab->be_printed += write(1, "0", 1);
	if (len)
	{
		if (nb && tab->hashtag)
			tab->be_printed += write(1, prefix, 2);
		ft_printnbr_base(tab, nb, base, str);
	}
	while (tab->minus && tab->width--)
		tab->be_printed += write(1, " ", 1);
}
