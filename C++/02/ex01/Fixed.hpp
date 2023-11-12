/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:47:51 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/12 21:43:43 by dvasco-m         ###   ########.fr       */
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
	
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();

		Fixed 	&operator=(const Fixed &f);
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif