/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:08:46 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/09 18:33:30 by tgrange          ###   ########.fr       */
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
	del_inttab(&t->t);
	free(t);
	exit(0);
}

void	plus_plus(int *a, int b, int *c, int d)
{
	*a = b;
	*c = d;
}

void	exit_fdf_error(char ***map, int error, char *name)
{
	del_triple_tab(&map);
	if (error == 1)
		ft_putendl_fd("fdf: map not clean", 2);
	if (error == 2)
		ft_putendl_fd("fdf: map empty", 2);
	if (error == 3)
	{
		ft_putstr_fd("fdf: failed to open: ", 2);
		ft_putendl_fd(name, 2);
	}
	exit(0);
}
