/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:16:37 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/07 15:16:40 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = (char*)malloc(size)) == NULL)
	{
		return (NULL);
	}
	while (size--)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
