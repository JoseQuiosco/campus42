/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:14:13 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/14 12:52:24 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)){
}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {
}

Point::Point(const Point &p) : x(p.getX()), y(p.getY()) {
}

Point::~Point(){
}

Fixed	Point::getX(void) const{
	return (this->x);
}

Fixed	Point::getY(void) const{
	return (this->y);
}

Point 	&Point::operator=(const Point &p){
	(void) &p;
    return *this;
}
