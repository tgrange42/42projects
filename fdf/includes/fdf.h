/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 17:33:56 by tgrange           #+#    #+#             */
/*   Updated: 2017/10/09 18:31:10 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

/*
**	structs
*/

typedef struct		s_coor
{
	int				**t;
	int				size_y;
	int				size_x;
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*image;
	float			e;
	float			h;
	int				ply;
	int				plx;
	int				endian;
	int				bpp;
	int				win_size;
	int				modi;
	int				size_max;
	int				*ct;
	int				m;
	int				proj;
	int				cube;
}					t_coor;

typedef struct		s_tmp
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				color;
}					t_tmp;

/*
**	draw_map.c
*/

void				init_draw(t_coor *t);
void				loop_draw(t_coor *t);

/*
**	fdf.c
*/


/*
**	get_map.c
*/

char				***get_map(char *map_path);

/*
**	tools.c
*/

void				del_tabstr(char ***str);
void				del_inttab(int ***tab);
void				del_triple_tab(char ****tab);
void				convert_map(char ***map, t_coor *t);

/*
**	tools2.c
*/

int					tri_tablen(char ***tab);
void				exit_fdf(t_coor *t);
void				plus_plus(int *a, int b, int *c, int d);
void				exit_fdf_error(char ***map, int error, char *name);

/*
**	tools_draw.c
*/

void				draw2(t_tmp c, t_coor *t, int e);
void				draw1(t_tmp c, t_coor *t, int e);
void				pixel_put(int x, int y, t_coor *t, int color);
void				draw(t_tmp c, t_coor *t);
void				trace_line(int x, int y, t_coor *t);

/*
**	tools_draw2.c
*/

void				trace_line2(int x, int y, t_coor *t);
void				trace_line3(int x, int y, t_coor *t);

/*
**	tools_draw3.c
*/

void				which_tracing(int x, int y, t_coor *t);
void				trace_line6(int x, int y, t_coor *t);

#endif
