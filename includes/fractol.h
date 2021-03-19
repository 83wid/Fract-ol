/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:15:49 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/08 05:25:50 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <math.h>
# include "mlx.h"
# include <pthread.h>

typedef struct	s_xpoint
{
	double	r;
	double	i;
}				t_xpoint;

typedef struct	s_npoint
{
	int		x;
	int		y;
}				t_npoint;

typedef struct	s_img
{
	void	*ptr;
	int		*str;
	int		bpp;
	int		endian;
	int		sl;
}				t_img;

typedef struct	s_mouse
{
	double	x;
	double	y;
}				t_mouse;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
	int		m;
}				t_color;

typedef struct	s_thread
{
	t_xpoint	z;
	t_xpoint	c;
	t_xpoint	z0;
	t_npoint	p;
}				t_thread;

typedef struct	s_center
{
	double	r_min;
	double	i_min;
	double	r_max;
	double	i_max;
}				t_center;

typedef struct	s_mlx
{
	t_xpoint	c;
	t_img		img;
	t_mouse		mouse;
	t_xpoint	move;
	t_color		color;
	double		zoom;
	double		zoom_factor;
	t_center	center;
	double		r;
	void		*init;
	void		*win;
	int			fract;
	int			width;
	int			height;
	int			max_iter;
	int			pause;
	int			pow;
}				t_mlx;

/*
 ** COMPLEX CALCS
*/
t_xpoint		add(t_xpoint a, t_xpoint b);
t_xpoint		power(t_xpoint a, t_xpoint b);
void			complex_abs(t_xpoint *z);
t_xpoint		sqr(t_xpoint a);
t_xpoint		sqr_bar(t_xpoint a);
t_xpoint		pow3(t_xpoint a);
t_xpoint		pow4(t_xpoint a);
t_xpoint		pow5(t_xpoint a);
t_xpoint		pow6(t_xpoint a);
t_xpoint		power_calc(t_mlx mlx, t_xpoint z);
double			mod(t_xpoint z);
/*
 **INIT
*/
void			init_mlx(t_mlx *mlx, int w, int h, int	fract);
t_xpoint		init_complex(t_mlx mlx, t_thread thread);
/*
 **ZOOM
*/
void			zoom(t_mlx *mlx, double x, double y);
/*
 ** 	SETS
*/
void			julia_threading(t_mlx *mlx);
void			mandelbrot_threading(t_mlx *mlx);
void			julia_bar_threading(t_mlx *mlx);
void			tricorn_threading(t_mlx *mlx);
/*
 ** 	FRACT_OPS
*/
void			fractol(t_mlx *mlx);
void			menu(t_mlx mlx);
double			map(int pos, int max_width, double min_scope, double range);
void			fill_pixel(t_mlx *mlx, int x, int y, int color);
/*
 ** 	KEYS
*/
int				key_press(int code, t_mlx *mlx);
int				ft_close(t_mlx *mlx);
void			total_exit(t_mlx *mlx);
/*
 ** 	MOUSE
*/
int				mouse_move(int x, int y, t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
/*
 ** 	COLOR
*/
int				color(int iter, t_mlx mlx);
#endif
