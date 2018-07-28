/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:06:16 by mrybak            #+#    #+#             */
/*   Updated: 2017/10/30 18:06:21 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)(s1 + i)) != *((unsigned char*)(s2 + i)))
		{
			return (*((unsigned char*)(s1 + i)) - *((unsigned char*)(s2 + i)));
		}
		i++;
	}
	return (0);
}
