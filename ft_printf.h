/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:01:34 by abensett          #+#    #+#             */
/*   Updated: 2021/10/07 15:22:51 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int		width;
	int		precision;
	int		is_precised;
	char	sign;
	int		is_neg;
	int		minus;
	int		zero;
	int		dot;
	int		hashtag;
	int		space;
	int		plus;
	int		be_printed;
	va_list	arg;
}			t_flags;

int		ft_printf(const char *str, ...);
int		ft_pad(t_flags *tab, int len, int bool_signed);
void	ft_width(t_flags *tab, int len, int pad);
void	ft_printnbr_base(t_flags *tab, unsigned long n, int b, const char *s);
int		ft_intlength_base(unsigned long long nb, int base);

void	ft_c(t_flags *tab, int chr);
void	ft_s(t_flags *tab, char *str);
void	ft_p(t_flags *tab, unsigned long nb, const char *str);
void	ft_di(t_flags *tab, int nb, const char *str);
void	ft_ux(t_flags *tab, unsigned int nb, const char *str, char *ppd);

#endif
