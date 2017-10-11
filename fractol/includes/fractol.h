/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:54:51 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/10 17:38:25 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>


typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*image;
	int				endian;
	int				bpp;
	int				win_size;
}					t_mlx;

/*
**	fractol.c
*/

void	draw(void);
void	pixel_put(int x, int y, t_mlx *t, int r, int g, int b);

#endif