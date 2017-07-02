/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 16:52:01 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/01 00:43:20 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		execute(char *bin_path, char **args)
{
	pid_t	father;

	father = fork();
	if (father > 0)
		wait(NULL);
	else if (!father)
	{
		if (execve(bin_path, args, NULL) == -1)
			return (-1);
	}
	else
		ft_putendl_fd("minishell: fork: failed to fork", 2);
	return (0);
}

int		is_bin_indir(char *path, char *name)
{
	DIR				*stream;
	struct dirent	*list;
	int				t;

	t = 0;
	stream = opendir(path);
	while ((list = readdir(stream)) != NULL)
	{
		if (!ft_strequ(list->d_name, ".") && !ft_strequ(list->d_name, "..") &&
			ft_strequ(list->d_name, name))
			t = 1;
	}
	closedir(stream);
	return (t);
}

int		search_for_bin(t_env **begin, char *bin_to_srch, char **args)
{
	char	**paths;
	char	*bin_path;
	int		i;

	i = 0;
	paths = ft_strsplit(get_content(begin, "PATH"), ':');
	while (paths[i])
	{
		if (is_bin_indir(paths[i], bin_to_srch))
			break;
		i++;
	}
	bin_path = get_path(paths[i], bin_to_srch);
	del_tabstr(&paths);
	if (execute(bin_path, args) == -1)
		ft_putendl_fd("minishell: failed to find the binary", 2);
	ft_strdel(&bin_path);
	return (1);
}
