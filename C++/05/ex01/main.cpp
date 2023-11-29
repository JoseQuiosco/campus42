/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:08:32 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/21 18:40:40 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	john("John", 1);
		std::cout << john << std::endl;
		john.upGrade();
		std::cout << john << std::endl;
		john.downGrade();
		std::cout << john << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	system("leaks -q bureaucrat");
	return (0);
}
