/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:17:16 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/03 20:05:17 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		display_prompt(int *n)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	if (*n)
		ft_putchar('\n');
	*n = 0;
	tmp2 = getcwd(NULL, PATH_MAX);
	tmp = ft_strrchr(tmp2, '/');
	ft_putstr("minishell@");
	while (tmp2[i])
	{
		if (tmp2[i++] == '/')
			ft_putchar('/');
		if (tmp2[i])
			ft_putchar(tmp2[i]);
		while (tmp2[i] && tmp2[i] && tmp2[i] != '/')
			i++;
	}
	if (tmp[1])
		ft_putstr(&tmp[2]);
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

void	equal_equal(t_env **t1, t_env **t2, t_env **s1, t_env **s2)
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
	ft_memdel((void **)*str);
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
		ret[i++] = get_path(tmp->name, tmp->content, '=');
		tmp = tmp->next;
	}
	return (ret);
}
