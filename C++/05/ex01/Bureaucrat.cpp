/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:16:51 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/21 18:29:07 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	std::cout << "Default Bureaucrat Constructor called. It can't be used." << std::endl;
}

Bureaucrat::Bureaucrat(unsigned int grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Error: Bureaucrat with level over 1 can't be created.");
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Error: Bureaucrat with level under 150 can't be created.");
	else
	{
		this->grade = grade;
		this->name = "NoNamed";
	}
	std::cout << "Constructor Bureaucrat only Graded called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name){
	this->grade = 150;
	this->name = name;
	std::cout << "Constructor Bureaucrat only Named called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Error: Bureaucrat with level over 1 can't be created.");
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Error: Bureaucrat with level under 150 can't be created.");
	else
	{
		this->grade = grade;
		this->name = name;
	}
	std::cout << "Constructor Bureaucrat with Grade and Name called." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &b){
	this->name = b.getName();
	this->grade = b.getGrade();
	std::cout << "Constructor Copy Bureaucrat called." << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Destructor Bureaucrat called." << std::endl;
}
				
std::string	Bureaucrat::getName(void) const{
	return (this->name);
}

unsigned int	Bureaucrat::getGrade(void) const{
	return (this->grade);
}

void	Bureaucrat::upGrade(void){
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException("You are already at the TOP. There is no level above level 1");
	else
		this->grade -=1;
	std::cout << this->name << " has been graded to level " << this->grade << "." << std::endl;
}

void	Bureaucrat::downGrade(void){
if (this->grade == 150)
		throw Bureaucrat::GradeTooHighException("You are in the SHIT, bro. There is nothing under level 150");
	else
		this->grade +=1;
	std::cout << this->name << " has been downgraded to level " << this->grade << "." << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &b){
	this->name = b.getName();
	this->grade = b.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b){
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (out);
}
