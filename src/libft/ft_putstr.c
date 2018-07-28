/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:41:45 by mrybak            #+#    #+#             */
/*   Updated: 2017/10/29 13:42:50 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		return (void *)NULL;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (void *)NULL;
}
