/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 01:33:49 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/08 04:25:33 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->pause && (mlx->fract % 2 == 0))
	{
		mlx->c.r = map(x, mlx->width, mlx->center.r_min, mlx->center.r_max);
		mlx->c.i = map(y, mlx->width, mlx->center.i_min, mlx->center.i_max);
	}
	fractol(mlx);
	return (1);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (mlx->fract % 2 == 0)
	{
		if (button == 1)
			mlx->pause = mlx->pause ? 0 : 1;
	}
	if (!(mlx->pause && (mlx->fract % 2 == 0)))
	{
		if (button == 4 && (mlx->zoom = 1.5))
			zoom(mlx, x, y);
		if (button == 5 && (mlx->zoom = 1.0 / 1.5))
			zoom(mlx, x, y);
	}
	fractol(mlx);
	return (1);
}
