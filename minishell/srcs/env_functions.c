/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:53:24 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/30 10:31:59 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	display_env(t_env **begin)
{
	t_env	*env;

	env = *begin;
	while (env)
	{
		ft_putstr(env->name);
		ft_putchar('=');
		ft_putendl(env->content);
		env = env->next;
	}
}

void	ft_unsetenv(t_env **begin, char **var_todel)
{
	int		i;

	i = 0;
	while (var_todel[i])
	{
		if (delete_t_env(begin, var_todel[i]) == -1)
		{
			ft_putstr_fd("minishell: unsetenv: ", 2);
			ft_putstr_fd(var_todel[i], 2);
			ft_putendl_fd(" not set", 2);
		}
		i++;
	}
}

void	ft_setenv(t_env **begin, char **var_con)
{
	int		i;
	char	**split;

	i = 0;
	while (var_con[i])
	{
		if (!ft_strchr(var_con[i], '='))
			ft_putendl_fd("minishell: setenv: usage: setenv \"variable=content\"", 2);
		else
		{
			split = ft_strsplit(var_con[i], '=');
			if (split[1][0] == '$')
				add_or_change(begin, split[0], get_content(begin, &split[1][1]));
			else
				add_or_change(begin, split[0], split[1]);
			del_tabstr(&split);
		}
		i++;
	}
}
