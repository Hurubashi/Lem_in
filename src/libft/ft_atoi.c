/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:28:51 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/11 16:34:36 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	long long int	nb;
	int				neg;

	i = 0;
	nb = 0;
	neg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (nb > 922337203685477580 && neg != -1)
			return (-1);
		else if (nb > 922337203685477580 && neg == -1)
			return (0);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (neg == -1)
		return (-nb);
	return (nb);
}
