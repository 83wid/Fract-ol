/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 01:00:40 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/08 04:29:08 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	menu(t_mlx mlx)
{
	mlx_string_put(mlx.init, mlx.win, 20, 820, 0xFF, "TO CONTROLE PRESS:");
	mlx_string_put(mlx.init, mlx.win, 80, 845, 0xFFFF, "R : RESET");
	mlx_string_put(mlx.init, mlx.win, 80, 870, 0xFFFF, "P : POLYNOME POWER");
	mlx_string_put(mlx.init, mlx.win, 80, 895, 0xFFFF, "M : COLOR METHOD:");
	mlx_string_put(mlx.init, mlx.win, 80, 920, 0xFFFF,\
			"+/- : HANDLE ITERATION");
	mlx_string_put(mlx.init, mlx.win, 80, 945, 0xFFFF,\
			"MOUSE LEFT: HANDLE MOVEMENTS");
	mlx_string_put(mlx.init, mlx.win, 80, 970, 0xFFFF,\
			"MOUSE WHEEL: HANDLE ZOOM");
	mlx_string_put(mlx.init, mlx.win, 500, 820, 0xFF, "TO CHANGE SET PRESS:");
	mlx_string_put(mlx.init, mlx.win, 580, 845, 0xFFFF, "1 : MANDEL BROT");
	mlx_string_put(mlx.init, mlx.win, 580, 870, 0xFFFF, "2 : JULIA");
	mlx_string_put(mlx.init, mlx.win, 580, 895, 0xFFFF, "3 : TRICORN");
	mlx_string_put(mlx.init, mlx.win, 580, 920, 0xFFFF, "4 : JULIA BAR");
	mlx_string_put(mlx.init, mlx.win, 580, 945, 0xFFFF, "5 : BURNING SHIP");
	mlx_string_put(mlx.init, mlx.win, 580, 970, 0xFFFF, "6 : BURNING JULIA");
}

void	win_vars(t_mlx *mlx)
{
	char	*x;
	char	*y;
	char	*iter;
	char	*zoom;

	x = ft_itoa(mlx->mouse.x);
	y = ft_itoa(mlx->mouse.y);
	zoom = ft_itoa(mlx->zoom_factor);
	iter = ft_itoa(mlx->max_iter);
	mlx_string_put(mlx->init, mlx->win, 20, 20, 0xFFFFFF, "MOUSE X:");
	mlx_string_put(mlx->init, mlx->win, 100, 20, 0xFFFFFF, x);
	mlx_string_put(mlx->init, mlx->win, 20, 50, 0xFFFFFF, "MOUSE Y:");
	mlx_string_put(mlx->init, mlx->win, 100, 50, 0xFFFFFF, y);
	mlx_string_put(mlx->init, mlx->win, 700, 750, 0xFFFFFF, "ITER:");
	mlx_string_put(mlx->init, mlx->win, 750, 750, 0xFFFFFF, iter);
	mlx_string_put(mlx->init, mlx->win, 20, 750, 0xFFFFFF, "ZOOM:");
	mlx_string_put(mlx->init, mlx->win, 90, 750, 0xFFFFFF, "X");
	mlx_string_put(mlx->init, mlx->win, 100, 750, 0xFFFFFF, zoom);
	free(x);
	free(y);
	free(iter);
	free(zoom);
}

void	fractol(t_mlx *mlx)
{
	mlx->fract == 1 || mlx->fract == 5 ? mandelbrot_threading(mlx) : 0;
	mlx->fract == 2 || mlx->fract == 6 ? julia_threading(mlx) : 0;
	mlx->fract == 3 ? tricorn_threading(mlx) : 0;
	mlx->fract == 4 ? julia_bar_threading(mlx) : 0;
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.ptr, 0, 0);
	win_vars(mlx);
}
