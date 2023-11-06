/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:53:23 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/10/31 11:28:37 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__
class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;

	public:
		Contact();						//constructor defecto
		Contact(Contact& c);			//constructor copia
		~Contact();						//destructor
		Contact &operator=(Contact& a); //operador asignación '='
		const std::string& 	get_firstname(void) const;
		const std::string& 	get_lastname(void) const;
		const std::string& 	get_nickname(void) const;
		const std::string& 	get_phone(void) const;
		const std::string& 	get_secret(void) const;
		void				set_firstname(std::string firstname);
		void				set_lastname(std::string lastname);
		void				set_nickname(std::string nickname);
		void				set_phone(std::string phone);
		void				set_secret(std::string secret);
};
#endif
