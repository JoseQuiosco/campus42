/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:42:57 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/30 19:00:59 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const &name, unsigned int grade_to_sign, unsigned int grade_to_exec) : name(name), sign(false), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
	if (grade_to_sign < 1)
		throw AForm::GradeTooHighException("Error: AForm with grade to sign over 1 can't be created.");
	else if (grade_to_sign > 150)
		throw AForm::GradeTooLowException("Error: AForm with grade to sign under 150 can't be created.");
	if (grade_to_exec < 1)
		throw AForm::GradeTooHighException("Error: AForm with grade to exec over 1 can't be created.");
	else if (grade_to_exec > 150)
		throw AForm::GradeTooLowException("Error: AForm with grade to exec under 150 can't be created.");
}

AForm::AForm(AForm &f) : name(f.getName()), sign(f.getSign()), grade_to_sign(f.getGrade_to_sign()), grade_to_exec(f.getGrade_to_exec()) {}

AForm::~AForm()
{
	std::cout << "AForm " << this->name << " has been destroyed" << std::endl;
}

void	AForm::setSign(void)
{
	if (!this->sign)
		this->sign = true;
}

std::string const	&AForm::getName(void) const
{
	return (this->name);
}

bool	AForm::getSign(void) const
{
	return (this->sign);
}

unsigned int	AForm::getGrade_to_sign(void) const
{
	return (this->grade_to_sign);
}

unsigned int	AForm::getGrade_to_exec(void) const
{
	return (this->grade_to_exec);
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->grade_to_sign)
		throw AForm::GradeTooLowException(("Bureaucrat " + b.getName() + " has not grade enough sign this AForm.").c_str());
	else
		this->sign = true;
}




AForm	&AForm::operator=(const AForm &b)
{
	if (this != &b)
		this->sign = b.getSign();
	return (*this);
}

std::ostream 	&operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm's Name: " << f.getName() << std::endl;
	out << "Grade to sign: " << f.getGrade_to_sign() << "    Grade to exec: " << f.getGrade_to_exec() << "    Signed: " << f.getSign() << std::endl;
	return (out);
}
