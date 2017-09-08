/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:38:45 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/07 19:16:35 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_dir(char ***env, char *path)
{
	DIR		*test;

	test = opendir(path);
	if (!access(path, F_OK | R_OK) && test)
	{
		chdir(path);
		*env = change_variable(*env, "OLDPWD", get_content(*env, "PWD"));
		*env = force_pwd(*env);
		closedir(test);
	}
	else
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		if (access(path, F_OK))
			ft_putendl_fd(" not such file or directory", 2);
		else if (access(path, R_OK))
			ft_putendl_fd(" permission denied", 2);
		else
			ft_putendl_fd(" not a directory", 2);
	}
}

void	cd_error(char *str)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" not set", 2);
}

void	cd(char ***env, char **args)
{
	if (ft_strequ("-", args[0]))
	{
		if (get_content(*env, "OLDPWD"))
			change_dir(env, get_content(*env, "OLDPWD"));
		else
			cd_error("OLDPWD");
	}
	else if (ft_strequ("~", args[0]) || !args[0])
	{
		if (get_content(*env, "HOME"))
			change_dir(env, get_content(*env, "HOME"));
		else
			cd_error("HOME");
	}
	else
		change_dir(env, args[0]);
}
