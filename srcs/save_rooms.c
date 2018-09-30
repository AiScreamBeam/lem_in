/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 09:45:49 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/30 13:14:17 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*save_room(char *str)
{
	char	*room;
	size_t		i;

	i = 0;
	while (str[i] != ' ')
		i++;
	room = (char *)ft_memalloc(sizeof(char) * (i + 1));
	ft_strncpy(room, str, i);
	return (room);
}

t_room		*save_rooms(t_gen *all, char *str, t_room *node)
{
	t_room	*head;
	
	head = node; //first time it will be NULL, after this it will be the head node in t_gen all

	if (node == NULL)
	{
		head = (t_room *)ft_memalloc(sizeof(t_room));
		node = head;
	}
	
	while (node->next != NULL)
		node = node->next; // get to end of current list so that we can add a new node.
	node->next = (t_room *)ft_memalloc(sizeof(t_room));
	node->rname = save_room(str);
	ft_putstr("this is node->rname: ");
	ft_putendl(node->rname);

	return (head);
}
