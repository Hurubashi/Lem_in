/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:12:32 by mrybak            #+#    #+#             */
/*   Updated: 2017/12/22 19:25:46 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		print_dat_shit(va_list args, t_settings set)
{
	size_t count;

	count = 0;
	set.spec == s_decimal || set.spec == S_decimal
	? count = print_s_decimal(args, set) : 0;
	set.spec == u_decimal || set.spec == U_decimal
	? count = print_u_decimal(args, set) : 0;
	if (set.spec == letter || set.spec == w_letter)
		count = print_letter(args, set);
	if (set.spec == string && set.length != l)
		count = print_string(args, set);
	if (set.spec == w_string || (set.spec == string && set.length == l))
		count = print_wstring(args, set);
	if (set.spec == hex_l || set.spec == hex_u)
		count = print_hex(args, set);
	set.spec == octal || set.spec == O_octal ? count = print_oct(args, set) : 0;
	set.spec == pointer ? count = print_pointer(args, set) : 0;
	if (set.spec == percent)
		count = print_letter(args, set);
	if (set.spec == invalid)
	{
		ft_putstr("INVALID");
	}
	return (count);
}

void		count_next(const char format, size_t *size)
{
	ft_putchar(format);
	*size = *size + 1;
}

size_t		do_all(const char *format, va_list *args, size_t n)
{
	static t_settings	settings;
	const char			*str;

	settings.strnlen.count = 0;
	while (format[n])
	{
		if (format[n] == '%')
		{
			str = cut_str(format + n + 1);
			settings.flags = initialize_flags();
			settings.flags = parse_flags(str, settings.flags);
			settings.length = parse_length(str, settings.length);
			settings.strnlen.place = len_to_spec(str);
			settings.spec = parse_spec(str[settings.strnlen.place]);
			settings.ext = parse_ext(str, settings.ext);
			free((void*)str);
			settings.strnlen.count = print_dat_shit(*args, settings)
									+ settings.strnlen.count;
			n = n + settings.strnlen.place + 2;
		}
		if (format[n] != '%' && format[n])
			count_next(format[n++], &settings.strnlen.count);
	}
	return (settings.strnlen.count);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		res;

	res = 0;
	if (*format == '\0')
		return (res);
	va_start(ap, format);
	res = do_all(format, &ap, 0);
	va_end(ap);
	return (res);
}
