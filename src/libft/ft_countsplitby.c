/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsplitby.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:25:47 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/09 17:41:38 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_countsplitby(char *str, char c)
{
	size_t	num;
	size_t	i;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
		{
			i++;
		}
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			if (str[i] == c || str[i] == '\0')
			{
				num++;
			}
		}
	}
	return (num);
}
