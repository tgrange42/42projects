/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:32:31 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/02 22:34:29 by tgrange          ###   ########.fr       */
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

void				force_pwd(t_env **begin);
char				*get_content(t_env **begin, char *name);
t_env				*get_env(char **environ);

/*
**	env_functions.c
*/

void				ft_unsetenv(t_env **begin, char **var_todel);
void				ft_env(t_env **env, char **args, char **environ);
void				ft_setenv(t_env **begin, char **var_con);

/*
**	env_list.c
*/

int					delete_t_env(t_env **begin, char *variable_to_delete);
void				add_or_change(t_env **begin, char *name, char *content);
void				push_alpha(t_env **begin, t_env *new);
void				create_t_env(t_env **begin, char *name, char *content);
int					t_env_len(t_env **begin);

/*
**	env_list2.c
*/

t_env				*copy_t_env(t_env **begin);

/*
**	exec_bin.c
*/

void				search_for_bin(t_env **begin, char *bin_to_srch, char **args, char **environ);

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
void				mini_core(t_env *begin, char **environ);

/*
**	pwd.c
*/

void				pwd(t_env *env);

/*
**	tools.c
*/

char				*get_path(char *path, char *name, char sep);
void				display_prompt();
void				del_tabstr(char ***str);
void				equal_equal(t_env **t1, t_env **t2, t_env **s1, t_env **s2);
char				**t_env_to_tab(t_env **begin);

#endif
