/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_fractals2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:39:28 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/03 18:39:49 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ship_iter(float x0, float y0, int maxiter)
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
		y = (fabs(x) + fabs(x)) * fabs(y) + y0;
		x = x2 - y2 + x0;
		x2 = fabs(x) * fabs(x);
		y2 = y * y;
		iter += 1;
	}
	return (iter);
}

void	flame_ship(t_var *vars)
{
	while (vars->pixel[1] < HEIGHT)
	{
		vars->pixel[0] = 0;
		while (vars->pixel[0] < WIDTH)
		{
			if (vars->pixel[0] < WIDTH / 2)
			{
				paint_bw(vars, ship_iter(((vars->pixel[0] - WIDTH / 2)
							+ vars->offset[0]) * (vars->paso) + vars->ajuste[0],
						(-((HEIGHT / 2 - vars->pixel[1]) + vars->offset[1])
							* (vars->paso)) + vars->ajuste[1], vars->maxiter));
			}
			else
			{
				paint_bw(vars, ship_iter(((vars->pixel[0] - WIDTH / 2)
							+ vars->offset[0]) * (vars->paso) + vars->ajuste[0],
						(-((HEIGHT / 2 - vars->pixel[1]) + vars->offset[1])
							* (vars->paso)) + vars->ajuste[1], vars->maxiter));
			}
			vars->pixel[0] += 1;
		}
		vars->pixel[1] += 1;
	}
}
