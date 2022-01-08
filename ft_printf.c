/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:44:27 by abensett          #+#    #+#             */
/*   Updated: 2021/10/07 15:11:00 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_reinit_flags(t_flags *tab, int refesh)
{
	tab->width = 0;
	tab->precision = 0;
	tab->is_precised = 0;
	tab->sign = '\0';
	tab->is_neg = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->dot = 0;
	tab->hashtag = 0;
	tab->space = 0;
	tab->plus = 0;
	if (refesh)
		tab->be_printed = 0;
}

static int	ft_type(char c)
{
	const char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (c == *str++)
			return (1);
	}
	return (0);
}

static void	ft_flags(char c, t_flags *tab)
{
	if (ft_isdigit(c))
	{
		if (tab->dot)
		{
			tab->precision = (tab->precision * 10) + (c - '0');
			tab->is_precised = 1;
		}
		else if (c == '0' && !tab->width)
			tab->zero = 1;
		else
			tab->width = (tab->width * 10) + (c - '0');
	}
	else if (c == '-')
		tab->minus = 1;
	else if (c == '+')
		tab->plus = 1;
	else if (c == ' ')
		tab->space = 1;
	else if (c == '.')
		tab->dot = 1;
	else if (c == '#')
		tab->hashtag = 1;
}

static char	*ft_identifiers(char *param, t_flags *tab)
{
	const char	*decimal = "0123456789";
	const char	*lowerhex = "0123456789abcdef";
	const char	*upperhex = "0123456789ABCDEF";

	while (*param && !ft_type(*param))
		ft_flags(*param++, tab);
	if (*param == 'c')
		ft_c(tab, va_arg(tab->arg, int));
	else if (*param == 's')
		ft_s(tab, va_arg(tab->arg, char *));
	else if (*param == 'p')
		ft_p(tab, va_arg(tab->arg, unsigned long), lowerhex);
	else if (*param == 'd' || *param == 'i')
		ft_di(tab, va_arg(tab->arg, int), decimal);
	else if (*param == 'u')
		ft_ux(tab, va_arg(tab->arg, unsigned int), decimal, "");
	else if (*param == 'x')
		ft_ux(tab, va_arg(tab->arg, unsigned int), lowerhex, "0x");
	else if (*param == 'X')
		ft_ux(tab, va_arg(tab->arg, unsigned int), upperhex, "0X");
	else if (*param == '%')
		tab->be_printed += write(1, "%", 1);
	return (++param);
}

int	ft_printf(const char *str, ...)
{
	t_flags	*tab;
	int		i;

	tab = malloc(sizeof(t_flags));
	if (!tab)
		return (-1);
	ft_reinit_flags(tab, 1);
	i = 0;
	va_start(tab->arg, str);
	while (*str)
	{
		if (*str == '%' && *str++)
		{
			str = ft_identifiers((char *)str, tab);
			ft_reinit_flags(tab, 0);
		}
		else
			i += write(1, str++, 1);
	}
	va_end(tab->arg);
	i += tab->be_printed;
	free(tab);
	return (i);
}
