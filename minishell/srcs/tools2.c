/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:31:56 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/08 14:13:56 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**split_var_con(char *str)
{
	char	**ret;

	if (!(ret = (char **)ft_memalloc(sizeof(ret) * 3)))
		return (NULL);
	ret[0] = ft_strsub(str, 0, ft_strlento(str, 0, '='));
	if (ft_strchr(str, '='))
		ret[1] = ft_strsub(str, ft_strlento(str, 0, '=') + 1, ft_strlen(str) -
			ft_strlento(str, 0, '='));
	return (ret);
}

void	display_env(char **env)
{
	int		i;

	i = 0;
	if (env)
		while (env[i])
			ft_putendl(env[i++]);
}
