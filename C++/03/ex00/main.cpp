/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:35:15 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/20 12:57:23 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap	bot1("JaviTor");
	ClapTrap	bot2("Halcón original");
	ClapTrap	bot3("Halcón Chica");

	std::cout << std::endl;
	std::cout << "Turno 1 STATUS: " << std::endl; 
	std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	std::cout << std::endl; 
	
	bot1.attack("Halcón original");
	bot2.takeDamage(bot1.getAttkDamage());
	std::cout << "Halcón original se calienta..." << std::endl;
	bot2.setAttkDamage(8);

	std::cout << std::endl << "Turno 2 STATUS: " << std::endl; 
	std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	std::cout << std::endl; 

	bot2.attack("Javitor");
	bot1.takeDamage(bot2.getAttkDamage());
	std::cout << GREEN << "Javitor se recupera comiendo un bocadillo de bacon al microondas" << DEFAULT << std::endl;
	bot1.beRepaired(5);

	std::cout << std::endl << "Turno 3 STATUS: " << std::endl; 
	std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	std::cout << std::endl; 

	std::cout << "Halcón Chica se baja del autobús y lanza una bola de ESTADÍSTICA" << std::endl;
	bot3.setAttkDamage(20);
	bot3.attack("Javitor");
	bot3.attack("Halcón original");
	bot1.takeDamage(bot3.getAttkDamage());
	bot2.takeDamage(bot3.getAttkDamage());

	std::cout << std::endl << "Turno 4 STATUS: " << std::endl; 
	std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	std::cout << std::endl; 

	std::cout << "Halcón chica se coge un avión a Barcelona para no volver..." << std::endl << std::endl;

	system("leaks -q claptrap");
	return 0;
}