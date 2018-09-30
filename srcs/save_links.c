/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 09:44:27 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/30 11:37:29 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_link		*save_link(t_gen *all, char *str, t_link *node, int nr)
{
	t_link	*head;

	head = node; // where does the node paramater that we feed into function intiailly come from? Is it the next stuff from
				 // the whole t_link struct?
				 // it comes from the find_info function?
	if (node == NULL)
	{
		head = (t_link *)ft_memalloc(sizeof(t_link));
		node = head;
	}
	while (node->next != NULL) // link is the string name
	   	node  = node->next;
	node->next = (t_link *)ft_memalloc(sizeof(t_link)); // allocating memory for the whole struct
	node->link = (char *)ft_memalloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strncpy(node->link, str, (ft_strlen(str) + 1));
	ft_putstr("this is node->link: ");
	ft_putendl(node->link);
	node->nrlink = nr;
	//copy node string into node link
	return (head);
}
