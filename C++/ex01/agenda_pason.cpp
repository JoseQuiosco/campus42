/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda_pason.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:34:39 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/10/27 00:28:52 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	show_contact(Phonebook& diary)
{
	int			index;

	std::cout << std::endl; std::cout << "Escribe el índice de un contacto para mostrarlo por pantalla: " << std::endl;
	std::cin >> index; std::cin.ignore(255, '\n');
	if (index < 1 || index > 8)
		std::cout << "El índice introducido es incorrecto." << std::endl;
	else
		diary.display_contact(index - 1);
}

int main (void)
{
	Phonebook 	diary;
	std::string	str;
	int			option = 0;
	
	std::cout << "Bienvenido a tu agenda pasón." << std::endl;
	while (1)
	{
		std::cout.setf(std::ios::left, std::ios::adjustfield);
		std::cout << std::endl << "Escribe por teclado alguno de los siguientes comandos:" << std::endl << std::endl;
		std::cout << "ADD		-->		Añadir nuevo usuario." << std::endl;
		std::cout << "SEARCH	-->		Muestra contactos para seleccionar uno y visualizarlo." << std::endl;
		std::cout << "EXIT		-->		Cierra la agenda y sal del programa." << std::endl;
		std::getline(std::cin, str);
		std::cout.setf(std::ios::right, std::ios::adjustfield);
		if (!str.compare("ADD"))
			option = 1;
		else if (!str.compare("SEARCH"))
			option = 2;
		else if (!str.compare("EXIT"))
			option = 3;
		switch(option)
		{
			case 1:{
				diary.add_contact();
				break;}
			case 2:{
				diary.display_phonebook();
				show_contact(diary);
				break;}
			case 3:{
				std::cout << "Hasta luego Maricarmen." << std::endl;
				break;}
			default:
				std::cout << "Vuelve a escribir una instrucción correcta MELÓN!..." << std::endl;
		}
		if (option == 3)
			break;
	}
	return (0);
}