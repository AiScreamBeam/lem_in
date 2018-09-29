#include "lem_in.h"
#include <stdio.h>

t_input			*insert_file(t_g *all)
{
	t_input		*head;
	t_input		*node;

	head = NULL;
	while (get_next_line(0, &all->gnl))
	{
		if (head == NULL)
		{
			head = (t_input *)ft_memalloc(sizeof(t_input));
			node = head;
		}
		node->str = all->gnl;
		ft_putstr("all->gnl: ");
		ft_putendl(all->gnl); // ask computer: what am i telling you to do?
		ft_putstr("node->str: ");
		ft_putendl(node->str); // ask computer: "                      "?
		node->next = (t_input *)ft_memalloc(sizeof(t_input));
		if (node->str == NULL || (ft_strcmp(node->str, "\0") == 0))
			error();
		node = node->next;
	}
	node->next = NULL;
	return (head);
}
