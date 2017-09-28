/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:08:46 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/28 17:47:30 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		tri_tablen(char ***tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

void	exit_fdf(t_coor *t)
{
	mlx_destroy_window(t->mlx, t->win);
	del_inttab(&t->t, t->size_y);
	free(t);
	exit(0);
}

void	plus_plus(int *a, int b, int *c, int d)
{
	*a = b;
	*c = d;
}
