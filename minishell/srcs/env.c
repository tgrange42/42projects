/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:22:35 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/03 01:05:34 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*get_content(t_env **begin, char *name)
{
	t_env	*env;

	env = *begin;
	while (env)
	{
		if (ft_strequ(name, env->name))
			return (env->content);
		env = env->next;
	}
	return (NULL);
}

void		force_pwd(t_env **begin)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, PATH_MAX);
	add_or_change(begin, "PWD", buf);
	ft_strdel(&buf);
}

void		increase_shlvl(t_env **begin)
{
	int		tmp;
	char	*tmp2;

	if (get_content(begin, "SHLVL"))
	{
		tmp = ft_atoi(get_content(begin, "SHLVL"));
		tmp2 = ft_itoa(tmp + 1);
		add_or_change(begin, "SHLVL", tmp2);
		ft_strdel(&tmp2);
	}
	else
		add_or_change(begin, "SHLVL", "1");
}

t_env		*get_env(char **environ)
{
	t_env	*ret;
	int		i;
	char	**tmp;

	i = 0;
	ret = NULL;
	while (environ[i])
	{
		tmp = ft_strsplit(environ[i++], '=');
		create_t_env(&ret, (environ[i - 1][0] != '=' ? tmp[0] : NULL),
				(environ[i - 1][0] != '=' ? tmp[1] : tmp[0]));
		del_tabstr(&tmp);
	}
	force_pwd(&ret);
	increase_shlvl(&ret);
	add_or_change(&ret, "SHELL", "minishell");
	delete_t_env(&ret, "OLDPWD");
	return (ret);
}
