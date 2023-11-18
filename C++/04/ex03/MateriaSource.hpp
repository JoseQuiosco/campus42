/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:05:12 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 14:50:47 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

static const unsigned int MAX_KNOWN = 4;

class MateriaSource : public IMateriaSource
{
	private:
		AMateria		*materias[MAX_KNOWN];
		unsigned int	memorized;
		
	public:
						MateriaSource();
						MateriaSource(MateriaSource &ms);
						~MateriaSource();
		void			learnMateria(AMateria*);
		AMateria*		createMateria(std::string const & type);
		unsigned int	getMemorized(void) const;

		MateriaSource 	&operator=(const MateriaSource &ms);
};
