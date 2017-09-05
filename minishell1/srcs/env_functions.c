/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:53:24 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/04 14:19:58 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unsetenv(t_env *begin, char **var_todel)
{
	// int		i;

	// i = 0;
	// while (var_todel[i])
	// 	delete_t_env(&begin, var_todel[i++]);
	// // if (!count_lst(&begin))
	// // 	begin = NULL;
	int		i;

	i = 0;
	while (var_todel[i])
	{
		ft_putendl(*var_todel);
		begin = copy_t_env2(&begin, var_todel[i++]);
		ft_putendl("end");
	}
}

void	ft_env_equal(t_env **begin, char **args)
{
	int		i;
	char	**split;
	char	**modified_env;
	t_env	*copy_env;

	i = 0;
	copy_env = copy_t_env(begin);
	while (args[i] && ft_strchr(args[i], '='))
	{
		split = split_var_con(args[i++]);
		if (split && split[0])
			add_or_change(&copy_env, (args[i - 1][0] != '=' ? split[0] : NULL),
				(args[i - 1][0] != '=' ? split[1] : split[0]));
		del_tabstr(&split);
	}
	if (!args[i])
		display_env(&copy_env);
	else
	{
		modified_env = t_env_to_tab(&copy_env);
		goto_func(&args[i], copy_env, modified_env);
		del_tabstr(&modified_env);
	}
	delete_list(&copy_env);
}

void	tmp_delete(t_env **begin, char **args)
{
	t_env	*copy_env;

	if (!args || !args[0])
	{
		ft_putendl_fd("env: need argument", 2);
		return ;
	}
	// copy_env = copy_t_env(begin);
	// delete_t_env(&copy_env, args[0]);
	copy_env = copy_t_env2(begin, args[0]);
	ft_env_equal(&copy_env, &args[1]);
	delete_list(&copy_env);
}

void	ft_env(t_env **begin, char **args, char **environ)
{
	if (!args[1] || ft_strchr(args[1], '='))
		ft_env_equal(begin, &args[1]);
	else if (args[1][0] != '-' && !ft_strchr(args[1], '='))
		goto_func(&args[1], *begin, environ);
	else if (ft_strequ("-i", args[1]))
		ft_env_equal(NULL, &args[2]);
	else if (ft_strequ("-u", args[1]))
		tmp_delete(begin, &args[2]);
}

void	ft_setenv(t_env **begin, char **var_con)
{
	int		i;
	char	**split;

	i = 0;
	while (var_con[i])
	{
		if (!ft_strchr(var_con[i], '='))
		{
			ft_putstr_fd("minishell: setenv: usage:", 2);
			ft_putendl_fd(" setenv \"variable=content\"", 2);
		}
		else
		{
			split = split_var_con(var_con[i]);
			if (split[1] && split[1][0] == '$')
				add_or_change(begin, split[0], get_content(begin,
					&split[1][1]));
			else
				add_or_change(begin, (var_con[i][0] != '=' ? split[0] : NULL),
				(var_con[i][0] != '=' ? split[1] : split[0]));
			del_tabstr(&split);
		}
		i++;
	}
}
