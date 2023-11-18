/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:49:16 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 00:02:32 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef	__AMATERIA_HPP__
#define __AMATERIA_HPP__

#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string			type;

	private:
							AMateria();
	public:
							AMateria(AMateria &m);
							AMateria(std::string const &type);
							~AMateria();
		std::string const	&getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter &target);

		AMateria			&operator=(const AMateria &m);
};

#endif
