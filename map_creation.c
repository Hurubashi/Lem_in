/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:45:34 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/09 15:45:35 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*ft_lstnew_str(void const *content, size_t content_size)
{
	t_list	*newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = ft_strdup(content);
		if (newlist->content == NULL)
			return (NULL);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}

void	check_start_end(char *s)
{
	if (ft_strstr(s, "##"))
	{
		g_start_used == 1 && !(ft_strcmp(s, "##start"))
		? error("Double start forbidden") : 0;
		g_end_used == 1 && !(ft_strcmp(s, "##end"))
		? error("Double end forbidden") : 0;
		!(ft_strcmp(s, "##start")) ? g_start_used = 1 : 0;
		!(ft_strcmp(s, "##end")) ? g_end_used = 1 : 0;
		(g_start_used || g_end_used) && g_phase == 0
		? error("No ants before start/end") : 0;
	}
}

void	check_liks(char *s)
{
	if (ft_strstr(s, "-"))
	{
		s[0] != '#' ? g_phase = 2 : 0;
		s[0] != '#' && !g_turn_off && (!g_start_used || !g_end_used || !g_phase)
		? error("Links before start/end or ants declaration") : 0;
	}
}

int		map_reading_error(char *s)
{
	g_phase < 2 ? check_start_end(s) : 0;
	check_liks(s);
	s[0] == '\0' && g_phase != 2 ? error("Empty lines forbidden") : 0;
	if (g_phase == 1 && if_nbr(s))
		error("Double declaration of ant number forbidden");
	else if (g_turn_off == 0 && s[0] != '#' && g_phase == 0)
		g_phase == 0 && if_nbr(s) ? g_phase = 1 : error("No ants");
	if (g_turn_off == 1 || s[0] == '\0'
		|| (g_phase == 2 && !ft_strstr(s, "-") && s[0] != '#'))
	{
		s != NULL ? free(s) : 0;
		return (1);
	}
	else
		return (0);
}

t_list	*map_creation(void)
{
	char	*s;
	t_list	*map;
	t_list	*tmp;

	map = NULL;
	while (g_turn_off <= 0 && get_next_line(0, &s))
	{
		if (!(ft_strcmp(s, "##")) &&
				(ft_strcmp(s, "##start") && ft_strcmp(s, "##end")))
			free(s);
		else if (map_reading_error(s))
			break ;
		else
		{
			tmp = ft_lstnew_str(s, ft_strlen(s));
			ft_lstadd_end(&map, tmp);
			free(s);
		}
	}
	g_map = map;
	(g_start_used != 1 || g_end_used != 1) && g_turn_off == 0
	? error("Should be both start/end") : 0;
	g_phase != 2 ? error("Map should have at least one Link") : 0;
	return (map);
}
