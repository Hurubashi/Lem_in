/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:01:08 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/22 14:01:14 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		color_print(int nb, char *s2, int i)
{
	if (i == 0)
		ft_printf(MAGENTA "L%d-%s ", nb, s2);
	if (i == 1)
		ft_printf(BLUE "L%d-%s ", nb, s2);
	if (i == 2)
		ft_printf(CYAN "L%d-%s ", nb, s2);
	if (i == 3)
		ft_printf(GREEN "L%d-%s ", nb, s2);
	if (i == 4)
		ft_printf(YELLOW "L%d-%s ", nb, s2);
	if (i == 5)
		ft_printf(RED "L%d-%s ", nb, s2);
	g_phase++;
}

t_room		*find_start(void)
{
	t_room	*rm;

	rm = g_rooms;
	while (rm && rm->pos != 0)
		rm = rm->next;
	if (!rm)
		error("No Start!");
	return (rm);
}

void		create_way_list(t_room *room, t_neigh **q)
{
	t_neigh	*cq;
	t_room	*tmp;

	tmp = room;
	cq = tmp->neighbours;
	while (cq)
	{
		tmp = cq->ng;
		if (tmp->pos == -2 || tmp->used > 1)
		{
			if (!q)
				*q = new_neighbour(tmp);
			else
				add_neigh_toend(q, new_neighbour(cq->ng));
		}
		cq = cq->next;
	}
	if (!(*q))
	{
		error("No Way Found");
	}
}

t_room		*find_track(t_room *current, int track)
{
	t_neigh *ng;
	t_room	*tmp;
	int		pos;

	if (current->pos != -2)
		pos = current->pos;
	else
		pos = 0;
	ng = current->neighbours;
	while (ng)
	{
		tmp = ng->ng;
		if (tmp->used == 0 && tmp->pos == 0)
			return (tmp);
		else if (tmp->pos == (pos + 1) && tmp->used == track)
			return (tmp);
		ng = ng->next;
	}
	return (NULL);
}

int			move_ants(t_room *end, int track, int ant_nb, int am_ant)
{
	t_room	*cp;
	t_room	*prev;

	cp = end;
	prev = cp;
	while ((cp = find_track(cp, track)))
	{
		if (cp->am_ant > 0 && (prev->am_ant == 0 || prev->pos == -2))
		{
			if (cp->pos == 0 && (am_ant + 1) < prev->pos
				&& track != g_start_used)
				return (0);
			cp->pos == 0 ? cp->nb_ant = ant_nb : 0;
			prev->nb_ant = cp->nb_ant;
			prev->am_ant += 1;
			cp->am_ant -= 1;
			color_print(prev->nb_ant, prev->name, track % 6);
		}
		if (cp->used == 0)
			return (1);
		prev = cp;
	}
	return (0);
}
