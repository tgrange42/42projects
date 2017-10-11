/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawfrac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:59:00 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/11 12:45:54 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	drawtest(t_mlx *t)
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	zoom;
	float	it_max;
	float	imx;
	float	imy;
	float	x;
	float	y;
	float	cr;
	float	ci;
	float	zr;
	float	zi;
	float	i;
	float	tmp;

	x = 0;
	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoom = 300;
	it_max = 50;
	imx = (x2 - x1) * zoom;
	imy = (y2 - y1) * zoom;
	while (x < imx)
	{
		y = 0;
		while (y < imy)
		{
			cr = x / zoom + x1;
			ci = y / zoom + y1;
			zr = 0;
			zi = 0;
			i = 0;
			while (zr * zr + zi * zi < 4 && i < it_max)
			{
				tmp = zr;
				zr = zr * zr - zi * zi + cr;
				zi = 2 * zi * tmp + ci;
				i++;
			}
			if (i == it_max)
				pixel_put(x, y, t, 255, 80, 80);
			else
				pixel_put(x, y, t, i * 255 / it_max, 0, 0);
			y++;
		}
		x++;
	}
			// ft_putstr("\ny = ");
			// ft_putnbr(zr * zr + zi * zi);
}

void	draw(void)
{
	t_mlx	*t;

	if (!(t = (t_mlx *)ft_memalloc(sizeof(t))))
		return ;
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, 1000, 1000, "MDR");
	t->img_ptr = mlx_new_image(t->mlx, 1000, 1000);
	t->image = mlx_get_data_addr(t->img_ptr, &t->bpp, &t->win_size, &t->endian);
	drawtest(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img_ptr, 0, 0);
	mlx_loop(t->mlx);
}
