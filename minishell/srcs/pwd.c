/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:19:25 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/05 22:34:11 by tgrange          ###   ########.fr       */
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
	force_pwd(env);
}
