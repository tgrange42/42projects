/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 22:33:38 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/04 14:30:38 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*copy_t_env(t_env **begin)
{
	t_env	*ret;
	t_env	*tmp;

	if (!begin)
		return (NULL);
	tmp = *begin;
	ret = NULL;
	while (tmp)
	{
		if (tmp->name)
			create_t_env(&ret, tmp->name, tmp->content);
		tmp = tmp->next;
	}
	return (ret);
}

t_env	*copy_t_env2(t_env **begin, char *var)
{
	t_env	*ret;
	t_env	*tmp;

	if (!begin)
		return (NULL);
	tmp = *begin;
	ret = NULL;
	ft_putendl("copy");
	ft_putendl(var);
	while (tmp)
	{
		if (tmp->name && !ft_strequ(var, tmp->name))
			create_t_env(&ret, tmp->name, tmp->content);
		tmp = tmp->next;
	}
	delete_list(begin);
	begin = &ret;
	return (ret);
}
