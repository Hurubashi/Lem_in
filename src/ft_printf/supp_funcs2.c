/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:40:46 by mrybak            #+#    #+#             */
/*   Updated: 2018/01/23 18:40:48 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	percision_dist(t_extension ext, size_t len)
{
	size_t	i;

	i = ext.precision;
	if (ext.precision > len)
		i = ext.precision - len;
	else
		i = 0;
	return (i);
}

char	*cut_str(const char *format)
{
	char	*str;
	size_t	i;

	str = malloc(len_to_spec(format) + 2);
	i = 0;
	while (format[i] && ALL_SPEC(format[i]))
	{
		str[i] = format[i];
		i++;
	}
	str[i] = format[i];
	str[i + 1] = '\0';
	return (str);
}
