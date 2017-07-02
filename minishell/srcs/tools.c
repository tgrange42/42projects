/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:17:16 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/01 00:37:43 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		display_prompt(void)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = getcwd(NULL, PATH_MAX);
	tmp = ft_strrchr(tmp2, '/');
	ft_putstr(&tmp[1]);
	ft_strdel(&tmp2);
	ft_putstr("> ");
}

char		*get_path(char *path, char *name)
{
	int		l;
	char	*ret;

	if (!path)
		return (ft_strdup(name));
	l = ft_strlen(path) + ft_strlen(name) + 2;
	if (!(ret = (char *)ft_memalloc(sizeof(char) * l)))
		return (NULL);
	ret = ft_strcpy(ret, path);
	ret[ft_strlen(path)] = '/';
	ret = ft_strcat(ret, name);
	return (ret);
}

void		del_tabstr(char ***str)
{
	int		i;

	i = 0;
	if (!str || !*str)
		return ;
	while ((*str)[i])
		ft_strdel(&((*str)[i++]));
	free(*str);
	*str = NULL;
}
