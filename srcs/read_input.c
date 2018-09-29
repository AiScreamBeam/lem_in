/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:35:23 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/29 14:48:04 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <stdio.h>

t_input			*read_input(t_gen *eve)
{
	t_input		*head;
	t_input		*node;

	head = NULL; // have to initialise list to NULL first time we use it because reasons.
	while (get_next_line(0, &eve->gnl)) // running gnl fn, assigning info via var eve to gnl inside struct t_gen
	{
		if (head == NULL)
		{
			head = (t_input *)ft_memalloc(sizeof(t_input)); // allocating space for everything that we use in t_input
			node = head; // making node = to head because we 'incriment' using node and head is just the start
		}
		node->str = eve->gnl; // putting value node into value str from struct t_input and making it be equal to
							  // the parameter of this function (eve) and putting that value in gnl from struct t_gen
		//**TESTING**
		ft_putstr("all->gnl: "); // what are we asking the function to do (ask computer what am I telling it to do?) 
		ft_putendl(eve->gnl);
		ft_putstr("node->str: "); // ask computer: " "
		ft_putendl(node->str); 
		node->next = (t_input *)ft_memalloc(sizeof(t_input));
		if (node->str == NULL || (ft_strcmp(node->str, "/0") == 0))
			error();
		node = node->next;
	}
	node->next = NULL; // making the  next instance of node of the same type so that we can have several of them
	return (head);
}
