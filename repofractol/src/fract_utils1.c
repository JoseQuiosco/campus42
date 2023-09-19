/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:17:24 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/03 18:31:29 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_error_1(t_var *vars)
{
	mlx_terminate(vars->mlx);
	exit(EXIT_FAILURE);
}

void	ft_error_2(t_var *vars)
{
	mlx_delete_image(vars->mlx, vars->img);
	mlx_terminate(vars->mlx);
	exit(EXIT_FAILURE);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int	get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}
