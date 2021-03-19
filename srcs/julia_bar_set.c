/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bar_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:30:28 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/07 00:05:04 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*julia_bar_1(void *param)
{
	t_thread	thread;
	int			n;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	thread.p.x = -1;
	while (++thread.p.x < mlx->width / 2)
	{
		thread.p.y = -1;
		while (++thread.p.y < mlx->width / 2)
		{
			thread.z0 = init_complex(*mlx, thread);
			n = 0;
			while (++n < mlx->max_iter)
			{
				thread.z = add(sqr_bar(thread.z0), add(thread.c, mlx->c));
				if (mod(thread.z) > mlx->r)
					break ;
				thread.z0 = thread.z;
			}
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void		*julia_bar_2(void *param)
{
	t_thread	thread;
	int			n;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	thread.p.x = mlx->width / 2 - 1;
	while (++thread.p.x < mlx->width)
	{
		thread.p.y = -1;
		while (++thread.p.y < mlx->width / 2)
		{
			thread.z0 = init_complex(*mlx, thread);
			n = 0;
			while (++n < mlx->max_iter)
			{
				thread.z = add(sqr_bar(thread.z0), add(thread.c, mlx->c));
				if (mod(thread.z) > mlx->r)
					break ;
				thread.z0 = thread.z;
			}
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void		*julia_bar_3(void *param)
{
	t_thread	thread;
	int			n;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	thread.p.x = -1;
	while (++thread.p.x < mlx->width / 2)
	{
		thread.p.y = mlx->width / 2 - 1;
		while (++thread.p.y < mlx->width)
		{
			thread.z0 = init_complex(*mlx, thread);
			n = 0;
			while (++n < mlx->max_iter)
			{
				thread.z = add(sqr_bar(thread.z0), add(thread.c, mlx->c));
				if (mod(thread.z) > mlx->r)
					break ;
				thread.z0 = thread.z;
			}
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void		*julia_bar_4(void *param)
{
	t_thread	thread;
	int			n;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	thread.p.x = mlx->width / 2 - 1;
	while (++thread.p.x < mlx->width)
	{
		thread.p.y = mlx->width / 2 - 1;
		while (++thread.p.y < mlx->width)
		{
			thread.z0 = init_complex(*mlx, thread);
			n = 0;
			while (++n < mlx->max_iter)
			{
				thread.z = add(sqr_bar(thread.z0), add(thread.c, mlx->c));
				if (mod(thread.z) > mlx->r)
					break ;
				thread.z0 = thread.z;
			}
			fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void		julia_bar_threading(t_mlx *mlx)
{
	pthread_t		tab[4];

	pthread_create(&tab[0], NULL, &julia_bar_1, mlx);
	pthread_create(&tab[1], NULL, &julia_bar_2, mlx);
	pthread_create(&tab[2], NULL, &julia_bar_3, mlx);
	pthread_create(&tab[3], NULL, &julia_bar_4, mlx);
	pthread_join(tab[0], NULL);
	pthread_join(tab[1], NULL);
	pthread_join(tab[2], NULL);
	pthread_join(tab[3], NULL);
}
