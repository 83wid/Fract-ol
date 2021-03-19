/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:19:39 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/07 03:52:56 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*mandelbrot_1(void *param)
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
			{
				mlx->fract == 5 ? complex_abs(&thread.z) : 0;
				thread.z = add(power_calc(*mlx, thread.z), thread.c);
			}
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	*mandelbrot_2(void *param)
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
			{
				mlx->fract == 5 ? complex_abs(&thread.z) : 0;
				thread.z = add(power_calc(*mlx, thread.z), thread.c);
			}
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	*mandelbrot_3(void *param)
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
			{
				mlx->fract == 5 ? complex_abs(&thread.z) : 0;
				thread.z = add(power_calc(*mlx, thread.z), thread.c);
			}
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	*mandelbrot_4(void *param)
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
			{
				mlx->fract == 5 ? complex_abs(&thread.z) : 0;
				thread.z = add(power_calc(*mlx, thread.z), thread.c);
			}
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	mandelbrot_threading(t_mlx *mlx)
{
	pthread_t		tab[4];

	pthread_create(&tab[0], NULL, &mandelbrot_1, mlx);
	pthread_create(&tab[1], NULL, &mandelbrot_2, mlx);
	pthread_create(&tab[2], NULL, &mandelbrot_3, mlx);
	pthread_create(&tab[3], NULL, &mandelbrot_4, mlx);
	pthread_join(tab[0], NULL);
	pthread_join(tab[1], NULL);
	pthread_join(tab[2], NULL);
	pthread_join(tab[3], NULL);
}
