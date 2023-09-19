/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:18:57 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/03 19:06:41 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <math.h>

# ifndef WIDTH
#  define WIDTH 1280
# endif
# ifndef HEIGHT
#  define HEIGHT 720
# endif

typedef struct s_pos
{
	uint32_t	x;
	uint32_t	y;
}			t_pos;

typedef struct s_vars
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_pos		*pos;
	int			maxiter;
	float		pixel[2];
	float		offset[2];
	float		ajuste[2];
	float		c[2];
	float		paso;
	float		max_x;
	float		max_y;
	int			color_t;
	int			fractal;
	int			axis;
}			t_var;

void	ft_leaksf(void);
void	init_vars(t_var *vars);
void	ft_error_1(t_var *vars);
void	ft_error_2(t_var *vars);
int		get_rgba(int r, int g, int b, int a);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);
float	my_atof(char *number);
void	pinta_ejes(mlx_image_t *img);
int		mandelbrot_iter(float x0, float y0, int maxiter);
int		julia_iter(float zx0, float zy0, int maxiter, float *c);
int		bw(t_var *vars, int iter);
int		fullcolor(t_var *vars, int iter);
int		othercolor(t_var *vars, int iter);
void	paint_bw(t_var *vars, int iter);
void	mandelbrot(t_var *vars);
int		ship_iter(float x0, float y0, int maxiter);
void	flame_ship(t_var *vars);
void	julia(t_var *vars);
void	create_img(t_var *vars);
void	configure_offset_zoom(t_var *vars, mouse_key_t button);
void	mouse_functions(mouse_key_t button, action_t action,
			modifier_key_t mods, void *param);
void	ajuste_zoom_google_in(t_var *vars);
void	ajuste_zoom_google_out(t_var *vars);
void	mouse_scroll(double xdelta, double ydelta, void *param);
void	configure_zoom_key(keys_t key, t_var *vars);
void	key_options(mlx_key_data_t keydata, t_var *vars);
void	key_functions(mlx_key_data_t keydata, void *param);
void	capture_c(t_var *vars, int argc, char **argv);
void	print_manual(void);

#endif