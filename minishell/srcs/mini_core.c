/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:21:18 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/01 00:32:18 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	goto_func(char **args, t_env *env)
{
	if (ft_strequ("env", args[0]))
		display_env(&env);
	else if (ft_strequ("echo", args[0]))
		echo(&args[1], env);
	else if (ft_strequ("exit", args[0]))
		exit_ms(&env);
	else if (ft_strequ("cd", args[0]))
		cd(&env, &args[1]);
	else if (ft_strequ("pwd", args[0]))
		pwd(env);
	else if (ft_strequ("setenv", args[0]))
		ft_setenv(&env, &args[1]);
	else if (ft_strequ("unsetenv", args[0]))
		ft_unsetenv(&env, &args[1]);
	else
		search_for_bin(&env, args[0], args);
}

void	mini_core(t_env *env)
{
	char	*buf;
	char	**args;

	buf = NULL;
	while (1)
	{
		display_prompt();
		get_next_line(0, &buf);
		args = ft_strsplit(buf, ' ');
		goto_func(args, env);
		del_tabstr(&args);
		ft_strdel(&buf);
	}
}
