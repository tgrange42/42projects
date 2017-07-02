/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:41:04 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/30 10:32:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_dir(t_env **begin, char **args, int p)
{
	int		error;

	error = 0;
	if (ft_strequ("-", args[p]))
	{
		if (get_content(begin, "OLDPWD"))
			chdir(get_content(begin, "OLDPWD"));
		else
		{
			ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
			error = 1;
		}
	}
	else if (!args[p] || ft_strequ("~", args[p]))
	{
		if (get_content(begin, "HOME"))
			chdir(get_content(begin, "HOME"));
		else
		{
			ft_putendl_fd("minishell: cd: HOME not set", 2);
			error = 1;
		}
	}
	else
		chdir(args[p]);
	if  (!error)
	{
		add_or_change(begin, "OLDPWD", get_content(begin, 	"PWD"));
		force_pwd(begin);
	}
}

void	cd(t_env **begin, char **args)
{
	int		p;

	p = 0;
	if (ft_strequ("-P", args[0]))
		p = 1;
	change_dir(begin, args, p);
}
