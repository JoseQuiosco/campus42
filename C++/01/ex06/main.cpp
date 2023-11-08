/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:12:41 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/08 22:51:46 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void ft_leaks(void){
	system("leaks -q harl_filter");
}

int	main(int argc, char *argv[])
{
	atexit(ft_leaks);
	if (argc != 2){
		return 0;
	}
	Harl harl;
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	std::string	level = argv[1];
	int i = 0;

	while (i < 4 && level.compare(levels[i]) != 0){
		i++;
	}
	switch(i){
		case 0:
			harl.complain("debug");
			harl.complain("info");
			harl.complain("warning");
			harl.complain("error");
			break;
		case 1: {
			harl.complain("info");
			harl.complain("warning");
			harl.complain("error");
			break;
		}
		case 2: {
			harl.complain("warning");
			harl.complain("error");
			break;
		}
		case 3: {
			harl.complain("error");
			break;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}