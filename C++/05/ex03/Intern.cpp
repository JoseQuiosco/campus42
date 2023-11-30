/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:28:35 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/12/01 00:18:47 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Default Intern constructor" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor" << std::endl;
}

Intern::Intern(Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(Intern &copy)
{
    (void)copy;
    return *this;
}

AForm *create_shrubb(std::string target)
{
    AForm *f = new ShrubberyCreationForm(target);
    return (f);
}

AForm *create_robotomy(std::string target)
{
    AForm *f = new RobotomyRequestForm(target);
    return (f);
}

AForm *create_presi_pardon(std::string target)
{
    AForm *f = new PresidentialPardonForm(target);
    return (f);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon" };
    AForm *(*create[3])(std::string target) = {&create_shrubb, &create_robotomy, &create_presi_pardon};
	int i = 0;
	while (name != names[i] && i < 3)
		i++;
	if (i == 3)
	{
		 std::cout << name << " is not a name of any existent Form." << std::endl;	
    	return (NULL);
	}
	return (create[i](target));	
}
