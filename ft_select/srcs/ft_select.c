/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:33:37 by tgrange           #+#    #+#             */
/*   Updated: 2017/11/06 16:23:28 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	init(struct termios *term, struct termios *saved_term)
{
	char			*name_term;
	
	name_term = NULL;
	name_term = getenv("TERM");
	tgetent(NULL, name_term);
	tcgetattr(0, term);
	tcgetattr(0, saved_term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	tcsetattr(0, 0, term);
}

void	initloop(t_env *env)
{
	char	buf[4];

	mainloop(env, buf);
}

int		main(int ac, char **av)
{
	t_env			*env;

	if (ac == 1)
		error_exit(1, NULL);
	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (1);
	env->list = get_lst(av);
	env->nb_nodes = ac - 1;
	env->pos = 0;
	init(&env->term, &env->saved_term);
	initloop(env);
	tcsetattr(0, 0, &env->saved_term);
	return (0);
}	


	// char			buf[4];
	
	// ft_putendl("buf[0]\tbuf[1]\tbuf[2]\tbuf[3]");
	// while (1)
	// {
	// 	buf[0] = 0;
	// 	buf[1] = 0;
	// 	buf[2] = 0;
	// 	buf[3] = 0;
	// 	read(0, buf, 4);
	// 	if (buf[0] == 27 && buf[1] + buf[2] + buf[3] == 0)
	// 		break ;
	// 	ft_putnbr((int)buf[0]);
	// 	ft_putstr("\t");
	// 	ft_putnbr((int)buf[1]);
	// 	ft_putstr("\t");
	// 	ft_putnbr((int)buf[2]);
	// 	ft_putstr("\t");
	// 	ft_putnbr((int)buf[3]);
	// 	ft_putstr("\t\n");
	// }