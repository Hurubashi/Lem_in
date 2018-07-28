/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:51:39 by mrybak            #+#    #+#             */
/*   Updated: 2018/01/17 16:51:40 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_length		parse_length(const char *str, t_length length)
{
	int i;

	i = 0;
	length = 0;
	while (ALL_SPEC(str[i]) && str[i])
	{
		if (str[i] == 'h' && length != h && length < h)
			length = h;
		else if (str[i] == 'h' && length == h)
			length = hh;
		if (str[i] == 'l' && length != l && length < l)
			length = l;
		else if (str[i] == 'l' && length == l)
			length = ll;
		if (str[i] == 'j' && length != z && length < j)
			length = j;
		if (str[i] == 'z' && length < z)
			length = z;
		i++;
	}
	if (length < hh)
		length = none;
	return (length);
}

t_spec			parse_spec(char c)
{
	t_spec spec;

	spec = invalid;
	c == 'd' || c == 'i' ? spec = s_decimal : 0;
	c == 'D' ? spec = S_decimal : 0;
	c == 'u' ? spec = u_decimal : 0;
	c == 'U' ? spec = U_decimal : 0;
	c == 'c' ? spec = letter : 0;
	c == 'C' ? spec = w_letter : 0;
	c == 's' ? spec = string : 0;
	c == 'S' ? spec = w_string : 0;
	c == 'x' ? spec = hex_l : 0;
	c == 'X' ? spec = hex_u : 0;
	c == 'o' ? spec = octal : 0;
	c == 'O' ? spec = O_octal : 0;
	c == 'p' ? spec = pointer : 0;
	c == '%' ? spec = percent : 0;
	return (spec);
}

t_extension		initialize_ext(void)
{
	t_extension ext;

	ext.width = 0;
	ext.precision = 1;
	ext.if_perc = 0;
	return (ext);
}

t_extension		parse_ext(const char *str, t_extension extension)
{
	size_t	i;

	i = 0;
	extension = initialize_ext();
	while (ALL_SPEC(str[i]) && str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			extension.width = ft_atoi(str + i);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		if (str[i] == '.')
		{
			extension.if_perc = 1;
			extension.precision = 0;
			i++;
			if (str[i] >= '0' && str[i] <= '9')
				extension.precision = ft_atoi(str + i);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		i++;
	}
	return (extension);
}

size_t			len_to_spec(const char *format)
{
	size_t i;

	i = 0;
	while (ALL_SPEC(format[i]) && format[i])
		i++;
	return (i);
}
