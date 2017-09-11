/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:14:19 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/08 14:16:55 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_content(char **env, char *name)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(name, env[i], ft_strlen(name)))
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
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
		if (!ft_strnequ(variable_to_delete, env[i],
			ft_strlen(variable_to_delete)))
			ret[j++] = ft_strdup(env[i]);
		i++;
	}
	del_tabstr(&env);
	return (ret);
}
