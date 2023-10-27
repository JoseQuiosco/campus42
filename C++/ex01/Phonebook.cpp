/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:27:54 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/10/27 00:37:34 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(){
	this->size = 0;
	this->index = 0;
	std::cout << "Constructor Phonebook por defecto. Agenda vacía de contactos (contactos con valores nulos)" << std::endl;
}

Phonebook::Phonebook(Phonebook& b){
	this->size = b.get_size();
	this->index = b.get_index();
	int i = 0;
	while (i < this->size)
	{
		this->contacts[i].set_firstname(b.contacts[i].get_firstname());
		this->contacts[i].set_lastname(b.contacts[i].get_lastname());
		this->contacts[i].set_nickname(b.contacts[i].get_nickname());
		this->contacts[i].set_phone(b.contacts[i].get_phone());
		this->contacts[i].set_secret(b.contacts[i].get_secret());
		i++;
	}
}

Phonebook::~Phonebook(){
	std::cout << "Destructor de Phonebook.." << std::endl;
}

int	Phonebook::get_size(void) const{
	return (this->size);
}

int	Phonebook::get_index(void) const{
	return (this->index);
}

void	Phonebook::add_contact(void){
	std::string	str;

	std::cout << "Introduce el Nombre del contacto:" << std::endl;
	std::getline(std::cin, str);
	this->contacts[this->index].set_firstname(str);
	std::cout << "Introduce el Apellido del contacto:" << std::endl;
	std::getline(std::cin, str);
	this->contacts[this->index].set_lastname(str);
	std::cout << "Introduce el Nickname del contacto:" << std::endl;
	std::getline(std::cin, str);
	this->contacts[this->index].set_nickname(str);
	std::cout << "Introduce el Teléfono del contacto:" << std::endl;
	std::getline(std::cin, str);
	this->contacts[this->index].set_phone(str);
	std::cout << "Introduce el Secreto del contacto:" << std::endl;
	std::getline(std::cin, str);
	this->contacts[this->index].set_secret(str);
	this->index = (this->index + 1) % 8;
	if (this->size < 8)
		this->size++;
	std::cout << "Contacto guardado." << std::endl;
}

void	Phonebook::display_contact(int pos) const{
	std::string	str;

	std::cout << "+-----------------------------+-----------------------------+" << std::endl;
	std::cout.setf(std::ios::left, std::ios::adjustfield); 
	std::cout << "|   "; std::cout.width(26); std::cout << "Nombre"; std::cout << "|";
	str = this->contacts[pos].get_firstname();
	if (str.length() > 26){
		str.resize(25); str.append(".");}
	std::cout.setf(std::ios::right, std::ios::adjustfield);
	std::cout << str << std::endl;
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << "|   "; std::cout.width(26); std::cout << "Apellido"; std::cout << "|";
	str = this->contacts[pos].get_lastname();
	if (str.length() > 26){
		str.resize(25); str.append(".");}
	std::cout.setf(std::ios::right, std::ios::adjustfield);
	std::cout << str << std::endl;
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << "|   "; std::cout.width(26); std::cout << "Nickname"; std::cout << "|";
	str = this->contacts[pos].get_nickname();
	if (str.length() > 26){
		str.resize(25); str.append(".");}
	std::cout.setf(std::ios::right, std::ios::adjustfield);
	std::cout << str << std::endl;
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << "|   "; std::cout.width(26); std::cout << "Teléfono"; std::cout << "|";
	str = this->contacts[pos].get_phone();
	if (str.length() > 26){
		str.resize(25); str.append(".");}
	std::cout.setf(std::ios::right, std::ios::adjustfield);
	std::cout << str << std::endl;
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << "|   "; std::cout.width(26); std::cout << "Secreto "; std::cout << "|";
	str = this->contacts[pos].get_secret();
	if (str.length() > 26){
		str.resize(25); str.append(".");}
	std::cout.setf(std::ios::right, std::ios::adjustfield);
	std::cout << str << std::endl;
	std::cout << "+-----------------------------+-----------------------------+" << std::endl;
}

void	Phonebook::display_phonebook(void) const{
	int i = 0;
	std::string	str;
	
	std::cout << "+-----------------------------+-----------------------------+-----------------------------+-----------------------------+" << std::endl;
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << "|   "; std::cout.width(26); std::cout << "Index";
	std::cout << "|   "; std::cout.width(26); std::cout << "Nombre";
	std::cout << "|   "; std::cout.width(26); std::cout << "Apellido";
	std::cout << "|   "; std::cout.width(26); std::cout << "Nickname" << "|" << std::endl;
	std::cout << "+-----------------------------+-----------------------------+-----------------------------+-----------------------------+" << std::endl;
	std::cout.setf(std::ios::right, std::ios::adjustfield);
	while (i < this->size)
	{
		std::cout << "|"; std::cout.width(29); std::cout << i + 1;
		str = this->contacts[i].get_firstname();
		if (str.length() > 26){
			str.resize(25); str.append(".");}
		std::cout << "|"; std::cout.width(29); std::cout << str;
		str = this->contacts[i].get_lastname();
		if (str.length() > 26){
			str.resize(25); str.append(".");}
		std::cout << "|"; std::cout.width(29); std::cout << str;
		str = this->contacts[i].get_nickname();
		if (str.length() > 26){
			str.resize(25); str.append(".");}
		std::cout << "|"; std::cout.width(29); std::cout << str << "|" << std::endl;
		i++;
	}
	std::cout << "+-----------------------------+-----------------------------+-----------------------------+-----------------------------+" << std::endl;
}

Phonebook& Phonebook::operator=(Phonebook& b){

	int i = 0;
	this->size = b.get_size();
	while(i < this->size)
	{
		this->contacts[i].set_firstname(b.contacts[i].get_firstname());
		this->contacts[i].set_lastname(b.contacts[i].get_lastname());
		this->contacts[i].set_nickname(b.contacts[i].get_nickname());
		this->contacts[i].set_phone(b.contacts[i].get_phone());
		this->contacts[i].set_secret(b.contacts[i].get_secret());
		i++;
	}
	this->index = b.get_index();
	return (*this);
}
