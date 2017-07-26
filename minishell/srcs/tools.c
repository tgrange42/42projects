/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:17:16 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/26 16:10:03 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		display_prompt(t_env **begin)
{
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = NULL;
	if (begin && variable_exist(begin, "PWD") &&
		ft_strchr(get_content(begin, "PWD"), '/'))
		tmp2 = ft_strdup(get_content(begin, "PWD"));
	else
		tmp2 = getcwd(tmp2, PATH_MAX);
	ft_putstr("minishell@");
	while (tmp2[i])
	{
		if (tmp2[i++] == '/')
			ft_putchar('/');
		if (tmp2[i])
			ft_putchar(tmp2[i]);
		while (tmp2[i] && tmp2[i] != '/')
			i++;
	}
	if (!ft_strequ("/", tmp2))
		ft_putstr(ft_strrchr(tmp2, '/') + 2);
	ft_strdel(&tmp2);
	ft_putstr("> ");
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

void		equal_equal(t_env **t1, t_env **t2, t_env **s1, t_env **s2)
{
	*t1 = *t2;
	*s1 = *s2;
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

char		**t_env_to_tab(t_env **begin)
{
	char	**ret;
	int		i;
	t_env	*tmp;

	if (!begin || !*begin)
		return (NULL);
	tmp = *begin;
	i = 0;
	if (!(ret = (char **)ft_memalloc(sizeof(ret) * (t_env_len(begin) + 1))))
		return (NULL);
	while (tmp)
	{
		if (tmp->name)
			ret[i++] = get_path(tmp->name, tmp->content, '=');
		tmp = tmp->next;
	}
	return (ret);
}
