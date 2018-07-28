/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:12:15 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/08 15:12:17 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (s != NULL && (str = (char*)malloc(ft_strlen(s) + 1)) != NULL)
	{
		while (i < ft_strlen(s))
		{
			str[i] = f(i, (s[i]));
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
