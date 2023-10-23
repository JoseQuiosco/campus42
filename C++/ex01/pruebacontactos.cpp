/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebacontactos.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:52:17 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/10/24 01:00:47 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <stdlib.h>

void ft_leaks(void)
{
	system("leaks -q pruebacontactos");
}

int	main(void)
{
	atexit(ft_leaks);
	Contact	contacto1;
	Contact contacto2;

	std::cout << "Prueba de Constructores por defecto" << std::endl;
	std::cout << "Nombre Contacto 1: " << contacto1.get_firstname() << "$" << std::endl;
	std::cout << "Nombre Contacto 2: " << contacto2.get_firstname() << "$" << std::endl;

	std::cout << "Prueba de Constructor copia" << std::endl;
	std::cout << "Primero almacenamos datos para nuestro Contacto 1:" << std::endl;
	contacto1.set_firstname("Dario");
	contacto1.set_lastname("Vasco");
	contacto1.set_nickname("Enano");
	contacto1.set_phone("666666666");
	contacto1.set_secret("Pirulus");
	
	std::cout << "Ahora asignamos a Contacto 2 el contenido de Contacto 1, con operador = :" << std::endl;
	contacto2 = contacto1;
	std::cout << "Ahora copiamos datos en Contacto 3 al declararlo, con constructor copia:" << std::endl;
	Contact	contacto3(contacto1);
	
	std::cout << "Ahora comprobamos datos en ambos contactos." << std::endl;
	std::cout << "CONTACTO 1:" << std::endl;
	std::cout << "Nombre Contacto 1: " << contacto1.get_firstname() << std::endl;
	std::cout << "Apellido Contacto 1: " << contacto1.get_lastname() << std::endl;
	std::cout << "Nickname Contacto 1: " << contacto1.get_nickname() << std::endl;
	std::cout << "Phone Contacto 1: " << contacto1.get_phone() << std::endl;
	std::cout << "Secreto Contacto 1: " << contacto1.get_secret() << std::endl;

	std::cout << "CONTACTO 2:" << std::endl;
	std::cout << "Nombre Contacto 2: " << contacto2.get_firstname() << std::endl;
	std::cout << "Apellido Contacto 2: " << contacto2.get_lastname() << std::endl;
	std::cout << "Nickname Contacto 2: " << contacto2.get_nickname() << std::endl;
	std::cout << "Phone Contacto 2: " << contacto2.get_phone() << std::endl;
	std::cout << "Secreto Contacto 2: " << contacto2.get_secret() << std::endl;
	
	std::cout << "CONTACTO 3:" << std::endl;
	std::cout << "Nombre Contacto 3: " << contacto3.get_firstname() << std::endl;
	std::cout << "Apellido Contacto 3: " << contacto3.get_lastname() << std::endl;
	std::cout << "Nickname Contacto 3: " << contacto3.get_nickname() << std::endl;
	std::cout << "Phone Contacto 3: " << contacto3.get_phone() << std::endl;
	std::cout << "Secreto Contacto 3: " << contacto3.get_secret() << std::endl;

	Contact contacto4;
	std::string aux;
	std::cout << "Ahora vamos a pedir los datos por teclado usando getline" << std::endl;
	std::cout << "Introduce el nombre: ";
	std::getline(std::cin, aux);
	contacto4.set_firstname(aux);
	std::cout << "Introduce el apellido: ";
	std::getline(std::cin, aux);
	contacto4.set_lastname(aux);
	std::cout << "Introduce el nickname: ";
	std::getline(std::cin, aux);
	contacto4.set_nickname(aux);
	std::cout << "Introduce el phone: ";
	std::getline(std::cin, aux);
	contacto4.set_phone(aux);
	std::cout << "Introduce el secret: ";
	std::getline(std::cin, aux);
	contacto4.set_secret(aux);

	std::cout << "Ahora comprobamos el contenido del último contacto." << std::endl;
	std::cout << "CONTACTO 4:" << std::endl;
	std::cout << "Nombre Contacto 4: " << contacto4.get_firstname() << std::endl;
	std::cout << "Apellido Contacto 4: " << contacto4.get_lastname() << std::endl;
	std::cout << "Nickname Contacto 4: " << contacto4.get_nickname() << std::endl;
	std::cout << "Phone Contacto 4: " << contacto4.get_phone() << std::endl;
	std::cout << "Secreto Contacto 4: " << contacto4.get_secret() << std::endl;

	return (0);
}