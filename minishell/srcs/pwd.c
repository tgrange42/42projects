/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:19:25 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/07 19:16:37 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pwd(char **env)
{
	char	*buf;

	buf = NULL;
	buf = get_content(env, "PWD");
	ft_putendl(buf);
}
