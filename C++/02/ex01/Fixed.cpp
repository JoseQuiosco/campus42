/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:28:29 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/09 22:02:28 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//int tiene 4 bytes - 32 bits

void printBits(int number){
	unsigned int mask = 1 << (sizeof(int) * 8 - 1); // Crear una máscara con el bit más significativo en 1

    std::cout << number << " en binario es: ";
    for (int i = 0; i < (int)sizeof(int) * 8; i++) {
        if ((number & mask) == 0) {
            std::cout << "0";
        } else {
            std::cout << "1";
        }
        number <<= 1; // Desplazar bits a la izquierda
    }
    std::cout << std::endl;
}

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &f){
	std::cout << "Copy constructor called" << std::endl;
	// this->value = f.getRawBits();
	*this = f;
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const{
	return (this->value);
}

void 	Fixed::setRawBits(int const raw){
	this->value = raw;
}

Fixed::Fixed(const int number){
	std::cout << "Int constructor called" << std::endl;
	this->value = (number << Fixed::fbits);
	//this->value = (number * (1 << Fixed::fbits));
}

Fixed::Fixed(const float number){
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(number * (float)(1 << Fixed::fbits));
	//this->value = (int)(number << Fixed::fbits);
}

float	Fixed::toFloat(void) const{
	return ((float)this->value / (float)(1 << Fixed::fbits));
	//return ((float)(this->value >> Fixed::fbits));
}
int		Fixed::toInt(void) const{
	return (this->value >> Fixed::fbits);
}

Fixed &Fixed::operator=(const Fixed &f){
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(f.getRawBits());
	return (*this);
}
std::ostream &operator<<(std::ostream &out, const Fixed &f){
	out << f.toFloat();
	return (out);
}
