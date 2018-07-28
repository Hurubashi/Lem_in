/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:56:58 by mrybak            #+#    #+#             */
/*   Updated: 2018/01/23 15:57:00 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_wstring(wchar_t *str, size_t stop)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return ;
	}
	while (str[i] && stop--)
	{
		print_wchar(str[i]);
		i++;
	}
}

size_t		go_tbmemery(wchar_t *str, size_t stop)
{
	size_t	i;
	size_t	size;
	wchar_t	c;

	i = 0;
	size = 0;
	while (str[i] && stop > size)
	{
		c = str[i];
		size += wchar_len(c);
		i++;
	}
	if (size > stop)
		size -= wchar_len(c);
	return (size);
}

size_t		count_wchars(wchar_t *str, size_t stop)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (str[i] && stop >= size)
	{
		size += wchar_len(str[i]);
		if (size > stop)
			break ;
		i++;
	}
	return (i);
}

size_t		print_wstring(va_list args, t_settings set)
{
	wchar_t	*wstr;
	size_t	len;
	size_t	count;

	count = 0;
	len = 6;
	wstr = va_arg(args, wchar_t *);
	wstr != NULL ? len = wstr_len(wstr) : 0;
	if (wstr != NULL)
	{
		set.ext.precision != 1
		? len = go_tbmemery(wstr, set.ext.precision) : 0;
		count = count_wchars(wstr, len);
		set.flags.minus == 0 && set.flags.zero != 0 && set.ext.width > len
		? put_nchar('0', set.ext.width - len) : 0;
		set.flags.minus == 0 && set.ext.width > len && set.flags.zero == 0
		? put_nchar(' ', set.ext.width - len) : 0;
	}
	put_wstring(wstr, count);
	set.flags.minus != 0 && set.ext.width > len &&
	set.flags.zero == 0 ? put_nchar(' ', set.ext.width - len) : 0;
	return (len + (set.ext.width > len
		? set.ext.width - len : 0));
}

size_t		print_string(va_list args, t_settings set)
{
	char	*str;
	size_t	len;

	str = va_arg(args, char *);
	if (str != NULL)
		len = ft_strlen(str);
	else
		len = 6;
	if (str != NULL)
	{
		set.ext.precision != 1 && set.ext.precision < len
		? len = set.ext.precision : 0;
		if (set.flags.minus == 0)
		{
			if (set.flags.zero != 0 && set.ext.width > len)
				put_nchar('0', set.ext.width - len);
			if (set.ext.width > len && set.flags.zero == 0)
				put_nchar(' ', set.ext.width - len);
		}
	}
	ft_putnstr(str, len);
	if (set.flags.minus != 0)
		if (set.ext.width > len && set.flags.zero == 0)
			put_nchar(' ', set.ext.width - len);
	return (len + (set.ext.width > len ? set.ext.width - len : 0));
}
