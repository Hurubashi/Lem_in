/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_handl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:15:15 by mrybak            #+#    #+#             */
/*   Updated: 2018/02/05 17:15:20 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		extension_handle(t_settings settings, size_t len, size_t pers_len)
{
	if (settings.flags.minus == 0)
	{
		if (settings.flags.zero == 0)
		{
			if (settings.ext.width > len
				&& settings.ext.width > settings.ext.precision)
				put_nchar(' ', settings.ext.width - pers_len - len);
		}
		if (settings.flags.zero != 0)
		{
			if (settings.ext.width > len
				&& settings.ext.width > settings.ext.precision
				&& settings.ext.precision != 0)
				put_nchar(' ', settings.ext.width - pers_len - len);
			else if (settings.ext.width > len
					&& settings.ext.width > settings.ext.precision)
				put_nchar('0', settings.ext.width - pers_len - len);
		}
	}
}

size_t		extension_usigned(t_settings set, size_t len,
								size_t pers_len, intmax_t nb)
{
	size_t	ext_count;

	ext_count = 0;
	if (set.flags.minus == 0)
	{
		if (set.ext.if_perc == 1 && set.ext.width > len
			&& set.ext.width > set.ext.precision)
			ext_count += put_nchar(' ', set.ext.width - pers_len - len);
		else if (set.flags.zero == 0 && set.ext.width > len
				&& set.ext.width > set.ext.precision)
			ext_count += put_nchar(' ', set.ext.width - pers_len - len);
	}
	if (set.flags.zero != 0 && set.flags.minus == 0
		&& set.ext.if_perc != 1)
		if (set.ext.width > len
			&& set.ext.width > set.ext.precision)
			ext_count += put_nchar('0', set.ext.width - pers_len - len);
	if (set.ext.precision >= len)
		ext_count += put_nchar('0', set.ext.precision - len);
	if (nb != 0 || set.ext.precision != 0)
		ft_put_uintmax_t(nb);
	if (set.flags.minus != 0 && set.ext.width > len
		&& set.ext.width > set.ext.precision)
		ext_count += put_nchar(' ', set.ext.width - pers_len - len);
	return (ext_count);
}

size_t		extension_dec(t_settings set, size_t len,
									size_t p, intmax_t nb)
{
	set.strnlen.place != 0 ? set.strnlen.place = 0 : 0;
	if (set.flags.minus == 0)
	{
		if (set.ext.if_perc == 1 && set.ext.width > len
			&& set.ext.width > set.ext.precision)
			set.strnlen.place += put_nchar(' ', set.ext.width - p - len);
		else if (set.flags.zero == 0 && set.ext.width > len
				&& set.ext.width > set.ext.precision)
			set.strnlen.place += put_nchar(' ', set.ext.width - p - len);
	}
	set.flags.plus != 0 && nb >= 0 ? set.strnlen.place += put_nchar('+', 1) : 0;
	nb < 0 && nb >= -9223372036854775807
	? set.strnlen.place += put_nchar('-', 1) : 0;
	nb <= -9223372036854775807 ? set.strnlen.place += 1 : 0;
	nb < 0 ? nb = nb * -1 : 0;
	if (set.flags.zero != 0 && set.flags.minus == 0 && set.ext.if_perc != 1)
		if (set.ext.width > len && set.ext.width > set.ext.precision)
			set.strnlen.place += put_nchar('0', set.ext.width - p - len);
	if (set.ext.precision >= len)
		set.strnlen.place += put_nchar('0', set.ext.precision - len);
	nb != 0 || set.ext.precision != 0 ? ft_putnbr(nb) : 0;
	if (set.flags.minus != 0 && set.ext.width > len
		&& set.ext.width > set.ext.precision)
		set.strnlen.place += put_nchar(' ', set.ext.width - p - len);
	return (set.strnlen.place);
}

size_t		extension_hex(t_settings s, size_t len,
								size_t pers_len, uintmax_t nb)
{
	size_t ext_count;

	ext_count = 0;
	if (s.flags.minus == 0 && s.flags.zero == 0)
	{
		if (s.ext.width > len && s.ext.width > s.ext.precision)
			ext_count += put_nchar(' ', s.ext.width - pers_len - len
							+ (s.ext.precision == 0 && nb == 0 ? 1 : 0));
	}
	s.spec == hex_l && nb != 0 && s.flags.hashtag != 0 ? ft_putstr("0x") : 0;
	s.spec == hex_u && nb != 0 && s.flags.hashtag != 0 ? ft_putstr("0X") : 0;
	if (s.flags.zero != 0 && s.flags.minus == 0 && s.ext.width > len
		&& s.ext.width > s.ext.precision)
		ext_count += put_nchar('0', s.ext.width - pers_len - len);
	if (s.ext.precision > len)
		ext_count += put_nchar('0', s.ext.precision - len);
	nb == 0 && s.ext.precision != 0 ? ft_putchar('0') : 0;
	nb != 0 && s.flags.hashtag != 0 ? ext_count += 2 : 0;
	s.spec == hex_l ? hexprint_low(nb) : 0;
	s.spec == hex_u ? hexprint_upp(nb) : 0;
	if (s.flags.minus != 0 && s.ext.width > len
		&& s.ext.width > s.ext.precision)
		ext_count += put_nchar(' ', s.ext.width - pers_len - len);
	return (ext_count);
}

size_t		extension_oct(t_settings set, size_t len,
								size_t pers_len, uintmax_t nb)
{
	size_t ext_count;

	ext_count = 0;
	if (set.flags.minus == 0 && set.flags.zero == 0)
	{
		if (set.ext.width > len
			&& set.ext.width > set.ext.precision)
			ext_count += put_nchar(' ', set.ext.width - pers_len - len
							+ (set.ext.precision == 0 && nb == 0 ? 1 : 0));
	}
	if (set.flags.hashtag != 0 && set.ext.precision <= len)
		ft_putchar('0');
	if (set.flags.zero != 0 && set.flags.minus == 0 && set.ext.width > len
		&& set.ext.width > set.ext.precision)
		ext_count += put_nchar('0', set.ext.width - pers_len - len);
	if (set.ext.precision > len)
		ext_count += put_nchar('0', set.ext.precision - len);
	nb == 0 && set.ext.precision != 0
	&& set.flags.hashtag == 0 ? ft_putchar('0') : 0;
	nb != 0 && set.flags.hashtag != 0 ? ext_count += 1 : 0;
	put_octal(nb);
	if (set.flags.minus != 0 && set.ext.width > len
		&& set.ext.width > set.ext.precision)
		ext_count += put_nchar(' ', set.ext.width - pers_len - len);
	return (ext_count);
}
