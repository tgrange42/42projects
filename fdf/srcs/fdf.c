/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:33:15 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/09 18:32:54 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		verif_map(char ***map)
{
	int		tmp;
	int		i;

	i = 0;
	if (!map)
		return (2);
	tmp = ft_tablen(map[0]);
	if (!tri_tablen(map))
		return (2);
	while (map[i])
	{
		if (ft_tablen(map[i]) != tmp)
			return (1);
		i++;
	}
	return (0);
}

int		*get_color(void)
{
	int		*ret;

	if (!(ret = (int *)ft_memalloc(sizeof(int) * 10)))
		return (NULL);
	ret[0] = 0x0000FF;
	ret[1] = 0x663300;
	ret[2] = 0x4C9900;
	ret[3] = 0x00FF80;
	ret[4] = 0x00FF00;
	ret[5] = 0x80FF00;
	ret[6] = 0xFFFF00;
	ret[7] = 0xFF8000;
	ret[8] = 0xFF0000;
	ret[9] = 0xFF0000;
	return (ret);
}

void	pre_fdf(t_coor *t)
{
	t->h = 0.2;
	t->e = 1;
	t->ply = 300;
	t->plx = 1000 / 2 + t->size_x * 2;
	t->modi = 1;
	t->ct = get_color();
	t->proj = 1;
	t->m = t->t[0][0];
	t->cube = -1;
	init_draw(t);
}

void	init_draw(t_coor *t)
{
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, 1000, 1000, "FDF");
	loop_draw(t);
}

int		main(int ac, char **av)
{
	char	***map;
	t_coor	*table;
	int		error;

	map = NULL;
	table = NULL;
	if (ac == 1)
		ft_putendl_fd("fdf: usage: ./fdf [map_name]", 2);
	else
	{
		map = get_map(av[1]);
		if ((error = verif_map(map)) != 0)
			exit_fdf_error(map, error, NULL);
		if (!(table = (t_coor *)ft_memalloc(sizeof(t_coor) * 1)))
			return (0);
		convert_map(map, table);
		table->size_x = ft_tablen(map[0]);
		table->size_y = tri_tablen(map);
		del_triple_tab(&map);
		pre_fdf(table);
	}
	return (0);
}
