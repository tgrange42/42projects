/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:47:16 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/26 17:43:14 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	push_alpha(t_env **begin, t_env *new)
{
	t_env	*tmp;

	if (!*begin)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	destroy_t_env(t_env *to_destroy)
{
	if (to_destroy)
	{
		ft_strdel(&to_destroy->name);
		ft_strdel(&to_destroy->content);
		free(to_destroy);
	}
}

void	delete_t_env(t_env **begin, char *variable_to_delete)
{
	t_env	*tmp;
	t_env	*previous;
	t_env	*current;

	if (ft_strequ(variable_to_delete, (*begin)->name))
	{
		tmp = *begin;
		*begin = (*begin)->next;
		destroy_t_env(tmp);
		return ;
	}
	current = (*begin)->next;
	previous = *begin;
	while (current && previous)
	{
		if (ft_strequ(variable_to_delete, current->name))
		{
			tmp = current;
			previous->next = current->next;
			destroy_t_env(tmp);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

void	add_or_change(t_env **begin, char *name, char *content)
{
	t_env	*env;

	if (!variable_exist(begin, name))
		create_t_env(begin, name, content);
	else
	{
		env = *begin;
		while (env && !ft_strequ(name, env->name))
			env = env->next;
		ft_strdel(&env->content);
		env->content = ft_strdup(content);
	}
}

void	create_t_env(t_env **begin, char *name, char *content)
{
	t_env	*tmp;

	if (!(tmp = (t_env *)ft_memalloc(sizeof(t_env))))
		return ;
	tmp->name = ft_strdup(name);
	tmp->content = ft_strdup(content);
	tmp->next = NULL;
	push_alpha(begin, tmp);
}
