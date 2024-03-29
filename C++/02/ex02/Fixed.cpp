/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:28:29 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/19 19:25:21 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//int tiene 4 bytes - 32 bits

/*
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
*/

const double Fixed::epsilon = 1.0 / (1 << Fixed::fbits);

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	std::cout << "Epsilon" << Fixed::epsilon;
	this->value = 0;
}

Fixed::Fixed(const Fixed &f){
	*this = f;
}
Fixed::~Fixed(){
}

int		Fixed::getRawBits(void) const{
	return (this->value);
}

void 	Fixed::setRawBits(int const raw){
	this->value = raw;
}

Fixed::Fixed(const int number){
	this->value = (number << Fixed::fbits);
}

Fixed::Fixed(const float number){
	this->value = (int)roundf(number * (float)(1 << Fixed::fbits));
}

float	Fixed::toFloat(void) const{
	return ((float)this->value / (float)(1 << Fixed::fbits));
}
int		Fixed::toInt(void) const{
	return (this->value >> Fixed::fbits);
}

Fixed &Fixed::operator=(const Fixed &f){
	this->setRawBits(f.getRawBits());
	return (*this);
}
std::ostream &operator<<(std::ostream &out, const Fixed &f){
	out << f.toFloat();
	return (out);
}

bool	Fixed::operator>(const Fixed &f) const{
	return ((double)(this->toFloat() - f.toFloat()) > Fixed::epsilon);
}

bool	Fixed::operator>=(const Fixed &f) const{

	if ((double)(this->toFloat() - f.toFloat()) > - Fixed::epsilon)
		return true;
	else
		return false;
}

bool	Fixed::operator<(const Fixed &f) const{
	return ((double)(this->toFloat() - f.toFloat()) < - Fixed::epsilon);
}

bool	Fixed::operator<=(const Fixed &f) const{
	
	if ((double)(this->toFloat() - f.toFloat()) < Fixed::epsilon)
		return true;
	else
		return false;
}

bool	Fixed::operator==(const Fixed &f) const{

	if (((double)(this->toFloat() - f.toFloat()) < Fixed::epsilon) 
		&& (double)(this->toFloat() - f.toFloat()) > - Fixed::epsilon)
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed &f) const{

	if (((double)(this->toFloat() - f.toFloat()) >= Fixed::epsilon) 
		|| (double)(this->toFloat() - f.toFloat()) <= - Fixed::epsilon)
		return true;
	else
		return false;
}

Fixed 	Fixed::operator+(const Fixed &f) const{
	Fixed	total;
	total.setRawBits(this->getRawBits() + f.getRawBits());
	return (total);
}

Fixed 	Fixed::operator-(const Fixed &f) const{
	Fixed	total;
	total.setRawBits(this->getRawBits() - f.getRawBits());
	return (total);
}

Fixed 	Fixed::operator*(const Fixed &f) const{
	return (this->toFloat() * f.toFloat());
}

Fixed 	Fixed::operator/(const Fixed &f) const{
	if (f.getRawBits() == 0)
		throw std::logic_error("Divided by 0");
	return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed 	&Fixed::operator++(void){
	this->value = (int)roundf((float)((double)this->toFloat() + epsilon) * (float)(1 << Fixed::fbits));
	return (*this);
}

Fixed 	Fixed::operator++(int){
	Fixed	copy = *this;
	this->value = (int)roundf((float)((double)this->toFloat() + epsilon) * (float)(1 << Fixed::fbits));
	return copy;
}

Fixed 	&Fixed::operator--(void){
	this->value = (int)roundf((float)((double)this->toFloat() - epsilon) * (float)(1 << Fixed::fbits));;
	return (*this);
}

Fixed 	Fixed::operator--(int){
	Fixed	copy = *this;
	this->value = (int)roundf((float)((double)this->toFloat() - epsilon) * (float)(1 << Fixed::fbits));;
	return copy;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return a;
	return b;
}
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b){
	if (a < b)
			return a;
		return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b)
		return a;
	return b;
}
