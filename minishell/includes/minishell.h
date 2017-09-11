/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:32:31 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/08 14:17:12 by tgrange          ###   ########.fr       */
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
**	variables
*/

int					g_in_child;

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
**	env_modi.c
*/

char				**delete_var(char **env, char *variable_to_delete);
char				**change_variable(char **env, char *name, char *content);

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
void				display_prompt(void);
void				del_tabstr(char ***str);
char				**cpy_tab(char **src);

/*
**	tools2.c
*/

int					variable_exist(char **env, char *name);
void				display_env(char **env);
char				**split_var_con(char *str);

#endif
