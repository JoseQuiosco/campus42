/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:49:16 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 20:12:21 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	__AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string			type;

	private:
							AMateria();
	public:
							AMateria(AMateria &m);
							AMateria(std::string const &type);
		virtual				~AMateria();
		std::string const	&getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter &target) = 0;

		AMateria			&operator=(const AMateria &m);
};

#endif
