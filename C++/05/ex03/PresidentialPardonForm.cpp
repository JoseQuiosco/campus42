/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:09:18 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/12/01 00:26:08 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
	std::cout << this->target << " PresidentialPardonForm has been created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &f) : AForm(f.getName(), f.getGrade_to_sign(), f.getGrade_to_exec())
{
	if (f.getSign())
		this->setSign();	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->target + this->getName() + " has been destroyed." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGrade_to_exec())
    {
        throw Bureaucrat::GradeTooLowException((executor.getName() + " has not grade enough to execute this form.").c_str());
    }
    else if (this->getSign() == false)
    {
        throw AForm::FormNotSigned("Can't execute this form because is not signed.");
    }
    else
    {
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}

std::string	const	&PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &f)
{
	this->target = f.getTarget();
	return (*this);
}
