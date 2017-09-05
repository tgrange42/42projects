/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 16:52:01 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/05 18:00:13 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute(char *bin_path, char **args, char **environ)
{
	pid_t	father;

	father = fork();
	if (father > 0)
		wait(&father);
	else if (!father)
	{
		if (execve(bin_path, args, environ) == -1)
		{
			ft_putstr_fd("minishell: command not found: ", 2);
			ft_putendl_fd(bin_path, 2);
			exit(1);
		}
	}
	else
		ft_putendl_fd("minishell: fork: failed to fork", 2);
}

int		is_bin_indir(char *path, char *name)
{
	DIR				*stream;
	struct dirent	*list;
	int				t;

	t = 0;
	stream = opendir(path);
	if (stream)
	{
		while ((list = readdir(stream)) != NULL)
		{
			if (!ft_strequ(list->d_name, ".") && !ft_strequ(list->d_name, "..")
				&& ft_strequ(list->d_name, name))
			{
				t = 1;
				break ;
			}
		}
		closedir(stream);
	}
	return (t);
}

/*
**	if (!get_content(begin, "PATH"))
**	{
**		if (!(paths = (char **)ft_memalloc(sizeof(paths) * 3)))
**			return ;
**		paths[0] = ft_strdup("/bin");
**		paths[1] = ft_strdup("/usr/bin");
**	}
**	else
*/

void	search_for_bin(char *bin_to_srch, char **args,
	char **env)
{
	char	**paths;
	char	*bin_path;
	int		i;

	i = 0;
	if (!variable_exist(env, "PATH"))
		execute(bin_to_srch, args, env);
	else
	{
		paths = ft_strsplit(get_content(env, "PATH"), ':');
		while (paths[i])
		{
			if (is_bin_indir(paths[i], bin_to_srch))
				break ;
			i++;
		}
		bin_path = get_path(paths[i], bin_to_srch, '/');
		del_tabstr(&paths);
		execute(bin_path, args, env);
		ft_strdel(&bin_path);
	}
}
