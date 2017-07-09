/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 22:33:38 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/05 17:11:41 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*copy_t_env(t_env **begin)
{
	t_env	*ret;
	t_env	*tmp;

	if (!begin)
		return (NULL);
	tmp = *begin;
	ret = NULL;
	while (tmp)
	{
		if (tmp->name)
			create_t_env(&ret, tmp->name, tmp->content);
		tmp = tmp->next;
	}
	return (ret);
}
