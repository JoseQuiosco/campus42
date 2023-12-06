#ifndef __SPELL_BOOK__
#define __SPELL_BOOK__

#include "ASpell.hpp"
#include "Fireball.hpp"
#include "Fwoosh.hpp"
#include "Polymorph.hpp"
#include <iostream>
#include <string>
#include <map>

class ASpell;

class SpellBook
{
	private:

		std::map<std::string, ASpell *> book;

					SpellBook(SpellBook const &spellbook);
		SpellBook 	&operator=(SpellBook const &spellbook);
	
	public:
					SpellBook();
					~SpellBook();
		void 		learnSpell(ASpell* spell);
		void 		forgetSpell(std::string const &spellname);
        ASpell		*createSpell(std::string const &spellname);

};


#endif