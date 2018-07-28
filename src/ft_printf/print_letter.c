/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:12:06 by mrybak            #+#    #+#             */
/*   Updated: 2018/02/06 11:12:13 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		print_letter(va_list args, t_settings settings)
{
	wchar_t	c;
	size_t	len;

	if (settings.spec == percent)
		c = '%';
	if (settings.spec == letter || settings.spec == w_letter)
		c = (char)va_arg(args, int);
	len = wchar_len(c);
	c == '\0' ? len = 1 : 0;
	if (settings.flags.minus == 0)
	{
		if (settings.flags.zero != 0 && settings.ext.width > len)
			put_nchar('0', settings.ext.width - len);
		if (settings.ext.width > len && settings.flags.zero == 0)
			put_nchar(' ', settings.ext.width - len);
	}
	ft_putchar(c);
	if (settings.flags.minus != 0)
	{
		if (settings.ext.width > len && settings.flags.zero == 0)
			put_nchar(' ', settings.ext.width - len);
	}
	return (len + (settings.ext.width > len
				? settings.ext.width - len : 0));
}
