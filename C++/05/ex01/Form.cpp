/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:42:57 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/30 18:21:10 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, unsigned int grade_to_sign, unsigned int grade_to_exec) : name(name), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
	if (grade_to_sign < 1)
		throw Form::GradeTooHighException("Error: Form with grade to sign over 1 can't be created.");
	else if (grade_to_sign > 150)
		throw Form::GradeTooLowException("Error: Form with grade to sign under 150 can't be created.");
	if (grade_to_exec < 1)
		throw Form::GradeTooHighException("Error: Form with grade to exec over 1 can't be created.");
	else if (grade_to_exec > 150)
		throw Form::GradeTooLowException("Error: Form with grade to exec under 150 can't be created.");
	this->sign = false;
}

Form::Form(Form &f) : name(f.getName()), sign(f.getSign()), grade_to_sign(f.getGrade_to_sign()), grade_to_exec(f.getGrade_to_exec()) {}

Form::~Form()
{
	std::cout << "Form " << this->name << " has been destroyed" << std::endl;
}

std::string		Form::getName(void) const
{
	return (this->name);
}

bool	Form::getSign(void) const
{
	return (this->sign);
}

unsigned int	Form::getGrade_to_sign(void) const
{
	return (this->grade_to_sign);
}

unsigned int	Form::getGrade_to_exec(void) const
{
	return (this->grade_to_exec);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->grade_to_sign)
		throw Form::GradeTooLowException("Bureaucrat " + b.getName() + " has not grade enough sign this Form." );
	else
		this->sign = true;
}




Form	&Form::operator=(const Form &b)
{
	if (this != &b)
		this->sign = b.getSign();
	return (*this);
}

std::ostream 	&operator<<(std::ostream &out, const Form &f)
{
	out << "Form's Name: " << f.getName() << std::endl;
	out << "Grade to sign: " << f.getGrade_to_sign() << "    Grade to exec: " << f.getGrade_to_exec() << "    Signed: " << f.getSign() << std::endl;
	return (out);
}
