/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:43:44 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/06 23:05:58 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

void ft_leaks(void){
	system("leaks -q horde");
}
int	main (void)
{
	atexit(ft_leaks);
	int		size = 5;
	Zombie	*horde = zombieHorde(size, "Muertin");
	
	for (int i = 0; i < size; i++){
		horde[i].announce();
	}
	delete [] horde;
	return 0;
}
