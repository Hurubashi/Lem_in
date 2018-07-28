/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:07:40 by mrybak            #+#    #+#             */
/*   Updated: 2018/01/24 18:07:41 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		hex_digit_len(uintmax_t n)
{
	size_t i;

	i = 1;
	while ((n = n / 16) != 0)
		i++;
	return (i);
}

size_t		oct_digit_len(uintmax_t n)
{
	size_t i;

	i = 1;
	while ((n = n / 8) != 0)
		i++;
	return (i);
}

size_t		print_hex(va_list args, t_settings set)
{
	uintmax_t	nb;
	size_t		len;
	size_t		pers_len;
	size_t		pidrah;

	set.length == h ? nb = (unsigned short int)va_arg(args, int) : 0;
	set.length == hh ? nb = (unsigned char)va_arg(args, int) : 0;
	set.length == l ? nb = (va_arg(args, unsigned long int)) : 0;
	set.length == ll ? nb = (va_arg(args, unsigned long long int)) : 0;
	set.length == j ? nb = (va_arg(args, uintmax_t)) : 0;
	set.length == z ? nb = (va_arg(args, size_t)) : 0;
	set.length == none ? nb = va_arg(args, unsigned int) : 0;
	len = hex_digit_len(nb);
	pers_len = percision_dist(set.ext, len) +
		(set.flags.hashtag != 0 && nb != 0 ? +2 : 0);
	pidrah = extension_hex(set, len, pers_len, nb);
	nb == 0 && set.ext.precision == 0 ? len = 0 : 0;
	return (len + pidrah);
}

size_t		print_oct(va_list args, t_settings set)
{
	uintmax_t	nb;
	size_t		len;
	size_t		pers_len;
	size_t		pidrah;

	if (set.spec == O_octal)
		nb = (va_arg(args, unsigned long int));
	else
	{
		set.length == h ? nb = (unsigned short int)va_arg(args, int) : 0;
		set.length == hh ? nb = (unsigned char)va_arg(args, int) : 0;
		set.length == l ? nb = (va_arg(args, unsigned long int)) : 0;
		set.length == ll ? nb = (va_arg(args, unsigned long long int)) : 0;
		set.length == j ? nb = (va_arg(args, uintmax_t)) : 0;
		set.length == z ? nb = (va_arg(args, size_t)) : 0;
		set.length == none && set.spec == octal
		? nb = va_arg(args, unsigned int) : 0;
	}
	len = oct_digit_len(nb);
	pers_len = percision_dist(set.ext, len) +
		(set.flags.hashtag != 0 && nb != 0 ? +1 : 0);
	pidrah = extension_oct(set, len, pers_len, nb);
	nb == 0 && set.ext.precision == 0
	&& set.flags.hashtag == 0 ? len = 0 : 0;
	return (len + pidrah);
}

size_t		print_pointer(va_list args, t_settings set)
{
	uintmax_t	nb;
	size_t		len;
	size_t		pers_len;

	nb = va_arg(args, unsigned long long);
	len = hex_digit_len(nb);
	pers_len = percision_dist(set.ext, len) + 2;
	extension_handle(set, len, pers_len);
	ft_putstr("0x");
	if (set.flags.zero != 0 && set.flags.minus == 0 && set.ext.width > len
		&& set.ext.width > set.ext.precision)
		put_nchar('0', set.ext.width - pers_len - len);
	if (set.ext.precision > len)
		put_nchar('0', set.ext.precision - len);
	nb == 0 && set.ext.precision != 0 ? ft_putchar('0') : 0;
	hexprint_low(nb);
	if (set.flags.minus != 0 && set.ext.width > len
		&& set.ext.width > set.ext.precision)
		put_nchar(' ', set.ext.width - pers_len - len);
	return (len + pers_len + (set.ext.width > len ? set.ext.width
														- len - pers_len : 0)
			+ (set.ext.precision == 0 && nb == 0 ? -1 : 0));
}
