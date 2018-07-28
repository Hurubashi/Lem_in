/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:58:22 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/09 15:58:24 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(char *s)
{
	ft_printf(RED "Error!\n%s\n" RESET, s);
	system("leaks lem_in");
	exit(0);
}

void	print_map(t_list *map)
{
	t_list	*m_head;

	m_head = map;
	while (m_head)
	{
		ft_printf(MAGENTA "%s\n" RESET, m_head->content);
		m_head = m_head->next;
	}
}

int		if_nbr(char *s)
{
	if (!*s)
		return (0);
	while (*s >= '0' && *s <= '9')
		s++;
	if (!*s)
		return (1);
	else
		return (0);
}

int		tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_2dim_array(char **s)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			free(s[i++]);
		free(s);
		s = NULL;
	}
}
