/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:53:59 by dvasco            #+#    #+#             */
/*   Updated: 2024/02/26 13:31:47 by dvasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>
#include <string>
#include <stdio.h>

int	main()
{
	int		    numbers[] = { 3, 2, 0, -1, 4 };
	char	    characters[] = { 'a', 'b', 'c', 'd', 'e' };
    std::string strings[] = {"Hola", "Capullin", "Mojón", "Pueblo Paleta", ""};
    const char  *ptrs[] = {strings[0].c_str(), strings[1].c_str(), NULL};


	std::cout << "ITER NUMBERS showing content:" << std::endl;
	::iter(numbers, 5, show_content);

    std::cout << std::endl;

	std::cout << "ITER CHARACTERS showing content:" << std::endl;
	::iter(characters, 5, show_content);

    std::cout << std::endl;
    
    	std::cout << "ITER STRINGS showing content:" << std::endl;
	::iter(strings, 5, show_content);

    std::cout << std::endl;

    	std::cout << "ITER CONST CHAR * showing content:" << std::endl;
	::iter(ptrs, 3, show_content);

    std::cout << std::endl;
	std::cout << std::endl;

    return (0);

}

