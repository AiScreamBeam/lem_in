/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 09:44:27 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/30 14:00:08 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_link		*save_link(t_gen *all, char *str, t_link *node, int nr)
{
	t_link	*head;
	char *temp;
	int len;

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
	node->link = ft_strsplit(str, '-');

	ft_putstr("this is node->link[0]: ");
	ft_putendl(node->link[0]);
	ft_putstr("this is node->link[1]: ");
	ft_putendl(node->link[1]);
	node->nrlink = nr;
	ft_putstr("node->nrlink: ");
	ft_putnbr(node->nrlink);
	ft_putchar('\n');
	//copy node string into node link
	return (head);
}
