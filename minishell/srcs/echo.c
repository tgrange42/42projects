/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:33:20 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/07 19:16:47 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo2(char *str, char **env)
{
	ft_putstr(get_content(env, str));
	ft_strdel(&str);
}

void	echo(char **str, char **env)
{
	int		i;
	int		j;
	int		l;

	l = 0;
	while (str[l])
	{
		i = 0;
		while (str[l][i])
		{
			if (str[l][i] == '$')
			{
				j = ft_strlento(str[l], i + 1, '$');
				echo2(ft_strsub(str[l], i + 1, j), env);
				i += j + 1;
			}
			else
				ft_putchar(str[l][i++]);
		}
		l++;
		if (str[l])
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
