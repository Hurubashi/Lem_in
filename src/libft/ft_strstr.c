/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:50:37 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/03 14:40:54 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)(haystack));
	while (haystack[i] && ft_strlen(needle) <= ft_strlen(haystack))
	{
		j = 0;
		while (haystack[i] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)(haystack + i - j));
			j++;
			i++;
			if (haystack[i] != needle[j])
			{
				i = i - j;
				break ;
			}
		}
		i++;
	}
	return (NULL);
}
