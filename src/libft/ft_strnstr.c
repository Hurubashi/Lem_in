/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 07:46:53 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/07 07:47:00 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)(haystack));
	while (ft_strlen(needle) <= ft_strlen(haystack) && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && i < len)
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
