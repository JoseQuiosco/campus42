/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:26:56 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/15 00:09:42 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	ClapTrap	bot1("JaviTor");
	ScavTrap	bot2("Halcón original");
	FragTrap	bot3("Halcón Chica");

	bot1.setAttkDamage(5);
	std::cout << std::endl;
	std::cout << "Turno 1 STATUS: " << std::endl; 
	std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	std::cout << std::endl; 
	
	bot1.attack("Halcón original");
	bot2.takeDamage(bot1.getAttkDamage());
	std::cout << "Halcón original se calienta..." << std::endl;
	bot2.guardGate();

	std::cout << std::endl << "Turno 2 STATUS: " << std::endl; 
	std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	std::cout << std::endl; 

	bot2.attack("Javitor");
	bot1.takeDamage(bot2.getAttkDamage());
	std::cout << GREEN << "Javitor se recupera antes de morir comiendo un bocadillo de bacon al microondas" << DEFAULT << std::endl;
	bot1.beRepaired(5);

	std::cout << std::endl << "Turno 3 STATUS: " << std::endl; 
	std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	std::cout << std::endl; 

	std::cout << "Halcón Chica se baja del autobús y lanza una bola de ESTADÍSTICA" << std::endl;
	bot3.attack("Javitor");
	bot3.attack("Halcón original");
	bot1.takeDamage(bot3.getAttkDamage());
	bot2.takeDamage(bot3.getAttkDamage());

	std::cout << std::endl << "Turno 4 STATUS: " << std::endl; 
	std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	std::cout << std::endl; 

	std::cout << "Halcón original le planta un puñete a Halcón Chica" << std::endl;
	bot2.attack("Halcón Chica");
	bot3.takeDamage(bot2.getAttkDamage());
	bot3.highFiveGuys();
	std::cout << "Halcón original se tranquiliza y vuelve a programar su propia versión pirata de 42..." << std::endl << std::endl;
	std::cout << "Halcón Chica vuelve al bus camino del aeropuerto, no vaya a perder su viaje a Barcelona... no sin antes tomarse un refrigerio." << std::endl;
	bot3.beRepaired(5);

	std::cout << std::endl << "Turno 5 STATUS: " << std::endl; 
	std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	std::cout << std::endl;
	return 0;
}
