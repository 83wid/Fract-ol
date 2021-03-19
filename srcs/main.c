/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 22:29:22 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/08 04:25:42 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_xpoint	sqr_bar(t_xpoint a)
{
	t_xpoint	c;

	c.r = a.r * a.r - a.i * a.i;
	c.i = -2 * a.r * a.i;
	return (c);
}

int			usage(void)
{
	ft_putendl("Usage: ./fractol [option]\noptions:\n1 : Mandelbrot\n2 : Julia\
			\n3 : Tricorn\n4 : Julia Bar\n5 : Burning Ship\n6 : Burning Julia");
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx		mlx;
	int			fract;

	if (ac == 2 && ft_strstr("123456", av[1]) &&\
			(fract = ft_atoi(av[1])) > 0 && fract < 7)
	{
		init_mlx(&mlx, 800, 1000, fract);
		fractol(&mlx);
		menu(mlx);
		mlx_hook(mlx.win, 2, 0, &key_press, &mlx);
		mlx_hook(mlx.win, 17, 0, &ft_close, &mlx);
		mlx_hook(mlx.win, 6, 0, &mouse_move, &mlx);
		mlx_hook(mlx.win, 4, 0, mouse_press, &mlx);
		mlx_loop(mlx.init);
	}
	else
		return (usage());
}
