/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:32:31 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/07 19:16:36 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>
# include <limits.h>

# include "../Libft/libft.h"

/*
**	structs
*/

typedef	struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

/*
**	cd.c
*/

void				cd(char ***env, char **args);

/*
**	echo.c
*/

void				echo2(char *str, char **env);
void				echo(char **str, char **env);

/*
**	env.c
*/

char				**force_pwd(char **env);
char				*get_content(char **env, char *name);
char				**get_env(char **environ);

/*
**	env_functions.c
*/

char				**ft_unsetenv(char **env, char **var_todel);
void				ft_env(char **args, char **environ);
char				**ft_setenv(char **env, char **var_con);

/*
**	env_list.c
*/

char				**delete_var(char **env, char *variable_to_delete);
char				**change_variable(char **env, char *name, char *content);

/*
**	env_list2.c
*/

// t_env				*copy_t_env(t_env **begin);
// t_env				*copy_t_env2(t_env **begin, char *var);

/*
**	exec_bin.c
*/

void				search_for_bin(char *bin_to_srch, char **args, char **env);

/*
**	exit_ms.c
*/

void				exit_ms(char **env);

/*
**	minishell.c
*/

/*
**	mini_core.c
*/

void				goto_func(char **args, char ***environ);
void				mini_core(char **environ, int g);

/*
**	pwd.c
*/

void				pwd(char **env);

/*
**	tilde.c
*/

void				get_tilde(char **args, char **env);

/*
**	tools.c
*/

char				*get_path(char *path, char *name, char sep);
void				display_prompt(char **env);
void				del_tabstr(char ***str);
// void				equal_equal(t_env **t1, t_env **t2, t_env **s1, t_env **s2);
char				**cpy_tab(char **src);

/*
**	tools2.c
*/

int					variable_exist(char **env, char *name);
void				display_env(char **env);
// int					t_env_len(t_env **begin);
char				**split_var_con(char *str);
// int					count_lst(t_env **begin);

#endif
