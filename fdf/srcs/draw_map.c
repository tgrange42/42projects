/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 20:13:41 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/28 17:44:25 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	8 = 91
**	2 = 84
**	esc = 53
**	+ = 69
**	- = 78
**	w = 13
**	s = 1
**	d = 2
**	a = 0
*/

int		key_gest(int key, t_coor *t)
{
	if (key == 53)
		exit_fdf(t);
	else if (key == 91)
		t->h += 0.001 * t->modi;
	else if (key == 84)
		t->h -= 0.001 * t->modi;
	else if (key == 69)
		t->e += 0.05 * t->modi;
	else if (key == 78 && t->e > 0.1 * t->modi)
		t->e -= 0.05 * t->modi;
	else if (key == 2)
		t->plx -= 10 * t->modi;
	else if (key == 0)
		t->plx += 10 * t->modi;
	else if (key == 1)
		t->ply -= 10 * t->modi;
	else if (key == 13)
		t->ply += 10 * t->modi;
	else if (key == 24)
		t->modi++;
	else if (key == 27 && t->modi > 1)
		t->modi--;
	mlx_clear_window(t->mlx, t->win);
	loop_draw(t);
	return (0);
}

void	init_draw(t_coor *t)
{
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, 1000, 1000, "FDF");
	loop_draw(t);
}

void	loop_draw(t_coor *t)
{
	int		x;
	int		y;

	y = 0;
	t->img_ptr = mlx_new_image(t->mlx, 1000, 1000);
	t->image = mlx_get_data_addr(t->img_ptr, &t->bpp, &t->win_size, &t->endian);
	while (y < t->size_y)
	{
		x = 0;
		while (x < t->size_x)
		{
			trace_line(x, y, t);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(t->mlx, t->win, t->img_ptr, 0, 0);
	mlx_hook(t->win, 2, 3, key_gest, t);
	mlx_loop(t->mlx);
}
