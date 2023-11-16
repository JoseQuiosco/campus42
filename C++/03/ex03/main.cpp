/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:26:56 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 18:59:32 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main (void)
{
	DiamondTrap	bot4("51_PerCent");
	DiamondTrap bot5;

	std::cout << std::endl;
	std::cout << "Probamos sacar información bot4.getName()" << std::endl;
	std::cout << std::endl;
	std::cout << "Name: " << bot4.getName() << std::endl;
	std::cout << "HP: " << bot4.getHitPoints() << std::endl;
	std::cout << "EP: " << bot4.getEnergyPoints() << std::endl;
	std::cout << "DMG: " << bot4.getAttkDamage() << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Probamos sacar información bot4.ClapTrap::getName()" << std::endl;
	std::cout << std::endl;
	std::cout << "Name: " << bot4.ClapTrap::getName() << std::endl;
	std::cout << "HP: " << bot4.ClapTrap::getHitPoints() << std::endl;
	std::cout << "EP: " << bot4.ClapTrap::getEnergyPoints() << std::endl;
	std::cout << "DMG: " << bot4.ClapTrap::getAttkDamage() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	bot4.attack(bot5.getName());
	bot5.takeDamage(bot4.getAttkDamage());
	
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "BOT 4: mi nombre es: " << bot4.getName() << std::endl;
	std::cout << "BOT 4: mi nombre primitivo es: " << bot4.ClapTrap::getName() << std::endl;
	std::cout << "BOT 5: mi nombre es: " << bot5.getName() << std::endl;
	std::cout << "BOT 5: mi nombre primitivo es: " << bot5.ClapTrap::getName() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	DiamondTrap copy = bot5;

	std::cout << "BOT 5: mi nombre es: " << bot5.getName() << std::endl;
	std::cout << "BOT 5: mi nombre primitivo es: " << bot5.ClapTrap::getName() << std::endl;
	std::cout << "COPY : mi nombre es: " << copy.getName() << std::endl;
	std::cout << "COPY : mi nombre primitivo es: " << copy.ClapTrap::getName() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	bot4.whoAmI();
	bot4.highFiveGuys();
	std::cout << std::endl;
	std::cout << std::endl;
	copy.whoAmI();
	copy.highFiveGuys();

	std::cout << std::endl;


	// ClapTrap	bot1("JaviTor");
	// ScavTrap	bot2("Halcón original");
	// FragTrap	bot3("Halcón Chica");
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << bot4.getName() << " " << bot4.getHitPoints() << " HP,	" << bot4.getAttkDamage() << " DMG,	" << bot4.getEnergyPoints() << " EP" << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// bot4.whoAmI();
	// bot4.attack("a tu puta madre");
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << bot4.getName() << " " << bot4.getHitPoints() << " HP,	" << bot4.getAttkDamage() << " DMG,	" << bot4.getEnergyPoints() << " EP" << std::endl;
	
	// bot1.setAttkDamage(5);
	// std::cout << std::endl;
	// std::cout << "Turno 1 STATUS: " << std::endl; 
	// std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	// std::cout << std::endl; 
	
	// bot1.attack("Halcón original");
	// bot2.takeDamage(bot1.getAttkDamage());
	// std::cout << "Halcón original se calienta..." << std::endl;
	// bot2.guardGate();

	// std::cout << std::endl << "Turno 2 STATUS: " << std::endl; 
	// std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	// std::cout << std::endl; 

	// bot2.attack("Javitor");
	// bot1.takeDamage(bot2.getAttkDamage());
	// std::cout << GREEN << "Javitor se recupera antes de morir comiendo un bocadillo de bacon al microondas" << DEFAULT << std::endl;
	// bot1.beRepaired(5);

	// std::cout << std::endl << "Turno 3 STATUS: " << std::endl; 
	// std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	// std::cout << std::endl; 

	// std::cout << "Halcón Chica se baja del autobús y lanza una bola de ESTADÍSTICA" << std::endl;
	// bot3.attack("Javitor");
	// bot3.attack("Halcón original");
	// bot1.takeDamage(bot3.getAttkDamage());
	// bot2.takeDamage(bot3.getAttkDamage());

	// std::cout << std::endl << "Turno 4 STATUS: " << std::endl; 
	// std::cout << "Javitor:			" << bot1.getHitPoints() << " HP,	" << bot1.getAttkDamage() << " DMG,	" << bot1.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	// std::cout << std::endl; 

	// std::cout << "Halcón original le planta un puñete a Halcón Chica" << std::endl;
	// bot2.attack("Halcón Chica");
	// bot3.takeDamage(bot2.getAttkDamage());
	// bot3.highFiveGuys();
	// std::cout << "Halcón original se tranquiliza" << std::endl << std::endl;
	// std::cout << "JaviTor resucita de entre los muertos convirtiéndose en el empresaurio definitivo" << std::endl;
	// bot4.whoAmI();

	// std::cout << std::endl << "Turno 5 STATUS: " << std::endl; 
	// std::cout << "Halcón original:		" << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "Halcón Chica:			" << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "51_PerCent:			" << bot4.getHitPoints() << " HP,	" << bot4.getAttkDamage() << " DMG,	" << bot4.getEnergyPoints() << " EP" << std::endl;
	// std::cout << std::endl;

	// std::cout << "51_PerCent invoca a una copia de Halcón Chica en versión Diamond" << std::endl;
	// DiamondTrap	copybotchica = bot4;
	// std::cout << "51 le pega otro puñete a Halcón original" << std::endl;
	// bot4.attack("Halcón original");
	// bot2.takeDamage(bot4.getAttkDamage());
	// copybotchica.attack("Halcón original");
	// bot2.takeDamage(copybotchica.getAttkDamage());

	// std::cout << std::endl << "Turno 6 STATUS: NOMBRES VERDADEROS" << std::endl; 
	// std::cout << "Halcón original:		" << bot2.getName() << " " << bot2.getHitPoints() << " HP,	" << bot2.getAttkDamage() << " DMG,	" << bot2.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "Halcón Chica:			" << bot3.getName() << " " << bot3.getHitPoints() << " HP,	" << bot3.getAttkDamage() << " DMG,	" << bot3.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "51_PerCent:			" << bot4.getName() << " " << bot4.getHitPoints() << " HP,	" << bot4.getAttkDamage() << " DMG,	" << bot4.getEnergyPoints() << " EP" << std::endl;
	// std::cout << "ChicaReplicante:		" << copybotchica.getName() << " " << copybotchica.getHitPoints() << " HP,	" << copybotchica.getAttkDamage() << " DMG,	" << copybotchica.getEnergyPoints() << " EP" << std::endl;
	// std::cout << std::endl;


	return 0;
}
