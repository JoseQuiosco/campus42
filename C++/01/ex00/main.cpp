/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:10:54 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/06 22:20:23 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
void	ft_leaks(void)
{
	system("leaks -q zombies");
}

int	main(void)
{	
	//atexit(ft_leaks);
	Zombie	*z = newZombie("Pablo");
	z->announce();
	randomChump("Pepe");
	delete z;
	return 0;
}