/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:32:31 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/26 17:46:36 by tgrange          ###   ########.fr       */
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

void				cd(t_env **begin, char **args);

/*
**	echo.c
*/

void				echo2(char *str, t_env *env);
void				echo(char **str, t_env *env);

/*
**	env.c
*/

void				force_pwd(t_env *env);
char				*get_content(t_env **begin, char *name);
t_env				*get_env(char **environ);

/*
**	env_functions.c
*/

void				ft_unsetenv(t_env *begin, char **var_todel);
void				ft_env(t_env **env, char **args, char **environ);
void				ft_setenv(t_env **begin, char **var_con);

/*
**	env_list.c
*/

void				delete_t_env(t_env **begin, char *variable_to_delete);
void				add_or_change(t_env **begin, char *name, char *content);
void				push_alpha(t_env **begin, t_env *new);
void				create_t_env(t_env **begin, char *name, char *content);

/*
**	env_list2.c
*/

t_env				*copy_t_env(t_env **begin);

/*
**	exec_bin.c
*/

void				search_for_bin(t_env **begin, char *bin_to_srch,
	char **args, char **environ);

/*
**	exit_ms.c
*/

void				delete_list(t_env **env);
void				exit_ms(t_env **env);

/*
**	minishell.c
*/

/*
**	mini_core.c
*/

void				goto_func(char **args, t_env *env, char **environ);
void				mini_core(t_env **begin, char **environ, int g);

/*
**	pwd.c
*/

void				pwd(t_env *env);

/*
**	tilde.c
*/

void				get_tilde(char **args, t_env **begin);

/*
**	tools.c
*/

char				*get_path(char *path, char *name, char sep);
void				display_prompt(t_env **begin);
void				del_tabstr(char ***str);
void				equal_equal(t_env **t1, t_env **t2, t_env **s1, t_env **s2);
char				**t_env_to_tab(t_env **begin);

/*
**	tools2.c
*/

int					variable_exist(t_env **begin, char *name);
void				display_env(t_env **begin);
int					t_env_len(t_env **begin);
char				**split_var_con(char *str);

#endif
