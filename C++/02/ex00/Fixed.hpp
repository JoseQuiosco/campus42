/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:47:51 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/09 18:42:39 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class Fixed
{
	private:
		int	value;
		static const int fbits = 8;
	
	public:
		Fixed();
		Fixed(Fixed& f);
		~Fixed();
		Fixed &operator=(Fixed& f);

		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
};

#endif