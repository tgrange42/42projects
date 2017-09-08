/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 17:51:43 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/07 19:16:37 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*replace_tilde(char *str, char **env, int k)
{
	int		l;
	char	*tmp;
	char	*ret;

	tmp = NULL;
	if (k == 1)
		tmp = ft_strdup(get_content(env, "HOME"));
	if (k == 2)
		tmp = getcwd(tmp, PATH_MAX);
	if (k == 3)
		tmp = (get_content(env, "OLDPWD") ? ft_strdup(get_content(env,
			"OLDPWD")) : ft_strdup("-"));
	if (!tmp)
		return (str);
	l = ft_strlen(tmp) + ft_strlen(str);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (l + 1))))
		return (NULL);
	ret = ft_strcpy(ret, tmp);
	ret = ft_strcat(ret, &str[(k == 1 ? 1 : 2)]);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (ret);
}

void	get_tilde(char **args, char **env)
{
	int		i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		if (args[i][0] == '~' && (!args[i][1] || args[i][1] == '/'))
			args[i] = replace_tilde(args[i], env, 1);
		else if (args[i][0] == '~' && args[i][1] == '+' && (!args[i][2] ||
			args[i][2] == '/'))
			args[i] = replace_tilde(args[i], env, 2);
		else if (args[i][0] == '~' && args[i][1] == '-' && (!args[i][2] ||
			args[i][2] == '/'))
			args[i] = replace_tilde(args[i], env, 3);
		i++;
	}
}
