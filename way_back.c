/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:10:18 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/19 19:10:20 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			find_cost(t_room *room)
{
	t_neigh	*cq;
	t_room	*tmp;
	int		cost;

	cq = room->neighbours;
	if (!cq)
		return (0);
	cost = 0;
	while (cq)
	{
		tmp = cq->ng;
		if (tmp->pos == 0)
			return (0);
		if (cost == 0 && tmp->used < 2 && tmp->pos != -1 && tmp->pos != -2)
			cost = tmp->pos;
		if (tmp->pos != -2 && tmp->pos < cost
			&& tmp->used != -1 && tmp->used < 2)
			cost = tmp->pos;
		cq = cq->next;
	}
	return (cost);
}

t_room		*add_step(t_room **rm)
{
	t_room	*tmp;
	t_neigh	*q;
	int		cost;

	q = (*rm)->neighbours;
	cost = find_cost(*rm);
	while (q)
	{
		tmp = q->ng;
		if (tmp->pos == 0)
			return (NULL);
		if (tmp->pos == cost && tmp->used < 2)
			return (tmp);
		q = q->next;
	}
	return (NULL);
}

t_room		*find_end(void)
{
	t_room	*rm;

	rm = g_rooms;
	while (rm && rm->pos != -2)
		rm = rm->next;
	if (!rm)
		error("No End!");
	return (rm);
}

void		way_back(void)
{
	t_room	*rm;
	t_room	*tmp;
	int		used;
	int		l;

	rm = find_end();
	used = 2;
	while (1)
	{
		if (!(tmp = add_step(&rm)))
			return ;
		l = 1;
		tmp->pos = 1;
		tmp->used = used;
		while ((tmp = add_step(&tmp)))
		{
			l++;
			tmp->pos = l;
			tmp->used = used;
		}
		used++;
	}
}
