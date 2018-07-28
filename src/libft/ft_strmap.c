/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:37:16 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/11 15:56:00 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (s != NULL && (str = (char*)malloc(ft_strlen(s) + 1)) != NULL)
	{
		while (i < ft_strlen(s))
		{
			str[i] = f((s[i]));
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
