/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:43:15 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/08 17:17:21 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s != NULL && (str = (char*)malloc(len + 1)) != NULL)
	{
		while (i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
