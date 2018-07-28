/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:51:11 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/09 19:59:11 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	size_t			size;
	size_t			i;

	i = 0;
	n < 0 ? (size = ft_countnbr(n) + 1) :
			(size = ft_countnbr(n));
	if ((str = (char*)ft_memalloc(size + 1)) == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
		if (n < -2147483646)
		{
			str[i++] = '2';
			n = n - 2000000000;
		}
	}
	while (i < size--)
	{
		str[size] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
