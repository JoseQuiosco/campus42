/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:21:26 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/10/23 21:15:49 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	this->firstname = "\0";
	this->lastname = "\0";
	this->nickname = "\0";
	this->phone = "\0";
	this->secret = "\0";
	std::cout << "Constructor por defecto. Strings vaciós" << std::endl;
}

Contact::Contact(Contact& c)
{
	this->firstname = c.firstname;
	this->lastname = c.lastname;
	this->nickname = c.nickname;
	this->phone = c.phone;
	this->secret = c.secret;
	std::cout << "Constructor copia." << std::endl;
}

Contact::~Contact(){
	std::cout << "Destructor de contacto activado." << std::endl; 
}

Contact& Contact::operator=(Contact& a){
	this->firstname = a.get_firstname();
	this->lastname = a.get_lastname();
	this->nickname = a.get_nickname();
	this->phone = a.get_phone();
	this->secret = a.get_secret();
	return (*this);
}

const std::string& 	Contact::get_firstname() const{
	return (this->firstname);
}

const std::string& 	Contact::get_lastname() const{
	return (this->lastname);
}

const std::string& 	Contact::get_nickname(void) const{
	return (this->nickname);
}
const std::string& 	Contact::get_phone(void) const{
	return (this->phone);
}

const std::string& 	Contact::get_secret(void) const{
	return (this->secret);
}

void				Contact::set_firstname(std::string firstname){
	this->firstname = firstname;
}
void				Contact::set_lastname(std::string lastname){
	this->lastname = lastname;
}

void				Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void				Contact::set_phone(std::string phone){
	this->phone = phone;
}

void				Contact::set_secret(std::string secret)
{
	this->secret = secret;
}
