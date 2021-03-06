/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:21:18 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/08 14:13:04 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	goto_func(char **args, char ***env)
{
	if (!args)
		return ;
	else if (ft_strequ("env", args[0]))
		ft_env(args, *env);
	else if (ft_strequ("echo", args[0]))
		echo(&args[1], *env);
	else if (ft_strequ("exit", args[0]))
		exit_ms(*env);
	else if (ft_strequ("cd", args[0]))
		cd(env, &args[1]);
	else if (ft_strequ("pwd", args[0]))
		pwd(*env);
	else if (ft_strequ("setenv", args[0]))
		*env = ft_setenv(*env, &args[1]);
	else if (ft_strequ("unsetenv", args[0]))
		*env = ft_unsetenv(*env, &args[1]);
	else
		search_for_bin(args[0], args, *env);
}

void	escape_ctrl_d(int *i, int g)
{
	*i = 0;
	if (!g)
		ft_putendl("");
}

void	mini_core(char **environ, int g)
{
	char	*buf;
	char	**args;
	char	**lines;
	int		i;

	buf = NULL;
	while (1)
	{
		display_prompt();
		g = get_next_line(0, &buf);
		if (buf[0] || !g)
		{
			escape_ctrl_d(&i, g);
			lines = ft_strsplit(buf, ';');
			while (lines && lines[i])
			{
				args = ft_tabsplit(lines[i++]);
				get_tilde(args, environ);
				goto_func(args, &environ);
				del_tabstr(&args);
			}
			del_tabstr(&lines);
		}
		ft_strdel(&buf);
	}
}
