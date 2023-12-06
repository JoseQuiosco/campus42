
#ifndef __WARLOCK_HPP__
#define __WARLOCK_HPP__

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class ATarget;

class Warlock
{
    private:
        std::string 					name;
        std::string 					title;
		std::map<std::string, ASpell *> memorized; 

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