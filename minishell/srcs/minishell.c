/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:01:14 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/26 17:33:33 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sig_c(int lol)
{
	(void)lol;
	ft_putchar('\n');
	display_prompt(NULL);
}

int		main(void)
{
	extern char		**environ;
	t_env			*env;

	signal(SIGINT, sig_c);
	env = get_env(environ);
	mini_core(&env, environ, 1);
	return (0);
}
