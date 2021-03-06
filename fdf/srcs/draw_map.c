/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 20:13:41 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/09 18:37:12 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_instr(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 5, 5, 0x00FF00, "************************");
	mlx_string_put(mlx, win, 5, 25, 0x00FF00, "^ for stronger altitude");
	mlx_string_put(mlx, win, 5, 45, 0x00FF00, "v for weaker altitude");
	mlx_string_put(mlx, win, 5, 65, 0x00FF00, "8 for higher altitude");
	mlx_string_put(mlx, win, 5, 85, 0x00FF00, "2 for lower altitude");
	mlx_string_put(mlx, win, 5, 105, 0x00FF00, "A, S, D, W to move");
	mlx_string_put(mlx, win, 5, 125, 0x00FF00, "+ to zoom in");
	mlx_string_put(mlx, win, 5, 145, 0x00FF00, "- to zoom out");
	mlx_string_put(mlx, win, 5, 165, 0x00FF00, "ESC to quit");
	mlx_string_put(mlx, win, 5, 185, 0x00FF00, "************************");
}

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

int		key_gest2(int key, t_coor *t)
{
	if (key == 87)
		t->proj *= -1;
	else if (key == 65)
		t->cube *= -1;
	loop_draw(t);
	return (0);
}

int		key_gest(int key, t_coor *t)
{
	if (key == 53)
		exit_fdf(t);
	else if (key == 91)
		t->h += 0.001 * t->modi;
	else if (key == 84)
		t->h -= 0.001 * t->modi;
	else if (key == 69)
		t->e += 0.05;
	else if (key == 78 && t->e > 0.1)
		t->e -= 0.05;
	else if (key == 2)
		t->plx -= 10;
	else if (key == 0)
		t->plx += 10;
	else if (key == 1)
		t->ply -= 10;
	else if (key == 13)
		t->ply += 10;
	else if (key == 126)
		t->modi++;
	else if (key == 125 && t->modi > 1)
		t->modi--;
	loop_draw(t);
	return (0);
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
			which_tracing(x, y, t);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(t->mlx, t->win, t->img_ptr, 0, 0);
	mlx_destroy_image(t->mlx, t->img_ptr);
	put_instr(t->mlx, t->win);
	mlx_hook(t->win, 2, 3, key_gest, t);
	mlx_key_hook(t->win, key_gest2, t);
	mlx_loop(t->mlx);
}
