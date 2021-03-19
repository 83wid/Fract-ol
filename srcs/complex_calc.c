/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 22:26:23 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/07 00:08:03 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_xpoint	add(t_xpoint a, t_xpoint b)
{
	t_xpoint c;

	c.r = a.r + b.r;
	c.i = a.i + b.i;
	return (c);
}

t_xpoint	power(t_xpoint a, t_xpoint b)
{
	t_xpoint	c;

	c.r = a.r * b.r - a.i * b.i;
	c.i = a.r * b.i + b.r * a.i;
	return (c);
}

t_xpoint	power_calc(t_mlx mlx, t_xpoint z)
{
	if (mlx.pow == 2)
		return (sqr(z));
	if (mlx.pow == 3)
		return (pow3(z));
	if (mlx.pow == 4)
		return (pow4(z));
	if (mlx.pow == 5)
		return (pow5(z));
	if (mlx.pow == 6)
		return (pow6(z));
	return (sqr(z));
}

double		mod(t_xpoint z)
{
	return (z.r * z.r + z.i * z.i);
}

void		complex_abs(t_xpoint *z)
{
	if (z->r < 0)
		z->r *= -1;
	if (z->i < 0)
		z->i *= -1;
}
