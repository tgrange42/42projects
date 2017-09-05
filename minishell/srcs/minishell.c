/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:01:14 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/05 17:44:23 by tgrange          ###   ########.fr       */
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
	char			**env;

	signal(SIGINT, sig_c);
	env = get_env(environ);
	mini_core(env, 1);
	return (0);
}
