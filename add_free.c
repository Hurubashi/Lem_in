/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:51:58 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/09 15:52:12 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lstadd_end(t_list **old, t_list *new)
{
	t_list *tmp;

	tmp = *old;
	if (tmp == NULL)
	{
		new->next = *old;
		*old = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	add_room(t_room **old, t_room *new)
{
	t_room *tmp;

	tmp = *old;
	if (new == NULL)
		return ;
	if (tmp == NULL)
	{
		new->next = *old;
		*old = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	t_list_del(t_list **alst)
{
	t_list *tmp;

	while ((*alst) != NULL)
	{
		tmp = (*alst)->next;
		free((*alst)->content);
		free(*alst);
		(*alst) = NULL;
		(*alst) = tmp;
	}
}

void	t_rooms_del(t_room **alst)
{
	t_room *tmp;

	while ((*alst) != NULL)
	{
		tmp = (*alst)->next;
		free((*alst)->name);
		free(*alst);
		(*alst) = NULL;
		(*alst) = tmp;
	}
}

void	clean_all(void)
{
	t_list_del(&g_map);
	t_rooms_del(&g_rooms);
}
