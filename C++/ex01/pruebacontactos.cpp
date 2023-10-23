/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebacontactos.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:52:17 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/10/23 21:11:40 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int	main(void)
{
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
	
	std::cout << "Ahora copiamos datos en Contacto 3:" << std::endl;
	Contact	contacto3(contacto1);
	
	std::cout << "Ahora comprobamos datos en ambos contactos." << std::endl;
	std::cout << "CONTACTO 1:" << std::endl;
	std::cout << "Nombre Contacto 1: " << contacto1.get_firstname() << std::endl;
	std::cout << "Apellido Contacto 1: " << contacto1.get_lastname() << std::endl;
	std::cout << "Nickname Contacto 1: " << contacto1.get_nickname() << std::endl;
	std::cout << "Phone Contacto 1: " << contacto1.get_phone() << std::endl;
	std::cout << "Secreto Contacto 1: " << contacto1.get_secret() << std::endl;
	
	std::cout << "CONTACTO 3:" << std::endl;
	std::cout << "Nombre Contacto 3: " << contacto3.get_firstname() << std::endl;
	std::cout << "Apellido Contacto 3: " << contacto3.get_lastname() << std::endl;
	std::cout << "Nickname Contacto 3: " << contacto3.get_nickname() << std::endl;
	std::cout << "Phone Contacto 3: " << contacto3.get_phone() << std::endl;
	std::cout << "Secreto Contacto 3: " << contacto3.get_secret() << std::endl << std::endl;

	return (0);
}