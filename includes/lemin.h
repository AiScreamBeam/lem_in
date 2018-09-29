/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 11:57:13 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/29 14:13:25 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"

typedef struct	s_gen
{
	int			nr_ant;
	char		*strt_r;
	char		*end_r;
	char		*gnl;
	t_input		input;
	t_ant		ants;
	t_link		links;
	t_room		room;
}				t_gen;

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

#endif