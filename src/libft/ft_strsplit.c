/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:50:02 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/09 11:42:50 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	k;

	str = NULL;
	i = 0;
	k = 0;
	if (s == NULL || (str = (char**)malloc(sizeof(char*) *
		(ft_countsplitby((char*)s, c) + 1))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			str[k++] = ft_strsub(s, i, j);
			i = i + j - 1;
		}
		i++;
	}
	str[k] = 0;
	return (str);
}
