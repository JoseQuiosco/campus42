/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:02:39 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 19:56:40 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	__ICHARACTER_HPP__
#define __ICHARACTER_HPP__

#include <iostream>
#include <string>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
