/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:17:16 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/08 14:07:13 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		display_prompt(void)
{
	char	*buf;
	char	*tmp;

	tmp = NULL;
	buf = NULL;
	buf = getcwd(buf, PATH_MAX);
	ft_putstr("¯\\_(ツ)_/¯@");
	if (buf)
	{
		tmp = ft_strrchr(buf, '/') + 1;
		if (tmp[0])
			ft_putstr(tmp);
		else
			ft_putchar('/');
	}
	else
		ft_putstr("anywhere");
	ft_putstr("> ");
	ft_strdel(&buf);
}

char		*get_path(char *path, char *name, char sep)
{
	int		l;
	char	*ret;

	if (!path)
		return (ft_strdup(name));
	l = ft_strlen(path) + ft_strlen(name) + 2;
	if (!(ret = (char *)ft_memalloc(sizeof(char) * l)))
		return (NULL);
	ret = ft_strcpy(ret, path);
	ret[ft_strlen(path)] = sep;
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
}

char		**cpy_tab(char **src)
{
	char	**ret;
	int		i;

	i = 0;
	ret = NULL;
	if (!src)
		return (NULL);
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		ret[i] = ft_strdup(src[i]);
		i++;
	}
	return (ret);
}
