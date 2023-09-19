/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:45:31 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/03 18:48:31 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mouse_functions(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_var	*vars;

	vars = (t_var *)param;
	mlx_get_mouse_pos(vars->mlx, (int32_t *)&vars->pos->x,
		(int32_t *)&vars->pos->y);
	if (action == 1)
	{
		configure_offset_zoom(vars, button);
		if (mods == MLX_SHIFT)
			ft_printf("SHIFT!!\n");
		vars->max_x = vars->max_y * ((float)WIDTH / (float)HEIGHT);
		vars->paso = (2 * vars->max_y) / (float)HEIGHT;
		create_img(vars);
	}
}

void	ajuste_zoom_google_in(t_var *vars)
{
	float	k;

	k = (0.2 / 1.2);
	if (vars->pos->x > WIDTH / 2 && vars->pos->y < HEIGHT / 2)
	{
		vars->ajuste[0] += k * (vars->pos->x - WIDTH / 2) * (vars->paso);
		vars->ajuste[1] -= k * (HEIGHT / 2 - vars->pos->y) * (vars->paso);
	}
	else if (vars->pos->x < WIDTH / 2 && vars->pos->y < HEIGHT / 2)
	{
		vars->ajuste[0] -= k * (WIDTH / 2 - vars->pos->x) * (vars->paso);
		vars->ajuste[1] -= k * (HEIGHT / 2 - vars->pos->y) * (vars->paso);
	}
	else if (vars->pos->x < WIDTH / 2 && vars->pos->y > HEIGHT / 2)
	{
		vars->ajuste[0] -= k * (WIDTH / 2 - vars->pos->x) * (vars->paso);
		vars->ajuste[1] += k * (vars->pos->y - HEIGHT / 2) * (vars->paso);
	}
	else if (vars->pos->x > WIDTH / 2 && vars->pos->y > HEIGHT / 2)
	{
		vars->ajuste[0] += k * (vars->pos->x - WIDTH / 2) * (vars->paso);
		vars->ajuste[1] += k * (vars->pos->y - HEIGHT / 2) * (vars->paso);
	}
}

void	ajuste_zoom_google_out(t_var *vars)
{
	float	k;

	k = (0.2 / 1.2);
	if (vars->pos->x > WIDTH / 2 && vars->pos->y < HEIGHT / 2)
	{
		vars->ajuste[0] -= k * (vars->pos->x - WIDTH / 2) * (vars->paso);
		vars->ajuste[1] += k * (HEIGHT / 2 - vars->pos->y) * (vars->paso);
	}
	else if (vars->pos->x < WIDTH / 2 && vars->pos->y < HEIGHT / 2)
	{
		vars->ajuste[0] += k * (WIDTH / 2 - vars->pos->x) * (vars->paso);
		vars->ajuste[1] += k * (HEIGHT / 2 - vars->pos->y) * (vars->paso);
	}
	else if (vars->pos->x < WIDTH / 2 && vars->pos->y > HEIGHT / 2)
	{
		vars->ajuste[0] += k * (WIDTH / 2 - vars->pos->x) * (vars->paso);
		vars->ajuste[1] -= k * (vars->pos->y - HEIGHT / 2) * (vars->paso);
	}
	else if (vars->pos->x > WIDTH / 2 && vars->pos->y > HEIGHT / 2)
	{
		vars->ajuste[0] -= k * (vars->pos->x - WIDTH / 2) * (vars->paso);
		vars->ajuste[1] -= k * (vars->pos->y - HEIGHT / 2) * (vars->paso);
	}
}

void	mouse_scroll(double xdelta, double ydelta, void *param)
{
	t_var	*vars;

	vars = (t_var *)param;
	mlx_get_mouse_pos(vars->mlx, (int32_t *)&vars->pos->x,
		(int32_t *)&vars->pos->y);
	if (ydelta > 0)
	{
		ajuste_zoom_google_in(vars);
		vars->max_y = vars->max_y / 1.2;
		vars->offset[0] *= 1.2;
		vars->offset[1] *= 1.2;
		vars->max_x = vars->max_y * ((float)WIDTH / (float)HEIGHT);
		vars->paso = (2 * vars->max_y) / (float)HEIGHT;
	}
	if (ydelta < 0)
	{
		vars->max_y = vars->max_y * 1.2;
		vars->offset[0] /= 1.2;
		vars->offset[1] /= 1.2;
		vars->max_x = vars->max_y * ((float)WIDTH / (float)HEIGHT);
		vars->paso = (2 * vars->max_y) / (float)HEIGHT;
		ajuste_zoom_google_out(vars);
	}
	xdelta = 0;
	create_img(vars);
}
