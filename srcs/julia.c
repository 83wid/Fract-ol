/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 00:45:35 by nabouzah          #+#    #+#             */
/*   Updated: 2020/01/07 03:51:38 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*julia_1(void *param)
{
	int			n;
	t_thread	t;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	t.p.x = -1;
	while (++t.p.x < mlx->width / 2)
	{
		t.p.y = -1;
		while (++t.p.y < mlx->width / 2)
		{
			t.z0 = init_complex(*mlx, t);
			n = 0;
			while (++n < mlx->max_iter)
			{
				mlx->fract == 6 ? complex_abs(&t.z0) : 0;
				t.z = add(power_calc(*mlx, t.z0), add(t.c, mlx->c));
				if (mod(t.z) > mlx->r)
					break ;
				t.z0 = t.z;
			}
			fill_pixel(mlx, t.p.x, t.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	*julia_2(void *param)
{
	int			n;
	t_thread	t;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	t.p.x = -1;
	while (++t.p.x < mlx->width / 2)
	{
		t.p.y = mlx->width / 2 - 1;
		while (++t.p.y < mlx->width)
		{
			t.z0 = init_complex(*mlx, t);
			n = 0;
			while (++n < mlx->max_iter)
			{
				mlx->fract == 6 ? complex_abs(&t.z0) : 0;
				t.z = add(power_calc(*mlx, t.z0), add(t.c, mlx->c));
				if (mod(t.z) > mlx->r)
					break ;
				t.z0 = t.z;
			}
			fill_pixel(mlx, t.p.x, t.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	*julia_3(void *param)
{
	int			n;
	t_thread	t;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	t.p.x = mlx->width / 2 - 1;
	while (++t.p.x < mlx->width)
	{
		t.p.y = -1;
		while (++t.p.y < mlx->width / 2)
		{
			t.z0 = init_complex(*mlx, t);
			n = 0;
			while (++n < mlx->max_iter)
			{
				mlx->fract == 6 ? complex_abs(&t.z0) : 0;
				t.z = add(power_calc(*mlx, t.z0), add(t.c, mlx->c));
				if (mod(t.z) > mlx->r)
					break ;
				t.z0 = t.z;
			}
			fill_pixel(mlx, t.p.x, t.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	*julia_4(void *param)
{
	int			n;
	t_thread	t;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	t.p.x = mlx->width / 2 - 1;
	while (++t.p.x < mlx->width)
	{
		t.p.y = mlx->width / 2 - 1;
		while (++t.p.y < mlx->width)
		{
			t.z0 = init_complex(*mlx, t);
			n = 0;
			while (++n < mlx->max_iter)
			{
				mlx->fract == 6 ? complex_abs(&t.z0) : 0;
				t.z = add(power_calc(*mlx, t.z0), add(t.c, mlx->c));
				if (mod(t.z) > mlx->r)
					break ;
				t.z0 = t.z;
			}
			fill_pixel(mlx, t.p.x, t.p.y, color(n, *mlx));
		}
	}
	return (NULL);
}

void	julia_threading(t_mlx *mlx)
{
	pthread_t		tab[4];

	pthread_create(&tab[0], NULL, &julia_1, mlx);
	pthread_create(&tab[1], NULL, &julia_2, mlx);
	pthread_create(&tab[2], NULL, &julia_3, mlx);
	pthread_create(&tab[3], NULL, &julia_4, mlx);
	pthread_join(tab[0], NULL);
	pthread_join(tab[1], NULL);
	pthread_join(tab[2], NULL);
	pthread_join(tab[3], NULL);
}
