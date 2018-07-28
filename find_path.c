/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:56:00 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/16 14:56:05 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			add_to_queue(t_room *room, t_neigh **q)
{
	t_neigh	*cq;
	t_room	*tmp;

	tmp = room;
	cq = tmp->neighbours;
	if (!cq)
		return (0);
	while (cq)
	{
		tmp = cq->ng;
		if (tmp->pos == -1)
		{
			if (!q)
				*q = new_neighbour(tmp);
			else
				add_neigh_toend(q, new_neighbour(cq->ng));
		}
		cq = cq->next;
	}
	return (1);
}

t_neigh		*del_from_queue(t_neigh *q)
{
	t_neigh *cq;
	t_room	*tmp;

	cq = q;
	tmp = cq->ng;
	while (cq && tmp->pos != -1)
	{
		tmp = cq->ng;
		if (tmp->pos != -1)
		{
			q = cq->next;
			free(cq);
			cq = q;
		}
		else
			break ;
	}
	return (q);
}

void		mark_road(t_neigh **q, int l)
{
	t_neigh	*cq;
	t_room	*tmp;

	cq = *q;
	while (cq)
	{
		tmp = cq->ng;
		if (tmp->used == 0)
			tmp->used = 1;
		if (tmp->pos == 0)
			return ;
		tmp->pos != -2 ? tmp->pos = l : 0;
		cq = cq->next;
	}
}

void		refill_queue(t_neigh **q)
{
	t_neigh	*cq;
	t_room	*tmp;

	cq = *q;
	while (cq)
	{
		tmp = cq->ng;
		if (tmp->pos != -1 && tmp->used == 1)
			add_to_queue(tmp, q);
		cq = cq->next;
	}
}

void		find_path(void)
{
	t_room	*rm;
	t_neigh	*q;
	int		l;

	q = NULL;
	l = 1;
	rm = g_rooms;
	while (rm && rm->pos != 0)
		rm = rm->next;
	if (!(add_to_queue(rm, &q)))
	{
		error("No Way to Go!");
		return ;
	}
	while (q)
	{
		mark_road(&q, l);
		refill_queue(&q);
		q = del_from_queue(q);
		l++;
	}
}
