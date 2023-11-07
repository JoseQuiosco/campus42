/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:57:21 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/07 20:46:09 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replace(std::string filename, std::string s1, std::string s2);
void	ft_leaks(void){
	system("leaks -q replace");
}

int	main (int argc, char **argv)
{
	atexit(ft_leaks);
	if (argc != 4){
		std::cout << "El programa necesita filename, s1 y s2..." << std::endl;
		return 0;
	}
	replace(argv[1], argv[2], argv[3]);
	return 0;
}
