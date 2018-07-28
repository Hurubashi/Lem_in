/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:07:32 by mrybak            #+#    #+#             */
/*   Updated: 2018/01/17 12:07:37 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	initialize_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.hashtag = 0;
	flags.zero = 0;
	return (flags);
}

t_flags	parse_flags(const char *str, t_flags flags)
{
	int	i;

	i = 0;
	while (ALL_SPEC(str[i]) && str[i])
	{
		if (str[i] == '-')
			flags.minus = 1;
		if (str[i] == '+')
			flags.plus = 1;
		if (str[i] == ' ')
			flags.space = 1;
		if (str[i] == '#')
			flags.hashtag = 1;
		if (str[i] == '0' && ft_isdigit(str[i - 1]) != 1
			&& str[i - 1] != '.')
			flags.zero = 1;
		i++;
	}
	return (flags);
}
