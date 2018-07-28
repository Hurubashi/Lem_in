/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:46:12 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/13 16:46:14 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	neigh_add(t_neigh **alst, t_neigh *new)
{
	if (new != NULL || (*alst) != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	add_neigh_toend(t_neigh **old, t_neigh *new)
{
	t_neigh *tmp;

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

t_neigh	*new_neighbour(void *content)
{
	t_neigh	*newlist;

	if (!(newlist = (t_neigh*)malloc(sizeof(t_neigh*))))
		return (NULL);
	if (content == NULL)
		newlist->ng = NULL;
	else
		newlist->ng = content;
	newlist->next = NULL;
	return (newlist);
}

void	create_neighbour(t_room *targ1, t_room *targ2)
{
	t_neigh *tmp;

	tmp = targ1->neighbours;
	while (tmp)
	{
		if (tmp->ng == targ2 || targ1 == targ2)
			return ;
		tmp = tmp->next;
	}
	if (targ1->neighbours == NULL)
		targ1->neighbours = new_neighbour(targ2);
	else
		neigh_add(&targ1->neighbours, new_neighbour(targ2));
	if (targ2->neighbours == NULL)
		targ2->neighbours = new_neighbour(targ1);
	else
		neigh_add(&targ2->neighbours, new_neighbour(targ1));
}

void	create_link(char *s)
{
	char **sp;

	sp = ft_strsplit(s, '-');
	if (tab_size(sp) != 2)
	{
		error("Bad Link indentation");
		return ;
	}
	if (ft_strstr(sp[0], sp[1]))
	{
		free_2dim_array(sp);
		return ;
	}
	make_links(sp);
}
