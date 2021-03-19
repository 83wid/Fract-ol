/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 22:39:00 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/08 04:25:27 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		init_mlx(t_mlx *mlx, int w, int h, int fract)
{
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, w, h, "FRATC'OL");
	mlx->width = w;
	mlx->height = h;
	mlx->img.ptr = mlx_new_image(mlx->init, mlx->width, mlx->width);
	mlx->img.str = (int *)mlx_get_data_addr(mlx->img.ptr,\
						&mlx->img.bpp, &mlx->img.sl, &mlx->img.endian);
	mlx->center = (t_center){-2, -2, 2, 2};
	mlx->zoom = 1;
	mlx->zoom_factor = 0;
	mlx->move = (t_xpoint){0, 0};
	mlx->color = (t_color){0, 1, 2, 1};
	mlx->pause = 0;
	if (fract == 2 && (mlx->c.r = -0.26))
		mlx->c.i = 0.7;
	if (fract == 4 && (mlx->c.r = 0.34))
		mlx->c.i = 0.4;
	if (fract == 6 && (mlx->c.r = 0.7))
		mlx->c.i = -1.1;
	mlx->fract = fract;
	mlx->max_iter = 50;
	mlx->r = 4;
	mlx->pow = 2;
}

t_xpoint	init_complex(t_mlx mlx, t_thread thread)
{
	t_xpoint	c;

	c.r = map(thread.p.x, mlx.width, mlx.center.r_min + mlx.move.r,\
			(mlx.center.r_max + mlx.move.r));
	c.i = map(thread.p.y, mlx.width, mlx.center.i_min + mlx.move.i,\
			(mlx.center.i_max + mlx.move.i));
	return (c);
}
