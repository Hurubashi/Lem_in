/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:33:39 by mrybak            #+#    #+#             */
/*   Updated: 2018/03/01 13:33:54 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "src/libft/libft.h"
# include "src/ft_printf/ft_printf.h"
# include "src/get_next_line/get_next_line.h"

typedef struct		s_neigh
{
	void			*ng;
	struct s_neigh	*next;
}					t_neigh;

typedef struct		s_room
{
	t_neigh			*neighbours;
	char			*name;
	int				am_ant;
	int				nb_ant;
	int				c_x;
	int				c_y;
	int				pos;
	int				used;
	struct s_room	*next;
}					t_room;

t_list				*g_map;
t_room				*g_rooms;
int					g_turn_off;
int					g_ant_nb;
int					g_phase;
int					g_start_used;
int					g_end_used;

t_list				*read_links(t_list *map);
t_list				*read_rooms(t_list *map);
t_list				*read_ants(t_list *map);
t_room				*command_choosing(char *s, t_list *map_elem);
t_room				*create_room(char *s);
t_list				*map_creation();
void				add_room(t_room **old, t_room *new);
void				ft_lstadd_end(t_list **old, t_list *new);
void				add_neigh_toend(t_neigh **old, t_neigh *new);
t_list				*ft_lstnew_str(void const *content, size_t content_size);
void				error(char *s);
void				print_map(t_list *map);
int					if_nbr(char *s);
int					tab_size(char **tab);
void				free_2dim_array(char **s);
t_neigh				*new_neighbour(void *content);
void				create_neighbour(t_room *targ1, t_room *targ2);
void				create_link(char *s);
void				find_path();
void				way_back();
t_room				*find_end();
t_room				*find_start();
void				create_way_list(t_room *room, t_neigh **q);
int					move_ants(t_room *end, int track, int ant_nb, int am_ant);
void				clean_all();
void				t_neigh_del(t_neigh **q);
void				t_list_del(t_list **alst);
void				make_links(char **sp);

#endif
