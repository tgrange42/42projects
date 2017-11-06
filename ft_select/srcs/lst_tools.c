/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:29:14 by tgrange           #+#    #+#             */
/*   Updated: 2017/11/06 16:25:11 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	push(t_lst **begin, t_lst *new)
{
	t_lst	*tmp;

	tmp = *begin;
	if (!*begin)
		*begin = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	newnode(t_lst **beg, char *content)
{
	t_lst	*ret;

	if (!(ret = (t_lst *)ft_memalloc(sizeof(t_lst))))
		return ;
	ret->next = NULL;
	ret->content = ft_strdup(content);
	ret->hl = 0;
	ret->show = 1;
	push(beg, ret);
}

t_lst	*get_lst(char **av)
{
	int		i;
	t_lst	*ret;

	ret = NULL;
	i = 1;
	while (av[i])
		newnode(&ret, av[i++]);
	return (ret);
}

void	free_lst(t_lst **lst)
{
	t_lst	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		// free
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
