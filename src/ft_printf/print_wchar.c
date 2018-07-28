/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:46:53 by mrybak            #+#    #+#             */
/*   Updated: 2018/01/23 15:46:55 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_wchar(void *c, size_t size)
{
	write(1, c, size);
}

void	print_wchar(wint_t c)
{
	char wint[4];

	if (c <= 0x7F)
		ft_put_wchar(&c, 1);
	else if (c <= 0x7FF)
	{
		wint[0] = (((c & 0x07c0) >> 6) + 0xc0);
		wint[1] = ((c & 0x003F) + 0x80);
		ft_put_wchar(wint, 2);
	}
	else if (c <= 0xFFFF)
	{
		wint[0] = (((c & 0xF000) >> 12) + 0xE0);
		wint[1] = (((c & 0x0Fc0) >> 6) + 0x80);
		wint[2] = ((c & 0x003F) + 0x80);
		ft_put_wchar(wint, 3);
	}
	else if (c <= 0x10FFFF)
	{
		wint[0] = (((c & 0x1c0000) >> 18) + 0xF0);
		wint[1] = (((c & 0x03F000) >> 12) + 0x80);
		wint[2] = (((c & 0x0Fc0) >> 6) + 0x80);
		wint[3] = ((c & 0x003F) + 0x80);
		ft_put_wchar(wint, 4);
	}
}

size_t	wstr_len(const int *str)
{
	int		i;
	size_t	size;

	size = 0;
	i = 0;
	if ((int)str[i] == 0)
		return (0);
	while (str[i])
	{
		if (str[i] <= 0x7F)
			size += 1;
		else if (str[i] <= 0x7FF)
			size += 2;
		else if (str[i] <= 0xFFFF)
			size += 3;
		else if (str[i] <= 0x10FFFF)
			size += 4;
		i++;
	}
	return (size);
}

size_t	wchar_len(int c)
{
	size_t	size;

	if (!c)
		return (0);
	size = 0;
	if (c <= 0x7F)
		size += 1;
	else if (c <= 0x7FF)
		size += 2;
	else if (c <= 0xFFFF)
		size += 3;
	else if (c <= 0x10FFFF)
		size += 4;
	return (size);
}
