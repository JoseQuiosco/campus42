/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:21:56 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/04 13:44:19 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

int	main(int argc, char *argv[])
{
	t_var	vars;
	t_pos	pos;

	if (argc < 2 || argc > 3)
		return (0);
	capture_c(&vars, argc, argv);
	vars.pos = &pos;
	init_vars(&vars);
	vars.mlx = mlx_init(WIDTH, HEIGHT, "Pantalla pasón", 1);
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	if (!vars.img)
		ft_error_1(&vars);
	if (mlx_image_to_window(vars.mlx, vars.img, 0, 0) < 0)
		ft_error_2(&vars);
	print_manual();
	create_img(&vars);
	mlx_mouse_hook(vars.mlx, mouse_functions, &vars);
	mlx_scroll_hook(vars.mlx, mouse_scroll, &vars);
	mlx_key_hook(vars.mlx, key_functions, &vars);
	mlx_loop(vars.mlx);
	mlx_delete_image(vars.mlx, vars.img);
	mlx_terminate(vars.mlx);
	return (0);
}
