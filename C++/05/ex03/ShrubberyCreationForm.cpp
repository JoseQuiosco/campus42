/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:20:25 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/12/01 00:26:26 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

static void printSpaces(int n, std::ofstream &out);
static void printTree(int height, int spaces, std::ofstream &out);

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
	std::cout << this->target << " ShrubberyCreationForm has been created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f) : AForm(f.getName(), f.getGrade_to_sign(), f.getGrade_to_exec())
{
	if (f.getSign())
		this->setSign();	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->target + this->getName() + " has been destroyed." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGrade_to_exec())
	{
		std::ofstream file(this->getTarget() + "_shrubbery", std::ofstream::out);
		if (file.is_open())
		{
			for (int i = 0; i < 4; i++)
			{
				printTree(4, 3, file);
			}
			file.close();
			std::cout << std::endl << "File " + this->getTarget() + "_shrubbery has been created with success!!" << std::endl;
		}
		else
			std::cout << "File " + this->getTarget() + "_shrubbery's creation has failed..." << std::endl;
	}
	else
		throw AForm::GradeTooLowException((executor.getName() + " has not grade enough to execute this form.").c_str());
}
	

std::string	const	&ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &f)
{
	this->target = f.getTarget();
	return (*this);
}


static void printSpaces(int n, std::ofstream &out) {
    for (int i = 0; i < n; ++i) {
        out << " ";
    }
}

static void printTree(int height, int spaces, std::ofstream &out) {
    if (height <= 0) {
        return;
    }

    int branches = 1;
    for (int i = 1; i <= height; ++i) {
        printSpaces(spaces - i, out);
        for (int j = 1; j <= branches; ++j) {
            out << "* ";
        }
        out << std::endl;
        branches += 2;
    }
    printSpaces(spaces - 1, out);
    out << "| |" << std::endl;
    printSpaces(spaces - 2, out);
    out << "|_|" << std::endl;
}