/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:45:51 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/13 16:45:53 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*read_ants(t_list *map)
{
	while (map)
	{
		if (((char*)map->content)[0] != '#')
		{
			g_ant_nb = ft_atoi(map->content);
			if (g_ant_nb <= 0)
				error("No ants");
			map = map->next;
			break ;
		}
		map = map->next;
	}
	return (map);
}

t_list		*read_rooms(t_list *map)
{
	while (g_turn_off == 0 && map)
	{
		if (map->next != NULL &&
			(!(ft_strcmp(map->content, "##start"))
			|| !(ft_strcmp(map->content, "##end"))))
		{
			add_room(&g_rooms, command_choosing(map->content, map));
			map = map->next;
		}
		else if (((char*)map->content)[0] != '#'
			&& ft_strstr(map->content, "-"))
			break ;
		else if (((char*)map->content)[0] != '#')
			add_room(&g_rooms, create_room(map->content));
		map = map->next;
	}
	return (map);
}

t_list		*read_links(t_list *map)
{
	while (g_turn_off == 0 && map)
	{
		if (((char*)map->content)[0] != '#' && ft_strstr(map->content, "-"))
			create_link(map->content);
		map = map->next;
	}
	return (map);
}
