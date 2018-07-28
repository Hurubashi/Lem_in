/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_funcs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 19:38:27 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/22 19:38:29 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		make_links(char **sp)
{
	t_room *rooms;
	t_room *targ1;
	t_room *targ2;

	targ1 = NULL;
	targ2 = NULL;
	rooms = g_rooms;
	while (rooms)
	{
		!(ft_strcmp(sp[0], rooms->name)) ? targ1 = rooms : 0;
		!(ft_strcmp(sp[1], rooms->name)) ? targ2 = rooms : 0;
		rooms = rooms->next;
	}
	free_2dim_array(sp);
	if (targ1 != NULL && targ2 != NULL)
		create_neighbour(targ1, targ2);
	else
		error("Wrong link");
}
