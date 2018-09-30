/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 13:16:44 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/30 16:39:57 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*find_start(t_gen *all)
{
	int i;
	char *temp;

	i = 0;
	//	all->path = (char *)ft_memalloc(sizeof(char) * 1000);
	while (all->link->next)
	{
		if (ft_strcmp(all->strt_r, all->link->link[0]) == 0)
		{
			all->path = (char**)ft_memalloc(sizeof(char *) * 100);
			all->path[i] = ft_strdup(all->link->link[0]);
			ft_putstr("all->path[i]: ");
			ft_putendl(all->path[i]);
			i++;
			all->path[i] = ft_strdup(all->link->link[1]);
			ft_putstr("all->path[i]: ");
			ft_putendl(all->path[i]);
			all->link->vis = 1;
			all->path_pos = i;
			return (all->path[i]);
		}
		else if (ft_strcmp(all->strt_r, all->link->link[1]) == 0)
		{
			all->path = (char**)ft_memalloc(sizeof(char *) * 100);
			all->path[i] = ft_strdup(all->link->link[1]);
			ft_putstr("all->path[i]: ");
			ft_putendl(all->path[i]);
			i++;
			all->path[i] = ft_strdup(all->link->link[0]);
			ft_putstr("all->path[i]: ");
			ft_putendl(all->path[i]);
			all->link->vis = 1;
			all->path_pos = i;
			return (all->path[i]);
		}
		all->link = all->link->next;
	}
	return (temp);
	//	error();
	//	return (-1);
	// does error count as a char * return type? Is the error retur nsupposed to be at the end of this specific function?
}

char	*get_path(t_gen *all, char *pos)
{
	if ((ft_strcmp(all->link->link[0], pos) == 0) && (all->link->vis != 1)
			&& (ft_strcmp(all->strt_r, pos) != 0))
	{
		ft_putendl("this is in strcmp(link[0])");
		all->path_pos++;
		all->path[all->path_pos] = all->link->link[1];
		all->link->vis = 1;
		if (ft_strcmp(all->strt_r, all->path[all->path_pos]) != 0)
			return (all->path[all->path_pos]);
		else
		{
			all->path_pos--;
			ft_putstr("print: all->path[all->path_pos--]: ");
			ft_putendl(all->path[all->path_pos]);
			return(pos);
		}
	}
	//	else if (ft_strcmp(all->link->link[0], pos) == 0)
	else if ((ft_strcmp(all->link->link[1], pos) == 0) && (all->link->vis != 1)
			&& (ft_strcmp(all->strt_r, pos) != 0))
	{
		ft_putendl("this is in strcmp(link[1])");
		all->path_pos++;
		all->path[all->path_pos] = all->link->link[0];
		all->link->vis = 1;
		return (all->path[all->path_pos]);
	}
/*
	else if (ft_strcmp(all->end_r, all->path[all->path->pos]) == 0)
	{
		ft_putendl("this is in strcmp(end)");
		return ("finished");
	}
*/
//	return (all->path[all->path_pos]);
	return(pos);
//	error();
	//	return (-1);
	// same with the return type here?
}

int		print_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		ft_putendl(arr[i]);
		i++;
	}
	return (0);
}

void	find_path(t_gen *all)
{
	char	*curr_pos;
	curr_pos = find_start(all);
	ft_putstr("this is curr_pos: ");
	ft_putendl(curr_pos);
	while (all->link->next)
	{
		curr_pos = get_path(all, curr_pos);
		ft_putstr("this is curr_pos2: ");
		ft_putendl(curr_pos);
		if (ft_strcmp(curr_pos, all->end_r) == 0)
		{
			ft_putendl("reached the end");
			break;
		}
		all->link = all->link->next;
	}
	ft_putendl("Printing path: ");
	print_arr(all->path);
/*
	ft_putendl(all->path[0]);
	ft_putendl(all->path[1]);
	ft_putendl(all->path[2]);
	ft_putendl(all->path[3]);
	ft_putendl(all->path[4]);
	ft_putendl(all->path[5]);
	*/
}
