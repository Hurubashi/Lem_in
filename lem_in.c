/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:25:33 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/01 14:25:44 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**if__room_valid(char *s)
{
	char	**sp;

	sp = ft_strsplit(s, ' ');
	if (tab_size(sp) != 3)
	{
		error("Bad room indentation");
		return (NULL);
	}
	if (!if_nbr(sp[1]) || !if_nbr(sp[2]))
	{
		error("Bad coords");
		return (NULL);
	}
	return (sp);
}

void	check_room(t_room *arr, t_room *cur)
{
	t_room *start;

	if (arr == NULL)
		return ;
	start = arr;
	while (start)
	{
		if (!(ft_strcmp(start->name, cur->name)))
			error("Name used");
		if (start->c_x == cur->c_x && start->c_y == cur->c_y)
			error("Same coords");
		start = start->next;
	}
}

t_room	*create_room(char *s)
{
	char	**sp;
	t_room	*room;

	sp = if__room_valid(s);
	if (g_turn_off == 1)
		return (NULL);
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	room->neighbours = NULL;
	room->name = ft_strdup(sp[0]);
	room->am_ant = 0;
	room->nb_ant = 0;
	room->c_x = ft_atoi(sp[1]);
	room->c_y = ft_atoi(sp[2]);
	room->pos = -1;
	room->used = 0;
	room->next = NULL;
	free_2dim_array(sp);
	check_room(g_rooms, room);
	return (room);
}

t_room	*command_choosing(char *s, t_list *map_elem)
{
	t_room	*start;

	if (!(ft_strcmp(s, "##start")))
	{
		map_elem = map_elem->next;
		if (map_elem == NULL)
			return (NULL);
		if (!(start = create_room(map_elem->content)))
			return (NULL);
		start->pos = 0;
		start->am_ant = g_ant_nb;
		return (start);
	}
	if (!(ft_strcmp(s, "##end")))
	{
		map_elem = map_elem->next;
		if (map_elem == NULL)
			return (NULL);
		if (!(start = create_room(map_elem->content)))
			return (NULL);
		start->pos = -2;
		start->used = 1;
		return (start);
	}
	return (NULL);
}
