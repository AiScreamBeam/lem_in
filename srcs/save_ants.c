#include "../includes/lemin.h"

t_ant		*save_ants(t_gen *all, t_ant *node, int nr)
{
	t_ant	*head;
	char	*temp;

	head = node;
	if (node == NULL)
	{
		head = (t_ant *)ft_memalloc(sizeof(t_ant));
		node = head;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = (t_ant *)ft_memalloc(sizeof(t_ant));
	node->antnr = nr;
	temp = ft_itoa(nr);
	node->aname = ft_strjoin("L", temp);
	free(temp);
	ft_putstr("node->aname: ");
	ft_putendl(node->aname);
	return (head);
}
