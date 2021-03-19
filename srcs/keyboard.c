/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 00:50:05 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/08 05:07:50 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_close(t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	mlx_destroy_image(mlx->init, mlx->img.ptr);
	mlx_destroy_window(mlx->init, mlx->win);
	exit(-1);
	return (0);
}

int		power_change(int *power)
{
	if (*power == 6)
		return (2);
	else
		return (*power + 1);
}

void	set_fract(int code, t_mlx *mlx)
{
	int	fract;

	fract = mlx->fract;
	code == 83 ? mlx->fract = 1 : 0;
	code == 35 ? mlx->pow = power_change(&mlx->pow) : 0;
	code == 87 ? mlx->fract = 5 : 0;
	if (code == 88)
		mlx->c = (t_xpoint){0.7, -1.1};
	code == 88 ? mlx->fract = 6 : 0;
	code <= 88 && code >= 83 ? mlx->pow = 0 : 0;
	code == 85 ? mlx->fract = 3 : 0;
	if (code == 86)
		mlx->c = (t_xpoint){0.34, 0.4};
	code == 86 ? mlx->fract = 4 : 0;
	if (code == 84)
		mlx->c = (t_xpoint){-0.26, 0.7};
	code == 84 ? mlx->fract = 2 : 0;
	if (fract != mlx->fract || code == 35 || code == 15)
	{
		mlx->zoom_factor = 0;
		mlx->center = (t_center){-2, -2, 2, 2};
	}
}

void	color_change(t_color *color)
{
	if (color->m == 1)
		*color = (t_color){0, 1, 2, 2};
	else if (color->m == 2)
		*color = (t_color){0, 2, 1, 3};
	else if (color->m == 3)
		*color = (t_color){1, 0, 2, 4};
	else if (color->m == 4)
		*color = (t_color){1, 2, 0, 5};
	else if (color->m == 5)
		*color = (t_color){2, 1, 0, 6};
	else if (color->m == 6)
		*color = (t_color){2, 0, 1, 1};
}

int		key_press(int code, t_mlx *mlx)
{
	t_xpoint	per;

	per = (t_xpoint){mlx->center.r_max - mlx->center.r_min,\
		mlx->center.i_max - mlx->center.i_min};
	code == 53 ? ft_close(mlx) : 0;
	code == 123 ? mlx->move.r += per.r / 10 : 0;
	code == 124 ? mlx->move.r -= per.r / 10 : 0;
	code == 125 ? mlx->move.i -= per.i / 10 : 0;
	code == 126 ? mlx->move.i += per.i / 10 : 0;
	code == 46 ? color_change(&mlx->color) : 0;
	if (code == 116 || code == 121)
		mlx->zoom += code == 116 ? 1 : -1;
	code == 69 ? mlx->max_iter *= 2 : 0;
	code == 78 && mlx->max_iter > 1 ? mlx->max_iter /= 2 : 0;
	set_fract(code, mlx);
	fractol(mlx);
	return (1);
}
