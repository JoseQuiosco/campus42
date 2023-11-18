/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:04:55 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 19:51:05 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	__CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

static const unsigned MAX_SLOTS = 4;

class Character : public ICharacter
{
	private:
		std::string		name;
		AMateria		*inventory[MAX_SLOTS];
		unsigned int	assigned;

	public:
							Character();
							Character(Character &c);
							Character(std::string name);
							~Character();
		
		void				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter &target);

		const std::string 	&getName(void) const;
		AMateria			*getMateria(unsigned int indx) const;
		unsigned int		getAssigned(void) const;

		void 				setName(std::string name);
		void				setAssigned(unsigned int newval);



		Character 			&operator=(const Character &c);
};

#endif
