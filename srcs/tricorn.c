/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 00:45:48 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/07 05:09:14 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*tricorn_1(void *param)
{
	t_thread	thread;
	int			n;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	thread.p.y = -1;
	while (++thread.p.y < mlx->width / 2)
	{
		thread.p.x = -1;
		while (++thread.p.x < mlx->width / 2)
		{
			thread.c = init_complex(*mlx, thread);
			thread.z = (t_xpoint){0, 0};
			n = 0;
			while (mod(thread.z) <= mlx->r && ++n < mlx->max_iter)
				thread.z = add(sqr_bar(thread.z), thread.c);
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	*tricorn_2(void *param)
{
	t_thread	thread;
	int			n;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	thread.p.y = -1;
	while (++thread.p.y < mlx->width / 2)
	{
		thread.p.x = mlx->width / 2 - 1;
		while (++thread.p.x < mlx->width)
		{
			thread.c = init_complex(*mlx, thread);
			thread.z = (t_xpoint){0, 0};
			n = 0;
			while (mod(thread.z) <= mlx->r && ++n < mlx->max_iter)
				thread.z = add(sqr_bar(thread.z), thread.c);
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	*tricorn_3(void *param)
{
	t_thread	thread;
	int			n;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	thread.p.y = mlx->width / 2 - 1;
	while (++thread.p.y < mlx->width)
	{
		thread.p.x = -1;
		while (++thread.p.x < mlx->width / 2)
		{
			thread.c = init_complex(*mlx, thread);
			thread.z = (t_xpoint){0, 0};
			n = 0;
			while (mod(thread.z) <= mlx->r && ++n < mlx->max_iter)
				thread.z = add(sqr_bar(thread.z), thread.c);
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	*tricorn_4(void *param)
{
	t_thread	thread;
	int			n;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	thread.p.y = mlx->width / 2 - 1;
	while (++thread.p.y < mlx->width)
	{
		thread.p.x = mlx->width / 2 - 1;
		while (++thread.p.x < mlx->width)
		{
			thread.c = init_complex(*mlx, thread);
			thread.z = (t_xpoint){0, 0};
			n = 0;
			while (mod(thread.z) <= mlx->r && ++n < mlx->max_iter)
				thread.z = add(sqr_bar(thread.z), thread.c);
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	tricorn_threading(t_mlx *mlx)
{
	pthread_t		tab[4];

	pthread_create(&tab[0], NULL, &tricorn_1, mlx);
	pthread_create(&tab[1], NULL, &tricorn_2, mlx);
	pthread_create(&tab[2], NULL, &tricorn_3, mlx);
	pthread_create(&tab[3], NULL, &tricorn_4, mlx);
	pthread_join(tab[0], NULL);
	pthread_join(tab[1], NULL);
	pthread_join(tab[2], NULL);
	pthread_join(tab[3], NULL);
}
