/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:47:16 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/05 17:34:29 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	push_alpha(t_env **begin, t_env *new)
{
	t_env	*tmp;

	if (!*begin)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	destroy_t_env(t_env *to_destroy)
{
	if (to_destroy)
	{
		ft_strdel(&to_destroy->name);
		ft_strdel(&to_destroy->content);
		free(to_destroy);
		to_destroy = NULL;
	}
}

char	**delete_var(char **env, char *variable_to_delete)
{
	char	**ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(env) + 1))))
		return (NULL);
	while (env[i])
	{
		if (!ft_strnequ(variable_to_delete, env[i], ft_strlen(variable_to_delete)))
			ret[j++] = ft_strdup(env[i]);
		i++;
	}
	del_tabstr(&env);
	return (ret);
}

// void	create_t_env(t_env **begin, char *name, char *content)
// {
// 	t_env	*tmp;

// 	if (!(tmp = (t_env *)ft_memalloc(sizeof(t_env))))
// 		return ;
// 	tmp->name = ft_strdup(name);
// 	tmp->content = ft_strdup(content);
// 	tmp->next = NULL;
// 	push_alpha(begin, tmp);
// }
