/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 11:57:13 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/30 17:24:27 by rburger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include <stdio.h>

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
	int				fnd_e;
	int				vis;
	char			**link;
	int				nrlink;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*rname;
	int				vis;
	int				avail;
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
	int			nr_rooms;
	int			path_pos;
	char		*strt_r;
	char		*end_r;
	char		*gnl;
	char		**path;
	t_input		*input;
	t_ant		*ants;
	t_link		*link;
	t_room		*room;
//	t_path		*path;
}				t_gen;

t_input		*read_input(t_gen *eve);
void		error();
void		find_info(t_gen *all);
t_room		*save_rooms(t_gen *all, char *str, t_room *node);
t_ant		*save_ants(t_gen *all, t_ant *node, int nr);
t_link		*save_link(t_gen *all, char *str, t_link *node, int nr);
void		find_path(t_gen *all);
char		*get_path(t_gen *all, char *pos);

#endif
