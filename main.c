/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:01:42 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/09 12:04:08 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lead_to_end(t_neigh *q, t_room *start, t_room *end)
{
	t_neigh *qh;
	t_room	*tmp;
	int		ants;
	int		i;

	i = 1;
	ants = start->am_ant;
	qh = q;
	while (end->am_ant != ants)
	{
		if (!qh)
		{
			qh = q;
			if (tmp->pos != -2)
			{
				g_end_used++;
				ft_printf("\n");
			}
		}
		tmp = qh->ng;
		if (tmp->used >= 0)
			i += move_ants(end, tmp->used, i, start->am_ant);
		qh = qh->next;
	}
	ft_printf(GREEN "\n\nTotal turns : %d\n" RESET, g_end_used);
}

int		short_way(t_neigh **q)
{
	t_neigh	*qh;
	t_room	*tmp;
	int		len;

	qh = *q;
	tmp = qh->ng;
	len = tmp->pos;
	while (qh)
	{
		if (len > tmp->pos)
			len = tmp->pos;
		qh = qh->next;
	}
	qh = *q;
	while (qh)
	{
		if (len == tmp->pos)
			return (tmp->used);
		qh = qh->next;
	}
	return (0);
}

void	t_neigh_del(t_neigh **q)
{
	t_neigh *tmp;

	while ((*q) != NULL)
	{
		tmp = (*q)->next;
		free(*q);
		(*q) = NULL;
		(*q) = tmp;
	}
}

void	solve(void)
{
	t_room	*start;
	t_room	*end;
	t_neigh	*q;

	q = NULL;
	start = find_start();
	create_way_list(start, &q);
	g_start_used = short_way(&q);
	end = find_end();
	g_end_used = 1;
	lead_to_end(q, start, end);
	t_neigh_del(&q);
}

int		main(void)
{
	t_list	*map;
	t_room	*slave;

	g_rooms = NULL;
	map = map_creation();
	map = read_ants(map);
	map = read_rooms(map);
	map = read_links(map);
	find_path();
	way_back();
	print_map(g_map);
	ft_printf("\n");
	g_phase = 0;
	solve();
	ft_printf(GREEN "Total moves : %d\n" RESET, g_phase);
	slave = g_rooms;
	if (g_turn_off > 0)
		clean_all();
}
