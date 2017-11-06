/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:26:06 by tgrange           #+#    #+#             */
/*   Updated: 2017/11/06 15:57:17 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	error_exit(int error, t_env *to_free)
{
	(void)to_free;
	// if (to_free)
	// 	free_lst(&to_free);
	if (error == 1)
		ft_putendl_fd("ft_select: usage: './ft_select [arg] ...'", 2);
	exit(0);
}
