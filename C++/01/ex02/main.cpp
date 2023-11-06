/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:27:34 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/06 23:38:22 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Dirección de Memoria de str: " << &str << std::endl;
	std::cout << "Contenido de str: " << str << std::endl;
	std::cout << "Dirección de memoria contenida en stringPTR: " << stringPTR << std::endl;
	std::cout << "Contenido al que apunta stringPTR : " << *stringPTR << std::endl;
	std::cout << "Dirección de memoria contenida en stringREF: " << &stringREF << std::endl;
	std::cout << "Contenido que referencia stringREF: " << stringREF << std::endl;
	return 0;
}