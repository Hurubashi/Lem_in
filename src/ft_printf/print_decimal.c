/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:44:23 by mrybak            #+#    #+#             */
/*   Updated: 2018/01/21 17:44:25 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		percision_sined_dist(t_extension ext, size_t len)
{
	size_t	i;

	i = ext.precision;
	if (ext.precision > len)
	{
		i = ext.precision - len;
	}
	else
		i = 0;
	return (i);
}

size_t		print_s_decimal(va_list args, t_settings set)
{
	intmax_t	nb;
	size_t		len;
	size_t		pers_len;

	set.strnlen.place = 0;
	set.spec == S_decimal ? nb = va_arg(args, long int) : 0;
	if (set.spec == s_decimal)
	{
		set.length == h ? nb = (short int)va_arg(args, int) : 0;
		set.length == hh ? nb = (signed char)va_arg(args, int) : 0;
		set.length == l ? nb = (long int)va_arg(args, long int) : 0;
		set.length == ll ? nb = (long long)va_arg(args, long long int) : 0;
		set.length == j ? nb = (intmax_t)(va_arg(args, intmax_t)) : 0;
		set.length == z ? nb = (size_t)(va_arg(args, size_t)) : 0;
		set.length == none && set.spec != S_decimal
		? nb = va_arg(args, int) : 0;
	}
	len = digit_len(nb);
	nb == 0 && set.ext.precision == 0 ? len = 0 : 0;
	pers_len = percision_sined_dist(set.ext, len);
	(set.flags.plus != 0 && nb >= 0) || (nb < 0) ? pers_len += 1 : 0;
	if (set.flags.space != 0 && set.ext.width <= set.ext.precision
		&& nb > 0 && set.flags.plus == 0)
		set.strnlen.place += put_nchar(' ', 1);
	return (len + set.strnlen.place + extension_dec(set, len, pers_len, nb));
}

size_t		print_u_decimal(va_list args, t_settings set)
{
	uintmax_t	nb;
	size_t		len;
	size_t		pers_len;
	size_t		ext_count;

	ext_count = 0;
	if (set.spec == U_decimal)
		nb = (unsigned long int)(va_arg(args, unsigned long int));
	else
	{
		set.length == h ? nb = (unsigned short)va_arg(args, unsigned) : 0;
		set.length == hh ? nb = (unsigned char)va_arg(args, int) : 0;
		set.length == l ? nb = (unsigned long)va_arg(args, unsigned long) : 0;
		set.length == ll ? nb = (unsigned long long int)
				va_arg(args, unsigned long long int) : 0;
		set.length == j ? nb = (uintmax_t)va_arg(args, uintmax_t) : 0;
		set.length == z ? nb = (size_t)va_arg(args, size_t) : 0;
		set.length == none && set.spec != U_decimal
		? nb = va_arg(args, unsigned int) : 0;
	}
	len = u_digit_len(nb);
	pers_len = percision_dist(set.ext, nb);
	ext_count += extension_usigned(set, len, pers_len, nb);
	return (len + ext_count);
}
