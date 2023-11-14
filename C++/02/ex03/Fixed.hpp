/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:47:51 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/14 00:05:53 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class Fixed
{
	private:
		int					value;
		static const int 	fbits = 8;
		static const double epsilon;
	
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();

		Fixed 	&operator=(const Fixed &f);

		bool	operator>(const Fixed &f) const;
		bool	operator<(const Fixed &f) const;
		bool	operator>=(const Fixed &f) const;
		bool	operator<=(const Fixed &f) const;
		bool	operator==(const Fixed &f) const;
		bool	operator!=(const Fixed &f) const;
		Fixed 	operator+(const Fixed &f) const;
		Fixed 	operator-(const Fixed &f) const;
		Fixed 	operator*(const Fixed &f) const;
		Fixed 	operator/(const Fixed &f) const;
		Fixed 	&operator++(void);
		Fixed 	operator++(int);
		Fixed 	&operator--(void);
		Fixed 	operator--(int);
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static	Fixed	&min(Fixed &a, Fixed &b);
		static	const Fixed	&min(const Fixed &a, const Fixed &b);
		static	Fixed	&max(Fixed &a, Fixed &b);
		static	const Fixed	&max(const Fixed &a, const Fixed &b);
		
};
std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif