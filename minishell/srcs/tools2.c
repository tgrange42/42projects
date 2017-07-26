/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:31:56 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/26 17:46:23 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**split_var_con(char *str)
{
	char	**ret;

	if (!(ret = (char **)ft_memalloc(sizeof(ret) * 3)))
		return (NULL);
	ret[0] = ft_strsub(str, 0, ft_strlento(str, 0, '='));
	if (ft_strchr(str, '='))
		ret[1] = ft_strsub(str, ft_strlento(str, 0, '=') + 1, ft_strlen(str) -
			ft_strlento(str, 0, '='));
	return (ret);
}

int		variable_exist(t_env **begin, char *name)
{
	t_env	*tmp;

	tmp = *begin;
	while (tmp)
	{
		if (ft_strequ(name, tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	display_env(t_env **begin)
{
	t_env	*env;

	env = *begin;
	while (env)
	{
		if (env->name)
		{
			ft_putstr(env->name);
			ft_putchar('=');
			ft_putendl(env->content);
		}
		env = env->next;
	}
}

int		t_env_len(t_env **begin)
{
	int		i;
	t_env	*tmp;

	tmp = *begin;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
