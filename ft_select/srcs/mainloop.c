/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:42:01 by tgrange           #+#    #+#             */
/*   Updated: 2017/11/06 16:53:42 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	set_hl(t_lst **lst, int tohl)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (i < tohl)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp->hl)
		tmp->hl = 0;
	else
		tmp->hl = 1;
}

void	set_lst(t_env *env, char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
	{
		env->pos++;
		if (env->pos == env->nb_nodes)
			env->pos = 0;
	}
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
	{
		env->pos--;
		if (env->pos == -1)
			env->pos = env->nb_nodes - 1;
	}
	if (buf[0] == 32 && buf[1] == 0 && buf[2] == 0)
		set_hl(&env->list, env->pos);
}

void	display(t_env *env, t_lst **begin)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = *begin;
	while (tmp)
	{
		if (i == env->pos)
			ft_putstr(tgetstr("us", NULL));
		if (tmp->hl)
			ft_putstr(tgetstr("mr", NULL));
		if (tmp->show)
			ft_putendl(tmp->content);
		ft_putstr(tgetstr("me", NULL));
		ft_putstr(tgetstr("ue", NULL));
		tmp = tmp->next;
		i++;
	}
}

void	mainloop(t_env *env, char *buf)
{
	int		i;

	i = 0;
	while (1)
	{
		system("clear");
		display(env, &env->list);
		bzero(buf, 4);
		read(1, buf, 4);
		set_lst(env, buf);
		i++;
	}
}
