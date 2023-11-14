/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:36:24 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/14 00:01:25 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) { 
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(5);
	Fixed const d((float)2.005);
	//Fixed const e((float)2.0058);
	Fixed const e((float)2.007);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl << std::endl;
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "b - a = " << b - a << std::endl;
	std::cout << "a / b = " <<  a / b << std::endl;
	std::cout << "b / a = " << b / a << std::endl;
	std::cout << "c / d = " << c / d << std::endl;
	std::cout << "b * a = " << b * a << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

	if ( d == e )
		std::cout << "d igual que e" << std::endl;
	if ( d >= e )
		std::cout << "d mayor o igual que e" << std::endl;
	if ( d > e )
		std::cout << "d mayor que e" << std::endl;
	if ( d <= e )
		std::cout << "d menor o igual que e" << std::endl;
	if ( d < e )
		std::cout << "d menor que e" << std::endl;
	
	if ( e >= d )
		std::cout << "e mayor o igual que d" << std::endl;
	if ( e > d )
		std::cout << "e mayor que d" << std::endl;
	if ( e <= d )
		std::cout << "e menor o igual que d" << std::endl;
	if ( e < d )
		std::cout << "e menor que d" << std::endl;

	if ( d != e )
		std::cout << "d diferente de e" << std::endl;
	
	return 0;
}