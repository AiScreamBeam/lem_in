/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 11:57:13 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/29 16:15:01 by rburger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"

typedef struct		s_input
{
	char			*str;
	struct s_input	*next;
}					t_input;

typedef struct		s_ant
{
	char			*aname;
	int				room_nr;
	int				antnr;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_link
{
	char			**link;
	int				nrlink;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*rname;
	int				vis;
	int				ava;
	struct s_room	*next;
}					t_room;

typedef struct		s_path
{
	char			**arr;
	struct s_path	*next;
}					t_path;

typedef struct	s_gen
{
	int			nr_ant;
	char		*strt_r;
	char		*end_r;
	char		*gnl;
	t_input		*input;
	t_ant		*ants;
	t_link		*links;
	t_room		*room;
	t_path		*path;
}				t_gen;

t_input		*read_input(t_gen *eve);
void		error();
void		find_info(t_gen *all);

#endif
