#include "../includes/lemin.h"

void	save_start(t_gen *all, t_input *node)
{
	all->strt_r = ft_strsplit(node->str, ' ')[0];
	ft_putstr("This is all->strt_r: ");
	ft_putendl(all->strt_r);
}

void	save_end(t_gen *all, t_input *node)
{
	all->end_r = ft_strsplit(node->str, ' ')[0];
	ft_putstr("This is all->end_r: ");
	ft_putendl(all->end_r);
}

void	find_info(t_gen *all)
{
	int		sflag, eflag;
	t_input *head;
	t_input *node;

	sflag = eflag = 1;
	head = all->input;
	node = all->input;

	int test = ft_atoi(all->input->str);
	if (test)
	{
		all->nr_ant = test;
		ft_putstr("this is all->nr_ant: ");
		ft_putnbr(all->nr_ant);
		ft_putchar('\n');
	}
	else
		error();

	while (node->next)
	{
		if (ft_strcmp("##start", node->str) == 0 && sflag == 1)
		{
			node = node->next;
			ft_putendl(node->str);
			save_start(all, node);
			node = head;
			sflag = -1;
		}
		else if (ft_strcmp("##end", node->str) == 0 && eflag == 1)
		{
			node = node->next;
			ft_putendl(node->str);
			save_end(all, node);
			node = head;
			eflag = -1;
		}
		//else if ()

		//ft_putendl(node->str);
		node = node->next;
	}
}
