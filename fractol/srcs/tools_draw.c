/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:17:16 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/10 18:00:59 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel_put(int x, int y, t_mlx *t, int r, int g, int b)
{
	if (x * 4 <= t->win_size && x >= 0 && y * 4 < t->win_size && y >= 0)
	{
		t->image[(((x + y * t->win_size / 4)) * 4)] = (char)(b);
		t->image[(((x + y * t->win_size / 4)) * 4) + 1] = (char)(g);
		t->image[(((x + y * t->win_size / 4)) * 4) + 2] = (char)(r);
	}
}
