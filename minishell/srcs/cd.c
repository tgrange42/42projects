/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:41:04 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/04 17:08:21 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	change_dir(t_env **begin, char *path)
// {
// 	DIR		*test;

// 	test = opendir(path);
// 	if (!access(path, F_OK | R_OK) && test)
// 	{
// 		chdir(path);
// 		add_or_change(begin, "OLDPWD", get_content(begin, "PWD"));
// 		force_pwd(*begin);
// 		closedir(test);
// 	}
// 	else
// 	{
// 		ft_putstr_fd("cd: ", 2);
// 		ft_putstr_fd(path, 2);
// 		if (access(path, F_OK))
// 			ft_putendl_fd(" not such file or directory", 2);
// 		else if (access(path, R_OK))
// 			ft_putendl_fd(" permission denied", 2);
// 		else
// 			ft_putendl_fd(" not a directory", 2);
// 	}
// }

// void	cd_error(char *str)
// {
// 	ft_putstr_fd("cd: ", 2);
// 	ft_putstr_fd(str, 2);
// 	ft_putendl_fd(" not set", 2);
// }

// void	cd(t_env **begin, char **args)
// {
// 	if (ft_strequ("-", args[0]))
// 	{
// 		if (get_content(begin, "OLDPWD"))
// 			change_dir(begin, get_content(begin, "OLDPWD"));
// 		else
// 			cd_error("OLDPWD");
// 	}
// 	else if (ft_strequ("~", args[0]) || !args[0])
// 	{
// 		if (get_content(begin, "HOME"))
// 			change_dir(begin, get_content(begin, "HOME"));
// 		else
// 			cd_error("HOME");
// 	}
// 	else
// 		change_dir(begin, args[0]);
// }
