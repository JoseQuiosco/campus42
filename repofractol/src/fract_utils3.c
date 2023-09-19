/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:41:37 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/03 19:11:28 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_vars(t_var *vars)
{
	vars->maxiter = 100;
	vars->max_y = 1;
	vars->max_x = vars->max_y * ((float)WIDTH / (float)HEIGHT);
	vars->paso = (2 * vars->max_y) / (float)HEIGHT;
	vars->offset[0] = 0;
	vars->offset[1] = 0;
	vars->ajuste[0] = 0;
	vars->ajuste[1] = 0;
	vars->pos->x = 0;
	vars->pos->y = 0;
	vars->color_t = 0;
	vars->fractal = -1;
	vars->axis = -1;
}

void	capture_c(t_var *vars, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argv[1][i] == '-' || argv[1][i] == '+')
		i++;
	while (i < (int)ft_strlen(argv[1]) && (ft_isdigit(argv[1][i])
		|| argv[1][i] == '.'))
		i++;
	if (i != (int)ft_strlen(argv[1]))
		exit(0);
	vars->c[0] = my_atof(argv[1]);
	if (argc == 2)
		vars->c[1] = 0;
	else
	{
		i = 0;
		if (argv[2][i] == '-' || argv[2][i] == '+')
			i++;
		while (i < (int)ft_strlen(argv[2]) && (ft_isdigit(argv[2][i])
			|| argv[2][i] == '.'))
			i++;
		if (i != (int)ft_strlen(argv[2]))
			exit(0);
		vars->c[1] = my_atof(argv[2]);
	}
}

void	print_manual(void)
{
	ft_printf("\n>------------    CONTROLES    ----------<\n\n");
	ft_printf("-------------     TECLADO     -----------\n\n");
	ft_printf("CURSORES     : 	Movimiento por el fractal.\n");
	ft_printf("TECLA +      : 	Zoom IN.\n");
	ft_printf("TECLA -      : 	Zoom OUT.\n\n");
	ft_printf("TECLA 1      : 	Cambio a blanco y negro.\n");
	ft_printf("TECLA 2      : 	Cambio a colorines divertidos.\n");
	ft_printf("TECLA 3      : 	Cambio a degradado de colores pasón.\n\n");
	ft_printf("TECLA z      : 	Selecciona fractal JULIA.\n");
	ft_printf("TECLA x      : 	Selecciona fractal BARCO EN LLAMAS.\n");
	ft_printf("TECLA c      : 	Selecciona fractal MANDELBROT.\n\n");
	ft_printf("TECLA ENTER  : 	Activa modo francotirador.\n");
	ft_printf("TECLA ESC    : 	Salir del programa.\n\n");
	ft_printf("-------------     RATÓN     -------------\n\n");
	ft_printf("SCROLL IN    : 	Zoom de Google IN.\n");
	ft_printf("SCROLL OUT   :	Zoom de Google OUT.\n");
	ft_printf("BOTÓN SCROLL :	Movimiento por el fractal a posición.\n");
	ft_printf("BOTÓN IZQ    :	Movimiento a posición y Zoom IN.\n");
	ft_printf("BOTÓN DER    :  Movimiento a posición y Zoom OUT.\n");
	ft_printf("\n-----------------------------------------\n");
}

void	create_img(t_var *vars)
{
	vars->pixel[1] = 0;
	if (vars->fractal == 1)
		mandelbrot(vars);
	if (vars->fractal == -1)
		julia(vars);
	if (vars->fractal == 0)
		flame_ship(vars);
	if (vars->axis == 1)
		pinta_ejes(vars->img);
	vars->pos->x = 0;
	vars->pos->y = 0;
}

void	ft_leaksf(void)
{
	system("leaks -q fractol");
}
