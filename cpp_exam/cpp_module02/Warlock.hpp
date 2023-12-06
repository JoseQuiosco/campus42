
#ifndef __WARLOCK_HPP__
#define __WARLOCK_HPP__

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class ASpell;
class ATarget;
class SpellBook;

class Warlock
{
    private:
        std::string 					name;
        std::string 					title;
		SpellBook						book;

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);

    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle(std::string const &title);
		
		void learnSpell(ASpell *spell);
        void forgetSpell(std::string spellname);
		void launchSpell(std::string spell, ATarget const &target);
		
		void introduce() const;
};

#endif
