/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 07:08:56 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/07 04:56:14 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		color(int iter, t_mlx mlx)
{
	double			per;
	int				ret;
	unsigned char	*rgb;
	int				*ptr;

	if (iter > mlx.max_iter)
		return (0);
	per = (double)iter / (double)mlx.max_iter;
	ptr = &ret;
	rgb = (unsigned char *)ptr;
	rgb[mlx.color.r] = (char)(9 * (1 - per) * per * per * per * 255);
	rgb[mlx.color.g] = (char)(15 * (1 - per) * (1 - per) * per * per * 255);
	rgb[mlx.color.b] =\
			(char)(8.5 * (1 - per) * (1 - per) * (1 - per) * per * 255);
	rgb[3] = 0;
	return (ret);
}
