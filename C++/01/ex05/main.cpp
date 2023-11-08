/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:57:21 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/08 21:59:09 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void ft_leaks(void){
	system("leaks -q harl");
}

int	main (int argc, char **argv)
{
	atexit(ft_leaks);
	if (argc != 2){
		return 0;
	}
	Harl harl;
	harl.complain(argv[1]);
	return 0;
}
