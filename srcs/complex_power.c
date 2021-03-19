/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:49:01 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/07 00:10:23 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_xpoint	sqr(t_xpoint a)
{
	return (power(a, a));
}

t_xpoint	pow3(t_xpoint a)
{
	t_xpoint	c;

	c = sqr(a);
	return (power(c, a));
}

t_xpoint	pow4(t_xpoint a)
{
	t_xpoint	c;

	c = pow3(a);
	return (power(c, a));
}

t_xpoint	pow5(t_xpoint a)
{
	t_xpoint	c;

	c = pow4(a);
	return (power(c, a));
}

t_xpoint	pow6(t_xpoint a)
{
	t_xpoint	c;

	c = pow5(a);
	return (power(c, a));
}
