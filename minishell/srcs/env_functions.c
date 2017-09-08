/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:53:24 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/07 19:16:34 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_unsetenv(char **env, char **var_todel)
{
	int		i;

	i = 0;
	while (var_todel[i])
		env = delete_var(env, var_todel[i++]);
	return (env);
}

void	ft_env_equal(char **env, char **args)
{
	int		i;
	char	**split;
	char	**cpy_env;

	i = 0;
	cpy_env = cpy_tab(env);
	while (args[i] && ft_strchr(args[i], '='))
	{
		split = split_var_con(args[i++]);
		if (split && split[0])
			cpy_env = change_variable(cpy_env, split[0], split[1]);
		del_tabstr(&split);
	}
	if (!args[i])
		display_env(cpy_env);
	else
	{
		goto_func(&args[i], &cpy_env);
		del_tabstr(&cpy_env);
	}
	del_tabstr(&cpy_env);
}

void	tmp_delete(char ***env, char **args)
{
	char	**env_cpy;

	if (!args || !args[0])
	{
		ft_putendl_fd("env: need argument", 2);
		return ;
	}
	// copy_env = copy_t_env(begin);
	// delete_t_env(&copy_env, args[0]);
	env_cpy = cpy_tab(*env);
	env_cpy = delete_var(*env, args[0]);
	ft_env_equal(env_cpy, &args[1]);
	del_tabstr(&env_cpy);
}

void	ft_env(char **args, char **environ)
{
	if (!args[1] || ft_strchr(args[1], '='))
		ft_env_equal(environ, &args[1]);
	else if (args[1][0] != '-' && !ft_strchr(args[1], '='))
		goto_func(&args[1], &environ);
	else if (ft_strequ("-i", args[1]))
		ft_env_equal(NULL, &args[2]);
	else if (ft_strequ("-u", args[1]))
		tmp_delete(&environ, &args[2]);
}

char	**ft_setenv(char **env, char **var_con)
{
	int		i;
	char	**tmp;
	char	**ret;

	ret = cpy_tab(env);
	i = 0;
	while (var_con[i])
	{
		tmp = NULL;
		if (!ft_strchr(var_con[i], '='))
		{
			ft_putstr_fd("minishell: setenv: usage:", 2);
			ft_putendl_fd(" setenv \"variable=content\"", 2);
		}
		else
		{
			tmp = split_var_con(var_con[i]);
			ret = change_variable(ret, tmp[0], tmp[1]);
			del_tabstr(&tmp);
		}
		i++;
	}
	del_tabstr(&env);
	return (ret);
}
