/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:19:25 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/30 10:32:02 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pwd(t_env *env)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, PATH_MAX);
	ft_putendl(buf);
	ft_strdel(&buf);
	force_pwd(&env);
}
