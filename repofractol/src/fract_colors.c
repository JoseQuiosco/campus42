/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:36:25 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/03 18:36:37 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	bw(t_var *vars, int iter)
{
	float	scale;
	int		c;

	scale = (float)255 / (float)vars->maxiter;
	c = (int)(iter * scale);
	if (iter < vars->maxiter)
		return (get_rgba(c, c, c, 255));
	if (iter == vars->maxiter)
		return (get_rgba(0, 0, 0, 255));
	return (0);
}

int	fullcolor(t_var *vars, int iter)
{
	float	scale;
	int		c;

	scale = (float)2147483646 / (float)vars->maxiter;
	c = (int)(iter * scale);
	if (iter < vars->maxiter)
		return (get_rgba(get_r(c), get_g(c), get_b(c), get_a(c)));
	if (iter == vars->maxiter)
		return (get_rgba(0, 0, 0, 255));
	return (0);
}

int	othercolor(t_var *vars, int iter)
{
	float	scale;
	int		c;

	scale = (float)255 / (float)vars->maxiter;
	c = (int)(iter * scale);
	if (iter < vars->maxiter)
		return (get_rgba(255 - c, 255 - c, c, 100));
	if (iter == vars->maxiter)
		return (get_rgba(0, 0, 0, 255));
	return (0);
}

void	paint_bw(t_var *vars, int iter)
{
	int		color;

	if (vars->color_t == 0)
		color = bw(vars, iter);
	if (vars->color_t == 1)
		color = fullcolor(vars, iter);
	if (vars->color_t == 2)
		color = othercolor(vars, iter);
	mlx_put_pixel(vars->img, vars->pixel[0], vars->pixel[1], (uint32_t)color);
}
