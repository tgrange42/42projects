/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:29:36 by tgrange           #+#    #+#             */
/*   Updated: 2017/11/06 16:22:54 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <stdlib.h>

/*
**	Structs
*/


typedef struct		s_lst
{
	char			*content;
	int				hl;
	int				show;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env
{
	struct s_lst	*list;
	struct termios	term;
	struct termios	saved_term;	
	int				nb_nodes;
	int				pos;
}					t_env;

/*
**	ft_select.c
*/

/*
**	lst_tools.c
*/

t_lst				*get_lst(char **av);
void				free_lst(t_lst **lst);

/*
**	error.c
*/

void				error_exit(int error, t_env *to_free);

/*
**	lst_tools.c
*/

void				free_lst(t_lst **lst);

/*
**	mainloop.c
*/

void				mainloop(t_env *env, char *buf);

#endif
