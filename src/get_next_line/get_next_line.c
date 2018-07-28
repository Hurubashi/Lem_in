/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:13:09 by mrybak            #+#    #+#             */
/*   Updated: 2017/12/06 17:58:38 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*datlist(t_gnl **head, const int fd)
{
	t_gnl *step;

	step = *head;
	while (step != NULL)
	{
		if (step->fd == fd)
		{
			return (step);
		}
		step = step->next;
	}
	step = (t_gnl *)malloc(sizeof(t_gnl));
	step->rdead = ft_strnew(0);
	step->i = 0;
	step->max = 0;
	step->start = 0;
	step->fd = fd;
	step->next = *head;
	*head = step;
	return (step);
}

static char		*copy_that_shit(t_gnl *list)
{
	char	*tmp;

	if (!list->rdead[list->i])
		return (NULL);
	if (list->i >= list->max)
		return (NULL);
	while (list->rdead[list->i] != '\n' && list->rdead[list->i] != '\0'
		&& list->i < list->max)
	{
		list->i++;
	}
	tmp = ft_strsub((list->rdead + list->start), 0, (list->i - list->start));
	list->i++;
	list->start = list->i;
	return (tmp);
}

int				read_it(t_gnl *list)
{
	ssize_t			k;
	char			*str;
	char			*tmp;

	str = ft_strnew(BUFF_SIZE);
	while ((k = read(list->fd, str, BUFF_SIZE)) > 0)
	{
		list->max = list->max + k;
		if (list->rdead == NULL)
			list->rdead = ft_strsub(str, 0, BUFF_SIZE);
		else
		{
			tmp = list->rdead;
			list->rdead = ft_strjoin(list->rdead, str);
			free(tmp);
		}
		if (ft_strchr((list->rdead + list->i), 10) != 0)
			break ;
	}
	free(str);
	if (k < 0)
		return (-1);
	else
		return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*list;

	if ((BUFF_SIZE <= 0) || fd < 0)
		return (-1);
	if (head == NULL)
	{
		head = datlist(&head, fd);
		list = head;
	}
	else
		list = datlist(&head, fd);
	if (read_it(list) == -1)
		return (-1);
	if (list->max == 0)
		return (0);
	if (!(*line = copy_that_shit(list)))
		return (0);
	return (1);
}
