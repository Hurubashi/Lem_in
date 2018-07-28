/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:34:14 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/08 20:15:42 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	end;
	size_t	j;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && s[i] != '\0')
		end--;
	end = end + 1;
	if (s != NULL && (str = (char*)malloc(end - i + 1)) != NULL)
	{
		while (i < end)
			str[j++] = s[i++];
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
