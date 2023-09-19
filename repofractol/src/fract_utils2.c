/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:32:50 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/05/03 19:22:17 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

int	get_a(int rgba)
{
	return (rgba & 0xFF);
}

float	my_atof(char *number)
{
	char	**num;
	int		i;
	float	decimal;
	int		sign;

	sign = 1;
	num = ft_split(number, '.');
	i = 0;
	while (num[i] != NULL)
		i++;
	if (i > 2)
		exit(0);
	if (num[0][0] == '-')
		sign *= -1;
	if (i == 2)
		decimal = (float)atoi(num[0]) + sign * (float)atoi(num[1])
			* (float)pow(10, -(float)ft_strlen(num[1]));
	if (i == 1)
		decimal = (float)atoi(num[0]);
	i = 0;
	while (num[i] != NULL)
		free(num[i++]);
	free(num);
	return (decimal);
}

void	pinta_ejes(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;

	y = HEIGHT / 2;
	x = 0;
	while (x < WIDTH)
		mlx_put_pixel(img, x++, y, 0xFF0000FF);
	x = WIDTH / 2;
	y = 0;
	while (y < HEIGHT)
		mlx_put_pixel(img, x, y++, 0xFF0000FF);
}
