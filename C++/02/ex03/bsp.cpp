/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:09:21 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/14 14:43:19 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	areAligned(const Point &a, const Point &b, const Point &c, const Point &d)
{
	double	m1;
	double	m2;

	m1 = (b.getY().toFloat() - a.getY().toFloat()) / (b.getX().toFloat() - a.getX().toFloat());
	m2 = (d.getY().toFloat() - b.getY().toFloat()) / (d.getX().toFloat() - b.getX().toFloat());
	if (m1 == m2)
		return (true);
	m1 = (c.getY().toFloat() - a.getY().toFloat()) / (c.getX().toFloat() - a.getX().toFloat());
	m2 = (d.getY().toFloat() - c.getY().toFloat()) / (d.getX().toFloat() - c.getX().toFloat());
	if (m1 == m2)
		return (true);
	m1 = (c.getY().toFloat() - b.getY().toFloat()) / (c.getX().toFloat() - b.getX().toFloat());
	m2 = (d.getY().toFloat() - c.getY().toFloat()) / (d.getX().toFloat() - c.getX().toFloat());
	if (m1 == m2)
		return (true);
	return (false);
}

double	areaTriangle(const Point &a, const Point &b, const Point &c)
{
	double	area;

	area = 0.5 * ((a.getX().toFloat() * b.getY().toFloat() + b.getX().toFloat() * c.getY().toFloat() + c.getX().toFloat() * a.getY().toFloat()) 
				- (a.getX().toFloat() * c.getY().toFloat() + b.getX().toFloat() * a.getY().toFloat() + c.getX().toFloat() * b.getY().toFloat()));
	if (area < 0)
		area *= -1;
	return (area);
}

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &d)
{
	if (areAligned(a, b, c, d))
		return (false);
	double areaT = areaTriangle(a, b, c);
	double area_sum = areaTriangle(a, b, d) + areaTriangle(a, d, c) + areaTriangle(d, b, c);

	if (area_sum <= areaT)
		return (true);
	else
		return (false);
}
