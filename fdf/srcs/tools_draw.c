/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:31:40 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/04 16:31:00 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		pixel_put(int x, int y, t_coor *t, int color)
{
	if (x * 4 <= t->win_size && x >= 0 && y * 4 < t->win_size && y >= 0)
	{
		t->image[(((x + y * t->win_size / 4) - 1) * 4)] = (char)(color % 256);
		t->image[(((x + y * t->win_size / 4) - 1) * 4) + 1] = (char)(color / 256
			% 256);
		t->image[(((x + y * t->win_size / 4) - 1) * 4) + 2] = (char)(color / 256
			/ 256 % 256);
	}
}

void		draw2(t_tmp c, t_coor *t, int e)
{
	int	dx;
	int	dy;

	if ((c.x2 - c.x1) >= -(c.y2 - c.y1))
	{
		e = c.x2 - c.x1;
		plus_plus(&dx, e * 2, &dy, (c.y2 - c.y1) * 2);
		while (c.x1 < c.x2)
		{
			pixel_put(c.x1, c.y1, t, c.color);
			((e = e + dy) < 0) ? plus_plus(&c.y1, c.y1 - 1, &e, e + dx) : 0;
			c.x1++;
		}
	}
	else
	{
		e = c.y2 - c.y1;
		plus_plus(&dy, e * 2, &dx, (c.x2 - c.x1) * 2);
		while (c.y1 > c.y2)
		{
			pixel_put(c.x1, c.y1, t, c.color);
			((e = e + dx) > 0) ? plus_plus(&c.x1, c.x1 + 1, &e, e + dy) : 0;
			c.y1--;
		}
	}
}

void		draw1(t_tmp c, t_coor *t, int e)
{
	int	dx;
	int	dy;

	if ((c.x2 - c.x1) >= (c.y2 - c.y1))
	{
		e = c.x2 - c.x1;
		plus_plus(&dx, e * 2, &dy, (c.y2 - c.y1) * 2);
		while (c.x1 < c.x2)
		{
			pixel_put(c.x1, c.y1, t, c.color);
			((e = e - dy) < 0) ? plus_plus(&c.y1, c.y1 + 1, &e, e + dx) : 0;
			c.x1++;
		}
	}
	else
	{
		e = c.y2 - c.y1;
		plus_plus(&dy, e * 2, &dx, (c.x2 - c.x1) * 2);
		while (c.y1 < c.y2)
		{
			pixel_put(c.x1, c.y1, t, c.color);
			((e = e - dx) < 0) ? plus_plus(&c.x1, c.x1 + 1, &e, e + dy) : 0;
			c.y1++;
		}
	}
}

void		draw(t_tmp c, t_coor *t)
{
	int	tmpx;
	int	tmpy;

	tmpx = c.x1;
	tmpy = c.y1;
	if (c.x1 > c.x2)
	{
		ft_swap(&c.x1, &c.x2);
		ft_swap(&c.y1, &c.y2);
	}
	if ((c.y2 - c.y1) >= 0)
		draw1(c, t, 0);
	else
		draw2(c, t, 0);
	pixel_put(tmpx, tmpy, t, c.color);
	pixel_put(c.x2, c.y2, t, c.color);
}

void		trace_line(int x, int y, t_coor *t)
{
	t_tmp	c;

	if (x < t->size_x - 1)
	{
		c.x1 = ((x - y) * 10 + t->plx) * t->e;
		c.y1 = ((x + y) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
		c.x2 = (((x + 1) - y) * 10 + t->plx) * t->e;
		c.y2 = (((x + 1) + y) * 5 - t->t[y][x + 1] * t->h + t->ply) * t->e;
		c.color = (abs(t->t[y][x + 1]) > abs(t->m)) ? t->ct[abs(t->t[y][x + 1])
			* 8 / abs(t->size_max) + 1] : 0x0000FF;
		draw(c, t);
	}
	if (y < t->size_y - 1)
	{
		c.x1 = ((x - y) * 10 + t->plx) * t->e;
		c.y1 = ((x + y) * 5 - t->t[y][x] * t->h + t->ply) * t->e;
		c.x2 = ((x - (y + 1)) * 10 + t->plx) * t->e;
		c.y2 = ((x + (y + 1)) * 5 - t->t[y + 1][x] * t->h + t->ply) * t->e;
		c.color = (abs(t->t[y + 1][x]) > abs(t->m)) ? t->ct[abs(t->t[y + 1][x])
			* 8 / abs(t->size_max) + 1] : 0x0000FF;
		draw(c, t);
	}
}
