/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:44:07 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/03 18:48:20 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	configure_zoom_key(keys_t key, t_var *vars)
{
	if (key == 334)
	{
		vars->max_y = vars->max_y / 1.2;
		vars->offset[0] *= 1.2;
		vars->offset[1] *= 1.2;
	}
	if (key == 333)
	{
		vars->offset[0] /= 1.2;
		vars->offset[1] /= 1.2;
		vars->max_y = vars->max_y * 1.2;
	}
	vars->max_x = vars->max_y * ((float)WIDTH / (float)HEIGHT);
	vars->paso = (2 * vars->max_y) / (float)HEIGHT;
}

void	key_options(mlx_key_data_t keydata, t_var *vars)
{
	if (((keydata.key == 334) || (keydata.key == 333)) && keydata.action == 1)
		configure_zoom_key(keydata.key, vars);
	if (keydata.key == 262 && keydata.action == 1)
		vars->offset[0] += (50);
	if (keydata.key == 263 && keydata.action == 1)
		vars->offset[0] -= (50);
	if (keydata.key == 265 && keydata.action == 1)
		vars->offset[1] += (50);
	if (keydata.key == 264 && keydata.action == 1)
		vars->offset[1] -= (50);
	if (keydata.key == 49 && keydata.action == 1)
		vars->color_t = 0;
	if (keydata.key == 50 && keydata.action == 1)
		vars->color_t = 1;
	if (keydata.key == 51 && keydata.action == 1)
		vars->color_t = 2;
	if (keydata.key == 90 && keydata.action == 1)
		vars->fractal = -1;
	if (keydata.key == 88 && keydata.action == 1)
		vars->fractal = 0;
	if (keydata.key == 67 && keydata.action == 1)
		vars->fractal = 1;
	if (keydata.key == 257 && keydata.action == 1)
		vars->axis *= -1;
}

void	key_functions(mlx_key_data_t keydata, void *param)
{
	t_var	*vars;

	vars = (t_var *)param;
	if (keydata.key == 256 && keydata.action == 1)
		mlx_close_window(vars->mlx);
	else if (keydata.action == 1)
	{
		key_options(keydata, vars);
		create_img(vars);
	}
}

void	configure_offset_zoom(t_var *vars, mouse_key_t button)
{
	if (vars->pos->x > WIDTH / 2)
		vars->offset[0] += (vars->pos->x - WIDTH / 2);
	else
		vars->offset[0] -= (WIDTH / 2 - vars->pos->x);
	if (vars->pos->y < HEIGHT / 2)
		vars->offset[1] += (HEIGHT / 2 - vars->pos->y);
	else
		vars->offset[1] -= (vars->pos->y - HEIGHT / 2);
	if (button == 0)
	{
		vars->max_y = vars->max_y / 1.2;
		vars->offset[0] *= 1.2;
		vars->offset[1] *= 1.2;
	}
	if (button == 1)
	{
		vars->max_y = vars->max_y * 1.2;
		vars->offset[0] /= 1.2;
		vars->offset[1] /= 1.2;
	}
}
