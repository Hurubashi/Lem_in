/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:41:38 by mrybak            #+#    #+#             */
/*   Updated: 2018/01/21 17:41:39 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(const char *str, size_t len)
{
	if (str == NULL)
		ft_putstr("(null)");
	write(1, str, len);
}

size_t	u_digit_len(uintmax_t n)
{
	size_t i;

	i = 1;
	while ((n = n / 10) != 0)
	{
		i++;
	}
	return (i);
}

size_t	digit_len(long long n)
{
	size_t i;

	i = 1;
	while ((n = n / 10) != 0)
	{
		i++;
	}
	return (i);
}

size_t	put_nchar(char c, size_t n)
{
	size_t i;

	i = n;
	while (n--)
		write(1, &c, 1);
	return (i);
}

void	ft_put_uintmax_t(uintmax_t n)
{
	uintmax_t nb;

	nb = n;
	if (nb > 9)
	{
		ft_put_uintmax_t(nb / 10);
		ft_put_uintmax_t(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}
