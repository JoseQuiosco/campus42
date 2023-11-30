/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:45:24 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/12/01 00:26:15 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
	std::cout << this->target << " RobotomyRequestForm has been created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f) : AForm(f.getName(), f.getGrade_to_sign(), f.getGrade_to_exec())
{
	if (f.getSign())
		this->setSign();	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->target + this->getName() + " has been destroyed." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
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
		std::cout << "(Loud drill noises) " << std::endl;
        std::srand(std::time(0));
        int randomNumber = std::rand() % (100 - 1 + 1) + 1;

        if ((randomNumber % 2) == 0)
        {
            std::cout << this->target << " has been robotomized." << std::endl;
        }
        else
        {
            std::cout << "Failed to robotomize." << this->target << std::endl;
        }
    }
}

std::string	const	&RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &f)
{
	this->target = f.getTarget();
	return (*this);
}
