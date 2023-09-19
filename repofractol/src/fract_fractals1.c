/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:37:43 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/03 18:38:58 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mandelbrot_iter(float x0, float y0, int maxiter)
{
	int		iter;
	float	x2;
	float	y2;
	float	x;
	float	y;

	x2 = 0;
	y2 = 0;
	x = 0;
	y = 0;
	iter = 0;
	while (x2 + y2 <= 4 && iter < maxiter)
	{
		y = (x + x) * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
		iter += 1;
	}
	return (iter);
}

int	julia_iter(float zx0, float zy0, int maxiter, float *c)
{
	int		iter;
	float	zx2;
	float	zy2;
	float	zx;
	float	zy;

	zx = zx0;
	zx2 = zx * zx;
	zy = zy0;
	zy2 = zy * zy;
	iter = 0;
	while (zx2 + zy2 <= 4 && iter < maxiter)
	{
		zy = zy * (zx + zx) + c[1];
		zx = zx2 - zy2 + c[0];
		zx2 = zx * zx;
		zy2 = zy * zy;
		iter += 1;
	}
	return (iter);
}

void	mandelbrot(t_var *vars)
{
	while (vars->pixel[1] < HEIGHT)
	{
		vars->pixel[0] = 0;
		while (vars->pixel[0] < WIDTH)
		{
			if (vars->pixel[0] < WIDTH / 2)
			{
				paint_bw(vars, mandelbrot_iter(((vars->pixel[0] - WIDTH / 2)
							+ vars->offset[0]) * (vars->paso) + vars->ajuste[0],
						((HEIGHT / 2 - vars->pixel[1]) + vars->offset[1])
						* (vars->paso) - vars->ajuste[1], vars->maxiter));
			}
			else
			{
				paint_bw(vars, mandelbrot_iter(((vars->pixel[0] - WIDTH / 2)
							+ vars->offset[0]) * (vars->paso) + vars->ajuste[0],
						((vars->pixel[1] - HEIGHT / 2) - vars->offset[1])
						* (vars->paso) + vars->ajuste[1], vars->maxiter));
			}
			vars->pixel[0] += 1;
		}
		vars->pixel[1] += 1;
	}
}

void	julia(t_var *vars)
{
	while (vars->pixel[1] < HEIGHT)
	{
		vars->pixel[0] = 0;
		while (vars->pixel[0] < WIDTH)
		{
			if (vars->pixel[0] < WIDTH / 2)
			{
				paint_bw(vars, julia_iter(((vars->pixel[0] - WIDTH / 2)
							+ vars->offset[0]) * (vars->paso) + vars->ajuste[0],
						(-((HEIGHT / 2 - vars->pixel[1]) + vars->offset[1])
							* (vars->paso)) + vars->ajuste[1], vars->maxiter,
						vars->c));
			}
			else
			{
				paint_bw(vars, julia_iter(((vars->pixel[0] - WIDTH / 2)
							+ vars->offset[0]) * (vars->paso) + vars->ajuste[0],
						(-((HEIGHT / 2 - vars->pixel[1]) + vars->offset[1])
							* (vars->paso)) + vars->ajuste[1], vars->maxiter,
						vars->c));
			}
			vars->pixel[0] += 1;
		}
		vars->pixel[1] += 1;
	}
}
