/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:26:31 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/14 14:45:28 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &d);
double	areaTriangle(const Point &a, const Point &b, const Point &c);

int main(void)
{
	Point	const a;
	Point	const b(1.0, 3.0);
	Point	const c(-3.0, 5.0);
	Point	const d(0.0, 1.0);
	Point	const e(-1.0, 0.0);
	
	// Point	const a;
	// Point	const b(0.0, 3.0);
	// Point	const c(-3.0, 0.0);
	// Point	const d(-1.0, 0.2);
	// Point	const e(-1.0, 0.0);

	std::cout << "Ax = " << a.getX().toFloat() << std::endl;
	std::cout << "Ay = " << a.getY().toFloat() << std::endl << std::endl;
	std::cout << "Bx = " << b.getX().toFloat() << std::endl;
	std::cout << "By = " << b.getY().toFloat() << std::endl << std::endl;
	std::cout << "Cx = " << c.getX().toFloat() << std::endl;
	std::cout << "Cy = " << c.getY().toFloat() << std::endl << std::endl;
	std::cout << "Dx = " << d.getX().toFloat() << std::endl;
	std::cout << "Dy = " << d.getY().toFloat() << std::endl << std::endl;
	std::cout << "Ex = " << e.getX().toFloat() << std::endl;
	std::cout << "Ey = " << e.getY().toFloat() << std::endl << std::endl;
	
	double	areaT = areaTriangle(a, b, c);
	if (areaT == 0){
		std::cout << "Los puntos a, b y c están alineados por lo que no forman un triángulo." << std::endl;
		return 0;
	}
	if (bsp(a, b, c, d))
		std::cout << "El punto d está DENTRO del triángulo." << std::endl;
	else
		std::cout << "El punto d está FUERA del triángulo." << std::endl << std::endl;
	if (bsp(a, b, c, e))
		std::cout << "El punto e está DENTRO del triángulo." << std::endl;
	else
		std::cout << "El punto e está FUERA del triángulo." << std::endl;
	return 0;
}