/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:22:35 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/11 14:59:37 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		variable_exist(char **env, char *var)
{
	int		i;

	i = 0;
	if (!env)
		return (0);
	while (env[i])
	{
		if (ft_strnequ(var, env[i], ft_strlen(var)))
			return (1);
		i++;
	}
	return (0);
}

char	**add_var(char **env, char *var, char *content)
{
	char	**ret;
	int		i;

	i = 0;
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(env) + 2))))
		return (NULL);
	while (env && env[i])
	{
		ret[i] = ft_strdup(env[i]);
		i++;
	}
	ret[i] = get_path(var, content, '=');
	del_tabstr(&env);
	return (ret);
}

char	**change_variable(char **env, char *name, char *content)
{
	int		i;

	i = 0;
	if (env && variable_exist(env, name))
	{
		while (!ft_strnequ(name, env[i], ft_strlen(name)))
			i++;
		ft_strdel(&env[i]);
		env[i] = get_path(name, content, '=');
	}
	else
		return (add_var(env, name, content));
	return (env);
}

char	**increase_shlvl(char **env)
{
	char	*tmp;

	if (variable_exist(env, "SHLVL"))
	{
		tmp = ft_itoa(ft_atoi(get_content(env, "SHLVL")) + 1);
		env = change_variable(env, "SHLVL", tmp);
		ft_strdel(&tmp);
	}
	else
		env = change_variable(env, "SHLVL", "1");
	return (env);
}

char	**get_env(char **environ)
{
	int		i;
	char	**ret;

	i = 0;
	ret = cpy_tab(environ);
	ret = increase_shlvl(ret);
	ret = change_variable(ret, "SHELL", "minishell");
	ret = delete_var(ret, "OLDPWD");
	ret = force_pwd(ret);
	return (ret);
}
