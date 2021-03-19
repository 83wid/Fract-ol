/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:24:58 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/08 04:27:36 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	map(int pos, int max_width, double min, double max)
{
	double	range;

	range = max - min;
	return (min + pos * (range / max_width));
}

double	interpolate(double start, double end, double k)
{
	return (start + ((end - start) * k));
}

void	zoom(t_mlx *mlx, double x, double y)
{
	t_xpoint center;

	mlx->zoom_factor += mlx->zoom < 1.0 ? 1 : -1;
	center.r = map(x, mlx->width, mlx->center.r_min, mlx->center.r_max);
	center.i = map(y, mlx->width, mlx->center.i_min, mlx->center.i_max);
	mlx->center.r_min = interpolate(center.r, mlx->center.r_min, mlx->zoom);
	mlx->center.i_min = interpolate(center.i, mlx->center.i_min, mlx->zoom);
	mlx->center.r_max = interpolate(center.r, mlx->center.r_max, mlx->zoom);
	mlx->center.i_max = interpolate(center.i, mlx->center.i_max, mlx->zoom);
}
