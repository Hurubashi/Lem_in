/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_oct_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:56:42 by mrybak            #+#    #+#             */
/*   Updated: 2018/01/15 19:56:44 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexprint_low(uintmax_t n)
{
	if (n)
	{
		hexprint_low(n >> 4);
		ft_putchar("0123456789abcdef"[n & 0xf]);
	}
}

void	hexprint_upp(uintmax_t n)
{
	if (n)
	{
		hexprint_upp(n >> 4);
		ft_putchar("0123456789ABCDEF"[n & 0xf]);
	}
}

void	put_octal(intmax_t n)
{
	if (n)
	{
		put_octal(n >> 3);
		ft_putchar("01234567"[n & 0x7]);
	}
}
