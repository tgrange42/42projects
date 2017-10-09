/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:55:10 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/09 18:12:50 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	del_tabstr(char ***str)
{
	int		i;

	i = 0;
	if (!str || !*str)
		return ;
	while ((*str)[i])
		ft_strdel(&((*str)[i++]));
	free(*str);
}

void	del_inttab(int ***tab)
{
	int		i;

	i = 0;
	if (!tab || !*tab)
		return ;
	while ((*tab)[i])
		ft_memdel((void *)(&((*tab)[i++])));
	free(*tab);
}

void	del_triple_tab(char ****tab)
{
	int		i;

	i = 0;
	while (tab && *tab && (*tab)[i])
		del_tabstr(&tab[0][i++]);
	free(*tab);
	*tab = NULL;
}

int		*char_to_int(char **s, t_coor *t)
{
	int		*ret;
	int		i;

	ret = NULL;
	i = 0;
	if (!(ret = (int *)ft_memalloc(sizeof(int) * (ft_tablen(s)))))
		return (NULL);
	while (s[i])
	{
		ret[i] = ft_atoi(s[i]);
		if (ret[i] > t->size_max)
			t->size_max = ret[i];
		i++;
	}
	return (ret);
}

void	convert_map(char ***map, t_coor *t)
{
	int		i;

	t->t = NULL;
	i = 0;
	if (!(t->t = (int **)ft_memalloc(sizeof(int *) * (tri_tablen(map) + 1))))
		return ;
	t->size_max = 0;
	while (map[i])
	{
		t->t[i] = char_to_int(map[i], t);
		i++;
	}
}
