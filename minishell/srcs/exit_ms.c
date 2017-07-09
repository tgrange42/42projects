/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:07:59 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/07 19:17:09 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_list(t_env **env)
{
	t_env	*tmp;
	t_env	*tmp2;
	char	*tmp3;
	char	*tmp4;

	if (!env || !*env)
		return ;
	tmp = *env;
	while (tmp)
	{
		tmp2 = tmp->next;
		tmp3 = tmp->name;
		tmp4 = tmp->content;
		if (tmp3)
			ft_memdel((void **)&tmp);
		ft_strdel(&tmp3);
		ft_strdel(&tmp4);
		tmp = tmp2;
	}
}

void	exit_ms(t_env **env)
{
	delete_list(env);
	exit(1);
}
