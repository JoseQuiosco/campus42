/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:08:32 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/12/01 00:04:54 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

# define BOLD  "\033[1m"
# define BLACK "\033[30;1m"
# define RED   "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define BLUE  "\033[34;1m"
# define MAGENTA   "\033[35;1m"
# define CYAN  "\033[36;1m"
# define WHITE "\033[37;1m"
# define DEFAULT   "\033[0m"

void ft_leaks(void)
{
	system("leaks -q form");
}

int main()
{
	atexit(ft_leaks);
    try
    {
		ShrubberyCreationForm home("home");
		Bureaucrat me("me", 1);
		Bureaucrat meno("meno", 149);
		RobotomyRequestForm yoo("yoo");
		PresidentialPardonForm noo("noo");
		
		me.signForm(home);
		me.executeForm(home);
		//std::cout << std::endl << RED <<"ME va a ejecutar un formulario de Robotimizar!! sin firmar: " << DEFAULT << std::endl << std::endl;
		//me.executeForm(yoo);
		me.signForm(yoo);
		std::cout << std::endl << GREEN << "ME va a ejecutar un formulario de Robotimizar!! firmado: " << DEFAULT << std::endl << std::endl;
		me.executeForm(yoo);
		//std::cout << std::endl << GREEN << "MENO va a ejecutar un formulario de Robotimizar!! firmado: " << DEFAULT << std::endl << std::endl;
		//meno.executeForm(yoo);
		
		std::cout << std::endl << RED << "MENO va a firmar un formulario de perdon!!" << DEFAULT << std::endl << std::endl;
		meno.signForm(noo);
		
		//std::cout << std::endl << RED << "ME va a ejecutar un formulario de perdón!! sin firmar: " << DEFAULT << std::endl << std::endl;
		//meno.executeForm(noo);
		std::cout << std::endl << GREEN<< "ME firma un formulario de perdon." << DEFAULT << std::endl << std::endl;
		me.signForm(noo);
		std::cout << std::endl << GREEN<< "ME va a ejecutar un formulario de perdón!!" << DEFAULT << std::endl << std::endl;
		meno.executeForm(noo);
    }
    catch(const std::exception& ex)
    {
        std::cout << BLUE << ex.what() << DEFAULT << std::endl;
    }
    return 0;
}