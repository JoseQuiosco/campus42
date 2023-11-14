/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:09:36 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/14 00:27:38 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#ifndef __POINT_HPP__
#define __POINT_HPP__

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &p);
		~Point();
		Fixed	getX(void) const;
		Fixed	getY(void) const;
		Point 	&operator=(const Point &p);
};

#endif