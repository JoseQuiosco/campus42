/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:52:41 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/10/26 13:59:20 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		int		index;
		int		size;
	public:
		Phonebook();
		Phonebook(Phonebook& b);
		~Phonebook();
		Phonebook& operator=(Phonebook& b); //operador asignación '='
		int		get_size(void) const;
		int		get_index(void) const;
		void	add_contact(void);
		void	display_phonebook(void) const;
		void	display_contact(int pos) const;
};
