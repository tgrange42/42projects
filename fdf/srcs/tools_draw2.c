/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_draw2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:24:44 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/02 17:07:13 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		trace_line2(int x, int y, t_coor *t)
{
	t_tmp	c;

	if (x < t->size_x - 1)
	{
		c.x1 = ((x - y) * 10) * t->e + t->plx;
		c.y1 = (y * 5 - t->t[y][x] * t->h) * t->e + t->ply;
		c.x2 = ((x - y + 1) * 10) * t->e + t->plx;
		c.y2 = (y * 5 - t->t[y][x + 1] * t->h) * t->e + t->ply;
		c.color = (abs(t->t[y][x + 1]) > abs(t->m)) ? t->ct[abs(t->t[y][x + 1])
			* 8 / abs(t->size_max) + 1] : 0x0000FF;
		draw(c, t);
	}
	if (y < t->size_y - 1)
	{
		c.x1 = ((x - y) * 10) * t->e + t->plx;
		c.y1 = (y * 5 - t->t[y][x] * t->h) * t->e + t->ply;
		c.x2 = ((x - y - 1) * 10) * t->e + t->plx;
		c.y2 = ((y + 1) * 5 - t->t[y + 1][x] * t->h) * t->e + t->ply;
		c.color = (abs(t->t[y + 1][x]) > abs(t->m)) ? t->ct[abs(t->t[y + 1][x])
			* 8 / abs(t->size_max) + 1] : 0x0000FF;
		draw(c, t);
	}
}
