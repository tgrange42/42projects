/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_draw3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:13:05 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/09 18:33:05 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	trace_line8(int x, int y, t_coor *t, t_tmp c)
{
	c.x1 = ((x - y - 1) * 10 + t->plx) * t->e;
	c.y1 = ((x + y - 1) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.x2 = ((x - y) * 10 + t->plx) * t->e;
	c.y2 = ((x + y - 2) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.color = (abs(t->t[y][x]) > abs(t->m)) ? t->ct[abs(t->t[y][x]) * 8 /
		abs(t->size_max) + 1] : 0x0000FF;
	draw(c, t);
	c.x1 = ((x - y) * 10 + t->plx) * t->e;
	c.y1 = ((x + y - 2) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.x2 = ((x - y + 1) * 10 + t->plx) * t->e;
	c.y2 = ((x + y - 1) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.color = (abs(t->t[y][x]) > abs(t->m)) ? t->ct[abs(t->t[y][x]) * 8 /
		abs(t->size_max) + 1] : 0x0000FF;
	draw(c, t);
}

void	trace_line7(int x, int y, t_coor *t, t_tmp c)
{
	c.x1 = ((x - y) * 10 + t->plx) * t->e;
	c.y1 = ((x + y - 2) * 5 + t->ply) * t->e;
	c.x2 = ((x - y) * 10 + t->plx) * t->e;
	c.y2 = ((x + y - 2) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.color = (abs(t->t[y][x]) > abs(t->m)) ? t->ct[abs(t->t[y][x]) * 8 /
		abs(t->size_max) + 1] : 0x0000FF;
	draw(c, t);
	c.x1 = ((x - y) * 10 + t->plx) * t->e;
	c.y1 = ((x + y) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.x2 = ((x - y + 1) * 10 + t->plx) * t->e;
	c.y2 = ((x + y - 1) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.color = (abs(t->t[y][x]) > abs(t->m)) ? t->ct[abs(t->t[y][x]) * 8 /
		abs(t->size_max) + 1] : 0x0000FF;
	draw(c, t);
	c.x1 = ((x - y) * 10 + t->plx) * t->e;
	c.y1 = ((x + y) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.x2 = ((x - y - 1) * 10 + t->plx) * t->e;
	c.y2 = ((x + y - 1) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.color = (abs(t->t[y][x]) > abs(t->m)) ? t->ct[abs(t->t[y][x]) * 8 /
		abs(t->size_max) + 1] : 0x0000FF;
	draw(c, t);
	trace_line8(x, y, t, c);
}

void	trace_line6(int x, int y, t_coor *t)
{
	t_tmp	c;

	c.x1 = ((x - y + 1) * 10 + t->plx) * t->e;
	c.y1 = ((x + y - 1) * 5 + t->ply) * t->e;
	c.x2 = ((x - y + 1) * 10 + t->plx) * t->e;
	c.y2 = ((x + y - 1) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.color = (abs(t->t[y][x]) > abs(t->m)) ? t->ct[abs(t->t[y][x]) * 8 /
		abs(t->size_max) + 1] : 0x0000FF;
	draw(c, t);
	c.x1 = ((x - y - 1) * 10 + t->plx) * t->e;
	c.y1 = ((x + y - 1) * 5 + t->ply) * t->e;
	c.x2 = ((x - y - 1) * 10 + t->plx) * t->e;
	c.y2 = ((x + y - 1) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.color = (abs(t->t[y][x]) > abs(t->m)) ? t->ct[abs(t->t[y][x]) * 8 /
		abs(t->size_max) + 1] : 0x0000FF;
	draw(c, t);
	c.x1 = ((x - y) * 10 + t->plx) * t->e;
	c.y1 = ((x + y) * 5 + t->ply) * t->e;
	c.x2 = ((x - y) * 10 + t->plx) * t->e;
	c.y2 = ((x + y) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
	c.color = (abs(t->t[y][x]) > abs(t->m)) ? t->ct[abs(t->t[y][x]) * 8 /
		abs(t->size_max) + 1] : 0x0000FF;
	draw(c, t);
	trace_line7(x, y, t, c);
}

void	which_tracing(int x, int y, t_coor *t)
{
	if (t->proj == 1)
	{
		if (t->cube == 1)
			trace_line6(x, y, t);
		else
			trace_line(x, y, t);
	}
	else
	{
		if (t->cube == 1)
			trace_line3(x, y, t);
		else
			trace_line2(x, y, t);
	}
}
